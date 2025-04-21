/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:06:13 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/22 00:19:50 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <climits> // INT_MIN, INT_MAX
#include <cfloat> // FLT_MAX, FLT_MIN, DBL_MAX, DBL_MIN
#include <cmath> // std::isnan(),  std::isinf()
#include <sstream> // stringstream
#include <iomanip>  // std::fixed and std::setprecision
#include <cstdlib> // strtod, strtol

#define RED	"\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

enum type
{
	CHAR,
	INT,
	DOUBLE,
	FLOAT,
	ERROR
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

	public:
		static void	convert(const std::string &input);

		class InvalidInputException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

#endif