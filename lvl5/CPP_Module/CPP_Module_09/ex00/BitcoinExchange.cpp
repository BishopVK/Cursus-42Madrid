/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:38:13 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/09 10:54:46 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static int check_first_line(std::ifstream *data_file, std::string line, const std::string &infile)
{
	std::string	data_head = "date,exchange_rate";
	std::string	infile_head = "date | value";
	std::getline(*data_file, line);
	std::cout << "DEBUG:" << std::endl; // DB
	std::cout << "Infile: " << infile << std::endl; // DB
	std::cout << "Line: " << line << std::endl; // DB
	
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

/* double round_to_2(double num)
{
	return floor(num * 100.0f + 0.5f) / 100.0f;
} */

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
	if (error)
	{
		*key = line;
		*value = NAN;
		// std::cerr << RED "Error: Wrong date format => " << line.substr(0, 10) << RESET << std::endl;
		// std::cerr << RED "key = " << *key << std::endl << "value = " << *value << RESET << std::endl;
		return ;
	}
}

static int	check_line_format(std::string *key, double *value, std::string line)
{
	std::string delimiter = " | ";

	// Encontrar la posición del delimitador
	std::size_t pos = line.find(delimiter);
	if (pos == std::string::npos) // El delimitador no fue encontrado
	{
		std::cout << "Delimitador no encontrado." << std::endl; // DB
		*key = line;
		*value = NAN;
		std::cout << "Fecha: " << *key << std::endl; // DB
		std::cout << "Valor: " << *value << std::endl; // DB
	}
	else // El delimitador fue encontrado
	{
		*key = line.substr(0, pos);
		std::string str_value;
		str_value = line.substr(pos + delimiter.length()); // Save value to string

		// Convert string to double
		char	*endptr;
		if (*endptr == '\0')
			*value = std::strtod(str_value.c_str(), &endptr);
		else
		{
			*key = line;
			*value = NAN;
		}
		if (!std::isnan(*value))
			check_date(key, value, line);

		std::cout << "Fecha: " << *key << std::endl; // DB
		std::cout << "Valor: " << *value << std::endl; // DB
	}

	return EXIT_SUCCESS;
}

static int	create_infile_map(std::multimap<std::string, double> *data_map, const std::string &infile)
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
		data_map->insert(std::make_pair(key, value));
	}

	return EXIT_SUCCESS;
}

static void	save_csv_map(std::string *key, double *value, std::string line)
{
	std::string delimiter = ",";

	// Encontrar la posición del delimitador
	std::size_t pos = line.find(delimiter);
	if (pos == std::string::npos) // El delimitador no fue encontrado
	{
		std::cout << "Delimitador no encontrado." << std::endl; // DB
		*key = line;
		*value = NAN;
		/* std::cout << "Fecha: " << *key << std::endl; // DB
		std::cout << "Valor: " << *value << std::endl; // DB */
	}
	else // El delimitador fue encontrado
	{
		*key = line.substr(0, pos);
		char*	endptr;
		*value = std::strtod(line.substr(pos + delimiter.length()).c_str(), &endptr);
		check_date(key, value, line);

		/* std::cout << "Fecha: " << *key << std::endl; // DB
		std::cout << "Valor: " << std::fixed << std::setprecision(2) << *value << std::endl; // DB */
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

int	exchange(const std::string &infile)
{
	// Create data_map
	std::multimap<std::string, double> data_map;
	if (create_csv_map(&data_map, DATA_CSV) == EXIT_FAILURE)
		return EXIT_FAILURE;
	/* for (std::multimap<std::string, double>::iterator it = data_map.begin(); it != data_map.end(); ++it)
	{
		std::cout << it->first << " => " << std::fixed << std::setprecision(2) <<  it->second << std::endl;
	} */ // DB 
	// (void)infile;

	// Create infile_map
	std::multimap<std::string, double> infile_map;
	create_infile_map(&infile_map, infile);
	/* for (std::multimap<std::string, double>::iterator it = infile_map.begin(); it != infile_map.end(); ++it)
	{
		std::cout << it->first << " => " << std::fixed << std::setprecision(2) <<  it->second << std::endl;
	} */ // DB
	return EXIT_SUCCESS;
}