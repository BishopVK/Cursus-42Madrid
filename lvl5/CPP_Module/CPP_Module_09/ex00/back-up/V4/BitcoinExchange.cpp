/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:38:13 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/06 00:02:35 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_database = other._database;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& dbFile)
{
	loadDatabase(dbFile);
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file)
		throw std::runtime_error("Error: could not open database file.");

	std::string line;
	std::getline(file, line); // skip header
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date, valueStr;
		if (!std::getline(iss, date, ',') || !std::getline(iss, valueStr))
			continue;
		float value = std::atof(valueStr.c_str());
		_database[date] = value;
	}
}

bool BitcoinExchange::isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009 || month < 1 || month > 12 || day < 1)
		return false;

	int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeapYear(year) && month == 2)
		return day <= 29;
	return day <= daysInMonth[month - 1];
}

bool BitcoinExchange::isValidValue(const std::string& valueStr)
{
	char* end;
	double val = std::strtod(valueStr.c_str(), &end);
	return *end == '\0' && val >= 0.0 && val <= 1000.0;
}

float BitcoinExchange::getRateForDate(const std::string& date) const
{
	std::map<std::string, float>::const_iterator it = _database.lower_bound(date);
	if (it != _database.end() && it->first == date)
		return it->second;
	if (it == _database.begin())
		throw std::runtime_error("Error: no data available for date: " + date);
	--it;
	return it->second;
}

void BitcoinExchange::processInputFile(const std::string& inputFile) const
{
	std::ifstream file(inputFile.c_str());
	if (!file)
	{
		std::cerr << "Error: could not open input file.\n";
		return;
	}

	std::string line;
	std::getline(file, line); // skip header

	while (std::getline(file, line))
	{
		if (line.empty()) continue;

		std::istringstream iss(line);
		std::string date, valueStr;

		size_t delim = line.find('|');
		if (delim == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << "\n";
			continue;
		}

		date = line.substr(0, delim);
		valueStr = line.substr(delim + 1);

		// trim
		date.erase(0, date.find_first_not_of(" \t"));
		date.erase(date.find_last_not_of(" \t") + 1);
		valueStr.erase(0, valueStr.find_first_not_of(" \t"));
		valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

		if (!isValidDate(date))
		{
			std::cerr << "Error: invalid date => " << date << "\n";
			continue;
		}

		if (!isValidValue(valueStr))
		{
			std::cerr << "Error: invalid value => " << valueStr << "\n";
			continue;
		}

		float value = std::atof(valueStr.c_str());

		try
		{
			float rate = getRateForDate(date);
			std::cout << date << " => " << value << " = " << (value * rate) << "\n";
		} catch (std::exception& e)
		{
			std::cerr << e.what() << "\n";
		}
	}
}