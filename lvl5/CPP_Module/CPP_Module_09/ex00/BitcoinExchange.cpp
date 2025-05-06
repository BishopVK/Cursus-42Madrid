/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:38:13 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/06 13:13:44 by danjimen         ###   ########.fr       */
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
		std::cerr << RED "Error: " << infile << " must start whit " << data_head << RESET << std::endl;
		return EXIT_FAILURE;
	}
	else if (infile != DATA_CSV && line != infile_head)
	{
		std::cerr << RED "Error: " << infile << " must start whit " << infile_head << RESET << std::endl;
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

static int	check_date(std::string line)
{
	if (line.empty())
		return -2;
	if (line[4] != '-' || line[7] != '-' || !isdigit_string(line.substr(0, 4))
		|| !isdigit_string(line.substr(5, 2)) || !isdigit_string(line.substr(8, 2)))
	{
		std::cerr << RED "Error: Wrong date format => " << line.substr(0, 10) << RESET << std::endl;
		return -1;
	}
	
	long	year = atol(line.substr(0, 4).c_str());
	long	month = atol(line.substr(5, 2).c_str());
	long	day = atol(line.substr(8, 2).c_str());
	bool	leap_year = (year % 4 == 0) ? true : false; // Bisiesto
	bool	error = false;
	if (year < 0 || year > 2022 || month < 0 || month > 12 || day < 0 || day > 31)
		error = true;
	if ((month == 2 && leap_year == true > 29) || (month == 2 && leap_year == false > 28))
		error = true;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		error = true;
	if (error == true)
	{
		std::cerr << RED "Error: Wrong date format => " << line.substr(0, 10) << RESET << std::endl;
		return -1;
	}
	std::string date = line.substr(0, 4) + line.substr(5, 2) + line.substr(8, 2);
	int			date_int = atoi(date.c_str());
	std::cout << "Fecha = " << date_int << std::endl; // DB
	return date_int;
}

static int	check_delimiter(std::string line, const std::string &infile)
{
	if ((infile == DATA_CSV && line[10] != ',') || (infile != DATA_CSV && line.substr(10, 3) != " | "))
	{
		std::cerr << RED "Error: key | value separator" << RESET << std::endl;
		return -1;
	}
	return 0;
}

static int	check_value(std::string line, const std::string &infile)
{
	int		dot_counter = 0;
	bool	wrong_amount = false;
	int		value_start_pos = (infile == DATA_CSV) ? 11 : 13;

	size_t	i;
	for (i = value_start_pos; i < line.length(); ++i)
	{
		if (infile != DATA_CSV && line[value_start_pos] == '-')
			continue;
		if (!std::isdigit(line[i]) && line[i] != '.')
			wrong_amount = true;
		else if (line[i] == '.')
			dot_counter++;
		if (wrong_amount == true || dot_counter > 1)
		{
			std::cerr << RED "Error: Wrong price format => " << line.substr(value_start_pos, line.length() - value_start_pos) << RESET << std::endl;
			return -1;
		}
	}
	float	value = atof(line.substr(value_start_pos, line.length() - value_start_pos).c_str());
	if (value < 0)
	{
		std::cerr << RED "Error: not a positive number." RESET << std::endl;
		return -1;
	}
	if ((infile == DATA_CSV && value > static_cast<float>(INT_MAX)) || (infile != DATA_CSV && value > 1000))
	{
		std::cerr << RED "Error: too large a number." RESET << std::endl;
		return -1;
	}
	
	return 0;
}

static int	check_line_format(int *key, int *value, std::string line, const std::string &infile)
{
	if (infile == DATA_CSV && line.length() < 12)
	{
		std::cerr << RED "Error: Wrong line format" << RESET << std::endl;
		return -1;
	}
	else if (infile != DATA_CSV && line.length() < 14)
	{
		std::cerr << RED "Error: Wrong line format" << RESET << std::endl;
		return -1;
	}
 
	// Check date
	int date_ret;
	date_ret = check_date(line);
	if (date_ret == -1)
		return -1;
	else if (date_ret == -2)
		return -2;
	else
		*key = date_ret;

	// Check delimiter
	if (check_delimiter(line, infile) == -1)
		return -1;

	// Check value
	float value_ret;
	value_ret = check_value(line, infile);
	if (value_ret == -1)
		return -1;
	else
		*value = value_ret;
	
	return EXIT_SUCCESS;
}

static int	create_map(std::map<int, float> *data_map, const std::string &infile)
{
	std::ifstream	data_file;
	data_file.open(infile.c_str());
	if (!data_file)
	{
		std::cerr << RED "Error: could not open " << infile << " file." RESET << std::endl;
		return EXIT_FAILURE;
	}

	std::string	line;
	// Check first line
	if (check_first_line(&data_file, line, infile) == EXIT_FAILURE)
		return EXIT_FAILURE;

	// Check the rest of the document
	while(std::getline(data_file, line))
	{
		int	key;
		int	value;
		int line_res = check_line_format(&key, &value, line, infile);
		if (line_res == -1)
			return EXIT_FAILURE;
		if (line_res == -2)
			continue;
		
	}
	(void)data_map;

	return EXIT_SUCCESS;
}

int	exchange(const std::string &infile)
{
	// Create data_map
	std::map<int, float> data_map;
	if (create_map(&data_map, DATA_CSV) == EXIT_FAILURE)
		return EXIT_FAILURE;
	(void)infile;
	return EXIT_SUCCESS;
}