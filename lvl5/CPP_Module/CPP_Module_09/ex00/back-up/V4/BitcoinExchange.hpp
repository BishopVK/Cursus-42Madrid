/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:38:11 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/05 23:58:44 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream> // std::ifstream, open()
#include <stdlib.h> // EXIT_FAILURE
#include <climits> // INT_MAX
#include <map>
#include <iomanip> // std::fixed, std::setprecision()
#include <cmath> // std::isnan(), NAN
#include <sstream> // std::ostringstream

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

#define DATA_CSV "./cpp_09/data.csv"

class BitcoinExchange
{
	private:
		std::map<std::string, float> _database;

		void loadDatabase(const std::string& filename);
		static bool isValidDate(const std::string& date);
		static bool isLeapYear(int year);
		static bool isValidValue(const std::string& valueStr);
		float getRateForDate(const std::string& date) const;

	public:
		// Canonical form
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		// Constructor con base de datos
		BitcoinExchange(const std::string& dbFile);

		// Método principal
		void processInputFile(const std::string& inputFile) const;
};

#endif