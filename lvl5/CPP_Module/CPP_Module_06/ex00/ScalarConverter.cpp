/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:18:15 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/22 00:15:31 by danjimen         ###   ########.fr       */
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

const char *ScalarConverter::InvalidInputException::what() const throw()
{
	return "Invalid input";
}

bool	itsChar(const std::string &input)
{
	return (input.length() == 1 && !isdigit(input[0]));
}

bool	itsInt(const std::string &input)
{
	size_t	i = 0;

	if (input[0] == '+' || input[0] == '-')
		i = 1;
	for (size_t j = i; j < input.length(); j++)
	{
		if (!isdigit(input[j]))
			return false;
	}
	return true;
}

bool	itsDouble(const std::string &input)
{
	size_t	i = 0;
	int		counter = 0;

	if (input == "-inf" || input == "+inf" || input == "nan")
		return true;
	if (input[0] == '+' || input[0] == '-')
		i = 1;
	for (size_t j = i; j < input.length(); j++)
	{
		if (!isdigit(input[j]) && input[j] != '.')
			return false;
		if (input[j] == '.')
			counter++;
		if (counter > 1)
			return false;
	}
	if (counter != 1)
			return false;
	return true;
}

bool	itsFloat(const std::string &input)
{
	size_t	i = 0;
	int		counter = 0;

	if (input == "-inff" || input == "+inff" || input == "nanf")
		return true;
	if (input[input.length() - 1] != 'f' || (input.length() == 2 && !isdigit(input[0])))
		return (false);
	if (input[0] == '+' ||input[0] == '-')
		i = 1;
	for (size_t j = i; j < input.length() - 1; j++)
	{
		if (!isdigit(input[j]) && input[j] != '.')
			return false;
		if (input[j] == '.')
			counter++;
		if (counter > 1)
			return false;
	}
	return true;
}

type	parse(const std::string &input)
{
	if (itsChar(input))
		return (CHAR);
	if (itsInt(input))
		return (INT);
	if (itsDouble(input))
		return (DOUBLE);
	if (itsFloat(input))
		return (FLOAT);
	return (ERROR);
}

bool	limits(const std::string &input, type _type)
{
	if (_type == INT)
	{
		long	val = ::strtol(input.c_str(), NULL, 10);
		if (val < INT_MIN || val > INT_MAX)
			return false;
	}
	else if (_type == DOUBLE || _type == FLOAT)
	{
		double	val = ::strtod(input.c_str(), NULL);
		if (std::isnan(val) || std::isinf(val))
			return false;
		if (_type == FLOAT)
		{
			if (val > FLT_MAX || val < -FLT_MAX)
				return false;
		}
		else
		{
			if (val > DBL_MAX || val < -DBL_MAX)
				return false;
		}
	}
	return true;
}

void	printChar(const std::string &input)
{
	char	c = input[0];

	if (!isprint(c))
		throw ScalarConverter::InvalidInputException();
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	printInt(const std::string &input)
{
	int	nbr;
	std::stringstream ss(input);

	ss >> nbr;

	if (nbr >= ' ' && nbr <= '~' && std::isprint(static_cast<unsigned char>(nbr)))
		std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << nbr << std::endl;
	std::cout << "float: " << nbr << ".0f" << std::endl;
	std::cout << "double: " << nbr << ".0" << std::endl;
}

bool	isPseudoLiteral(const std::string &input, type _type)
{
	std::string	specials[6] = {"nan", "-inf", "+inf", "nanf", "-inff", "+inff"};

	if (_type == DOUBLE)
	{
		for (int i = 0; i < 3; i++)
		{
			if (input == specials[i])
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: " << input << "f" << std::endl;
				std::cout << "double: " << input << std::endl;
				return true;
			}
		}
	}
	else if (_type == FLOAT)
	{
		for (int i = 3; i < 6; i++)
		{
			if (input == specials[i])
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: " << input << std::endl;
				std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
				return true;
			}
		}
	}
	return false;
}

void	printDouble(const std::string &input, type _type)
{
	double	nbr;
	std::stringstream ss(input);

	ss >> nbr;

	if (!isPseudoLiteral(input, _type))
	{
		if (nbr >= ' ' && nbr <= '~' && std::isprint(static_cast<unsigned char>(nbr)))
			std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(nbr) << std::endl;
		std::cout << "float: " << nbr << "f" << std::endl;
		std::cout << "double: " << nbr << std::endl;
	}
}

void	printFloat(const std::string &input, type _type)
{
	float	nbr;
	std::stringstream ss(input);

	ss >> nbr;

	if (!isPseudoLiteral(input, _type))
	{
		if (nbr >= ' ' && nbr <= '~' && std::isprint(static_cast<unsigned char>(nbr)))
			std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(nbr) << std::endl;
		std::cout << "float: " << nbr << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(nbr) << std::endl;
	}
}

void	converter(const std::string &input, type _type)
{
	std::string	specials[6] = {"nan", "-inf", "+inf", "nanf", "-inff", "+inff"};
	for (int i = 0; i < 6; i++)
	{
		if (input == specials[i])
		{
			if (i < 3)
			{
				printDouble(input, _type);
				return ;
			}
			else
			{
				printFloat(input, _type);
				return ;
			}
		}
	}
	switch (_type)
	{
		case CHAR:
			printChar(input);
			break;
		case INT:
			printInt(input);
			break;
		case DOUBLE:
			printDouble(input, _type);
			break;
		case FLOAT:
			printFloat(input, _type);
			break;
		default:
			throw ScalarConverter::InvalidInputException();
			break;
	}
}

void	ScalarConverter::convert(const std::string &input)
{
	type _type;
	std::string	specials[6] = {"nan", "-inf", "+inf", "nanf", "-inff", "+inff"};

	if (input.empty())
		throw ScalarConverter::InvalidInputException();
	_type = parse(input);
	for (int i = 0; i < 6; i++)
		if (input == specials[i])
		{
			converter(input, _type);
			return;
		}
	if (!limits(input, _type))
	{
		std::cerr << RED << "Error: Overflow detected" << RESET << std::endl;
		return ;
	}
	converter(input, _type);
}