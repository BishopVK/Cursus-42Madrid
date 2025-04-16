/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:18:15 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/17 01:42:41 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << GREEN << "Empty constructor called" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	std::cout << GREEN << "Copy assignment constructor called" << RESET << std::endl;
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

bool	itsChar(const std::string &input)
{
	return (input.length() == 1 && !isdigit(input[0]));
}

bool	itsInt(const std::string &input)
{
	int	i = 0;

	if (input[0] == '+' || input[0] == '-')
		i = 1;
	for (i; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
			return false;
	}
	/* long	val = std::strtol(input.c_str(), NULL, 10);
	if (val < INT_MIN || val > INT_MAX)
		return false; */
	return true;
}

bool	itsDouble(const std::string &input)
{
	int	i = 0;
	int	counter = 0;

	if (input == "-inf" || input == "+inf" || input == "nan")
		return true;
	if (input[0] == '+' || input[0] == '-')
		i = 1;
	for (i; i < input.length(); i++)
	{
		if (!isdigit(input[i]) && input[i] != '.')
			return false;
		if (input[i] == '.')
			counter++;
		if (counter > 1)
			return false;
	}
	if (counter != 1)
			return false;

	/* double	val = std::strtod(input.c_str(), NULL);
	if (std::isnan(val) || std::isinf(val))
		return false;
	if (val > DBL_MAX || val < -DBL_MAX)
		return false; */

	return true;
}

bool	itsFloat(const std::string &input)
{
	int	i = 0;
	int	counter = 0;

	if (input == "-inff" || input == "+inff" || input == "nanf")
		return true;
	if (input[input.length() - 1] != 'f' || (input.length() == 2 && !isdigit(input[0])))
		return (false);
	if (input[0] == '+' ||input[0] == '-')
		i = 1;
	for (i; i < input.length() - 1; i++)
	{
		if (!isdigit(input[i]) && input[i] != '.')
			return false;
		if (input[i] == '.')
			counter++;
		if (counter > 1)
			return false;
	}

	/* double	val = std::strtof(input.c_str(), NULL);
	if (std::isnan(val) || std::isinf(val))
		return false;
	if (val > FLT_MAX || val < -FLT_MAX)
		return false; */

	return true;
}

std::string	parse(const std::string &input)
{
	std::cout << GREEN << "Valor recibido: " << input << std::endl; // DB
	if (itsChar(input))
		return ("char");
	if (itsInt(input))
		return ("int");
	if (itsDouble(input))
		return ("double");
	if (itsFloat(input))
		return ("float");
	return ("error");
}

bool	limits(const std::string &input, const std::string &type)
{
	if (type == "int")
	{
		long	val = std::strtol(input.c_str(), NULL, 10);
		if (val < INT_MIN || val > INT_MAX)
			return false;
	}
	else if (type == "double" || type == "float")
	{
		double	val = std::strtod(input.c_str(), NULL);
		if (std::isnan(val) || std::isinf(val))
			return false;
		if (type == "float")
			if (val > DBL_MAX || val < -DBL_MAX)
				return false;
		else
			if (val > FLT_MAX || val < -FLT_MAX)
				return false;
	}
	return true;
}


void	ScalarConverter::convert(const std::string &input)
{
	std::string type;
	if (input.empty())
	{
		std::cerr << RED << "Error: Empty string" << RESET << std::endl;
		return ;
	}
	type = parse(input);
	if (type == "error")
	{
		std::cerr << RED << "Error: The type conversion is impossible" << RESET << std::endl;
		return ;
	}
	if (!limits(input, type))
	{
		std::cerr << RED << "Error: Overflow detected" << RESET << std::endl;
		return ;
	}
	std::cout << "RETURN = " << type << std::endl; // DB
}