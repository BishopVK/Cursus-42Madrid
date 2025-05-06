/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:38:13 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/06 08:51:24 by danjimen         ###   ########.fr       */
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
	for (int i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
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
	
	int	year;
	int	month;
	int	day;
 
	// Check date
	if (line.empty())
		return -2;
	if (line[4] != '-' || line[7] != '-' || !isdigit_string(line.substr(0, 4))
		|| !isdigit_string(line.substr(5, 2)) || !isdigit_string(line.substr(8, 2)))
	{
		std::cerr << RED "Error: Wrong date format => " << line.substr(0, 10) << RESET << std::endl;
		return -1;
	}
	else if ((infile == DATA_CSV && line[10] != ',') || (infile != DATA_CSV && line.substr(10, 3) != " | "))
	{
		std::cerr << RED "Error: key | value separator" << RESET << std::endl;
		return -1;
	}

	// Check value
	int		value_start_pos;
	int		dot_counter = 0;
	bool	wrong_amount = false;
	if (infile == DATA_CSV)
		value_start_pos = 11;
	else
		value_start_pos = 13;

	int	i;
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
	return EXIT_SUCCESS;
}

static int	create_map(std::map<int, int> *data_map, const std::string &infile)
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

	return EXIT_SUCCESS;
}

int	exchange(const std::string &infile)
{
	// Create data_map
	std::map<int, int> data_map;
	if (create_map(&data_map, DATA_CSV) == EXIT_FAILURE)
		return EXIT_FAILURE;
	(void)infile;
	return EXIT_SUCCESS;
}