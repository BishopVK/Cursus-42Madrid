/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:38:13 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/06 13:26:56 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& dbFile)
{
	loadDatabase(dbFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_database = other._database;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

const std::multimap<std::string, double> &BitcoinExchange::getDatabase() const
{
	return this->_database;
}

std::string	formatDouble(double value)
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

std::ostream	&operator<<(std::ostream &os, const BitcoinExchange &object)
{
	os << "date,exchange_rate" << std::endl;
	for (std::multimap<std::string, double>::const_iterator it = object.getDatabase().begin(); it != object.getDatabase().end(); ++it)
		os << it->first << "," << formatDouble(it->second) << std::endl;
	return os;
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file)
		throw FailOpenFileException(filename);

	std::string line;
	std::getline(file, line); // skip header
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date, valueStr;
		if (!std::getline(iss, date, ',') || !std::getline(iss, valueStr))
			continue;
		double value = std::atof(valueStr.c_str());
		this->_database.insert(std::make_pair(date, value));
	}
}

void	BitcoinExchange::processInputFile(const std::string &filename) const
{
	std::ifstream	input_file;
	input_file.open(filename.c_str());
	if (!input_file)
		throw FailOpenFileException(filename);

	// Check first line
	std::string	line;
	std::getline(input_file, line);
	if (!this->check_first_line(line))
		throw WrongHeaderFileException();

	// Check the rest of the document
	while(std::getline(input_file, line))
	{
		std::string		key;
		double			value;
		if (line.empty())
			continue ;
		check_line_format(line);
		print_output(data_map, &key, &value);
	}
}

bool	BitcoinExchange::check_first_line(const std::string &header_line) const
{
	std::string	infile_head = "date | value";
	
	if (header_line != infile_head)
	{
		std::cerr << RED "Error: " << "Infile must start with " + infile_head << RESET << std::endl;
		return false;
	}

	return true;
}

bool	check_date(const std::string &date)
{
	if (date.length() < 10)
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

bool	BitcoinExchange::check_line_format(std::string line)
{
	// mm.insert(std::make_pair("clave", 1));
	std::string delimiter = " | ";

	// Finding the position of the delimiter
	std::size_t pos = line.find(delimiter);
	if (pos == std::string::npos) // The delimiter was not found
	{
		this->_database.insert(std::make_pair(line, NAN));
	}
	else // The delimiter was found
	{
		std::string	key;
		int	value;
		std::string str_value;
		str_value = line.substr(pos + delimiter.length()); // Save value to string
		char	*endptr;

		if (!check_date(line.substr(0, pos)))
		{
			return false
		}
		if (*endptr != '\0')
		{
			*key = line;
			*value = NAN;
			return false
		}
		else if (!std::isnan(*value))
		{
			check_date(key, value, line);
		}
		else
		{
			*key = line.substr(0, pos);
			// Convert string to double
			*value = std::strtod(str_value.c_str(), &endptr);
		}

		if (!std::isnan(*value))
			check_date(key, value, line);
	}

	return true;
}

/* static bool	isdigit_string(const std::string &str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
} */

/* static void	check_date(std::string *key, double *value, std::string line)
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
} */

/* static int	check_line_format(std::string *key, double *value, std::string line)
{
	// mm.insert(std::make_pair("clave", 1));
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
} */

/* std::string	formatFloat(double value)
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
} */

/* static void	print_output(std::multimap<std::string, double> *data_map, std::string *key,
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
} */

/* static int	read_infile(std::multimap<std::string, double> *data_map, const std::string &infile)
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
} */

/* static void	save_csv_map(std::string *key, double *value, std::string line)
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
} */

/* int	create_csv_map(std::multimap<std::string, double> *data_map, const std::string &infile)
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
} */

/* int	BitcoinExchange::exchange(const std::string &infile)
{
	// Create data_map
	std::multimap<std::string, double> data_map;
	if (create_csv_map(&data_map, DATA_CSV) == EXIT_FAILURE)
		return EXIT_FAILURE;

	// Read infile
	if (read_infile(&data_map, infile) == EXIT_FAILURE)
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
} */

// Exceptions
const char* BitcoinExchange::FailOpenFileException::what() const throw()
{
	return ("Failed to open file: " + this->filename).c_str();
}

const char* BitcoinExchange::WrongHeaderFileException::what() const throw()
{
	return "Wrong input header line";
}
