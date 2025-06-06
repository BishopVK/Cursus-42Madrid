/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:38:11 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/06 12:56:14 by danjimen         ###   ########.fr       */
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

		// Parse Input File
		bool	check_first_line(const std::string &header_line) const;
		bool	check_line_format(std::string line);

		//static int	exchange(const std::string &infile); // OLD

		class FailOpenFileException : public std::exception
		{
			private:
				std::string filename;
			public:
				FailOpenFileException(const std::string &file) : filename(file) {}
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