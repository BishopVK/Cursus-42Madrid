/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:18:15 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/16 23:38:22 by danjimen         ###   ########.fr       */
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
	if (input[0] == '-')
		i = 1;
	for (i; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
			return false;
	}
	return true;
}

std::string	parse(const std::string &input)
{
	std::cout << GREEN << "Valor recibido: " << input << std::endl; // DB
	if (itsChar(input))
		return ("char");
	if (itsInt(input))
		return ("int");
	return ("OK"); // DB
}

void	ScalarConverter::convert(const std::string &input)
{
	std::string type;
	if (input.empty())
	{
		std::cout << RED << "Error: Empty string" << std::endl;
		exit (1);
	}
	std::cout << "RETURN = " << (type = parse(input)) << std::endl;
}