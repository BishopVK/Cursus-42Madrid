/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:38:11 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/08 01:32:04 by danjimen         ###   ########.fr       */
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
#include <stdexcept>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

#define DATA_CSV "./cpp_09/data.csv"

//int	exchange(const std::string &infile);

class BitcoinExchange{
	private:
		std::multimap<std::string, double> _database;

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string &csvFile);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		// Load values
		void	loadDatabase(const std::string& filename);

		// Queries
		const	std::multimap<std::string, double> &getDatabase() const;

		// Main Process
		void	processInputFile(const std::string &filename) const;
		void	print_output(std::string *key, double *value) const;

		class FailOpenFileException : public std::exception
		{
			private:
				std::string filename;
			public:
				FailOpenFileException(const std::string &file) : filename(file) {}
				virtual ~FailOpenFileException() throw() {}
				virtual const char* what() const throw();
		};

		class WrongHeaderFileException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const BitcoinExchange &object);

#endif