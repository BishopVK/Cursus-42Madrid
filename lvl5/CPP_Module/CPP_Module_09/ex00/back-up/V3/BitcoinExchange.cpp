/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:38:13 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/06 00:33:13 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static int check_first_line(std::ifstream *data_file, std::string line, const std::string &infile)
{
	std::string	data_head = "date,exchange_rate";
	std::string	infile_head = "date | value";
	std::getline(*data_file, line);
	
	if (infile == DATA_CSV && line != data_head)
	{
		std::cerr << RED "Error: " << infile << " must start with " << data_head << RESET << std::endl;
		return EXIT_FAILURE;
	}
	else if (infile != DATA_CSV && line != infile_head)
	{
		std::cerr << RED "Error: " << infile << " must start with " << infile_head << RESET << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

static bool	isdigit_string(const std::string &str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

static void	check_date(std::string *key, double *value, std::string line)
{
	if ((*key).empty() || (*key).length() < 10)
	{
		*key = line;
		*value = NAN;
		return ;
	}
	if ((*key)[4] != '-' || (*key)[7] != '-' || !isdigit_string((*key).substr(0, 4))
		|| !isdigit_string((*key).substr(5, 2)) || !isdigit_string((*key).substr(8, 2)))
	{
		*key = line;
		*value = NAN;
		return ;
	}
	if ((*key).length() > 10 && (*key)[10] != ' ')
	{
		*key = line;
		*value = NAN;
		return ;
	}

	int	year = atoi((*key).substr(0, 4).c_str());
	int	month = atoi((*key).substr(5, 2).c_str());
	int	day = atoi((*key).substr(8, 2).c_str());
	bool	leap_year = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? true : false; // Bisiesto
	bool	error = false;
	if (year < 0 || year > 2022 || month < 1 || month > 12 || day < 1 || day > 31)
		error = true;
	if ((month == 2 && leap_year == true && day > 29) || (month == 2 && leap_year == false && day > 28))
		error = true;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		error = true;
	if (((year < 2009 || (year == 2009 && month <= 1 && day <= 2)) && !std::isnan(*value)))
		*key = "2009-01-02";
	if (error)
	{
		*key = line;
		*value = NAN;
		return ;
	}
}

static int	check_line_format(std::string *key, double *value, std::string line)
{
	std::string delimiter = " | ";

	// Finding the position of the delimiter
	std::size_t pos = line.find(delimiter);
	if (pos == std::string::npos) // The delimiter was not found
	{
		*key = line;
		*value = NAN;
	}
	else // The delimiter was found
	{
		*key = line.substr(0, pos);
		std::string str_value;
		str_value = line.substr(pos + delimiter.length()); // Save value to string

		// Convert string to double
		char	*endptr;
		*value = std::strtod(str_value.c_str(), &endptr);
		if (*endptr != '\0')
		{
			*key = line;
			*value = NAN;
		}

		if (!std::isnan(*value))
			check_date(key, value, line);
	}

	return EXIT_SUCCESS;
}

std::string	formatFloat(double value)
{
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(2) << value;
	std::string str = oss.str();

	// Remove trailing zeros
	size_t dot = str.find('.');
	if (dot != std::string::npos) {
		size_t end = str.size() - 1;
		while (end > dot && str[end] == '0') {
			--end;
		}
		if (str[end] == '.') // If the point remains alone, we eliminate it.
			--end;
		str = str.substr(0, end + 1);
	}
	return str;
}

static void	print_output(std::multimap<std::string, double> *data_map, std::string *key,
	double *value)
{
	// Find correct or previous date
	std::map<std::string, double>::iterator it = data_map->lower_bound(*key);

	if (it != data_map->begin() && (it == data_map->end() || it->first > *key))
	{
		--it; // Get the nearest previous date
	}

	if (std::isnan(*value))
		std::cerr << "Error: bad input => " << *key << std::endl;
	else if (*value < 0)
		std::cerr << "Error: not a positive number => " << *value << std::endl;
	else if (*value > 1000)
		std::cerr << "Error: too large a number => " << formatFloat(*value) << std::endl;
	else
	{
		double	result = *value * it->second;
		std::cout << *key << " => "
		<< formatFloat(*value) << " = "
		<< formatFloat(result) << std::endl;
	}
}

static int	read_infile(std::multimap<std::string, double> *data_map, const std::string &infile)
{
	std::ifstream	data_file;
	data_file.open(infile.c_str());
	if (!data_file)
	{
		std::cerr << RED "Error: could not open " << infile << " file." RESET << std::endl;
		return EXIT_FAILURE;
	}

	// Check first line
	std::string	line;
	if (check_first_line(&data_file, line, infile) == EXIT_FAILURE)
		return EXIT_FAILURE;

	// Check the rest of the document
	while(std::getline(data_file, line))
	{
		std::string		key;
		double			value;
		if (line.empty())
			continue ;
		check_line_format(&key, &value, line);
		print_output(data_map, &key, &value);
	}

	return EXIT_SUCCESS;
}

static void	save_csv_map(std::string *key, double *value, std::string line)
{
	std::string delimiter = ",";

	// Finding the position of the delimiter
	std::size_t pos = line.find(delimiter);
	if (pos == std::string::npos) // The delimiter was not found
	{
		*key = line;
		*value = NAN;
	}
	else // The delimiter was found
	{
		*key = line.substr(0, pos);
		char*	endptr;
		*value = std::strtod(line.substr(pos + delimiter.length()).c_str(), &endptr);
		check_date(key, value, line);
	}
}

int	create_csv_map(std::multimap<std::string, double> *data_map, const std::string &infile)
{
	std::ifstream	data_file;
	data_file.open(infile.c_str());
	if (!data_file)
	{
		std::cerr << RED "Error: could not open " << infile << " file." RESET << std::endl;
		return EXIT_FAILURE;
	}

	// Check first line
	std::string	line;
	if (check_first_line(&data_file, line, infile) == EXIT_FAILURE)
		return EXIT_FAILURE;

	// Check the rest of the document
	while(std::getline(data_file, line))
	{
		std::string		key;
		double			value;
		if (line.empty())
			continue ;
		save_csv_map(&key, &value, line);
		data_map->insert(std::make_pair(key, value));
	}

	return EXIT_SUCCESS;
}

int	BitcoinExchange::exchange(const std::string &infile)
{
	// Create data_map
	std::multimap<std::string, double> data_map;
	if (create_csv_map(&data_map, DATA_CSV) == EXIT_FAILURE)
		return EXIT_FAILURE;

	// Read infile
	if (read_infile(&data_map, infile) == EXIT_FAILURE)
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}