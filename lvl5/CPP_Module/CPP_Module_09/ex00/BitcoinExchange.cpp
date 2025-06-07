/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:38:13 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/08 01:37:21 by danjimen         ###   ########.fr       */
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

bool	check_first_line(const std::string &header_line)
{
	std::string	infile_head = "date | value";
	
	if (header_line != infile_head)
	{
		std::cerr << RED "Error: " << "Infile must start with " + infile_head << RESET << std::endl;
		return false;
	}

	return true;
}

bool	isdigit_string(const std::string &str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool	check_date(std::string *key, double *value, std::string line)
{
	if ((*key).empty() || (*key).length() < 10)
	{
		*key = line;
		*value = NAN;
		return false;
	}
	if ((*key)[4] != '-' || (*key)[7] != '-' || !isdigit_string((*key).substr(0, 4))
		|| !isdigit_string((*key).substr(5, 2)) || !isdigit_string((*key).substr(8, 2)))
	{
		*key = line;
		*value = NAN;
		return false;
	}
	if ((*key).length() > 10 && (*key)[10] != ' ')
	{
		*key = line;
		*value = NAN;
		return false;
	}

	int	year = atoi((*key).substr(0, 4).c_str());
	int	month = atoi((*key).substr(5, 2).c_str());
	int	day = atoi((*key).substr(8, 2).c_str());
	bool	leap_year = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? true : false;
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
		return false;
	}

	return true;
}

bool	check_line_format(std::string line, std::string *key, double *value)
{
	std::string delimiter = " | ";

	// Finding the position of the delimiter
	std::size_t pos = line.find(delimiter);
	if (pos == std::string::npos) // The delimiter was not found
	{
		*key = line;
		*value = NAN;
		return false;
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
			return false;
		}

		if (!std::isnan(*value))
			check_date(key, value, line);
	}

	return true;
}

void	BitcoinExchange::print_output(std::string *key, double *value) const
{
	// Find correct or previous date
	std::map<std::string, double>::const_iterator it = this->_database.lower_bound(*key);

	if (it != this->_database.begin() && (it == this->_database.end() || it->first > *key))
	{
		--it; // Get the nearest previous date
	}

	if (std::isnan(*value))
		std::cerr << "Error: bad input => " << *key << std::endl;
	else if (*value < 0)
		std::cerr << "Error: not a positive number => " << *value << std::endl;
	else if (*value > 1000)
		std::cerr << "Error: too large a number => " << formatDouble(*value) << std::endl;
	else
	{
		double	result = *value * it->second;
		std::cout << *key << " => "
		<< formatDouble(*value) << " = "
		<< formatDouble(result) << std::endl;
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
	if (!check_first_line(line))
		throw WrongHeaderFileException();

	// Check the rest of the document
	while(std::getline(input_file, line))
	{
		std::string		key;
		double			value;
		if (line.empty())
			continue ;
		check_line_format(line, &key, &value);
		print_output(&key, &value);
	}
}

// Exceptions
const char* BitcoinExchange::FailOpenFileException::what() const throw()
{
	return ("Failed to open file: " + this->filename).c_str();
}

const char* BitcoinExchange::WrongHeaderFileException::what() const throw()
{
	return "Wrong input header line";
}
