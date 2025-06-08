/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 23:21:45 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/08 03:20:08 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const std::string &input) : _input(input)
{
	RPNCalculator();
}

RPN::RPN(const RPN &other) : _input(other._input)
{
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		this->_input = other._input;
	return *this;
}

RPN::~RPN()
{
}

std::string	RPN::getInput() const
{
	return this->_input;
}

void	RPN::setInput(const std::string &input)
{
	this->_input = input;
}

static bool	isdigitString(const std::string &str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

static bool	isoperatorString(const std::string &str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/')
			return false;
	}
	return true;
}

std::string intToString(int number)
{
	std::ostringstream oss;
	oss << number;
	return oss.str();
}

bool	isIntNumber(int a, int b, char op)
{
	long	la = static_cast<long>(a);
	long	lb = static_cast<long>(b);
	bool	error = false;

	if (op == '+')
	{
		if (la + lb >= INT_MAX)
			error = true;
	}
	else if (op == '-')
	{
		if (la - lb <= INT_MIN)
			error = true;
	}
	else if (op == '*')
	{
		if (la * lb >= INT_MAX || la * lb <= INT_MIN)
			error = true;
	}

	if (error == true)
		return false;

	return true;
}

void	RPN::RPNCalculator()
{
	std::stack<std::string>	tokens;
	std::stringstream		ss(this->_input);
	std::string 			item;
	int						first;
	int						second;

	while (std::getline(ss, item, ' '))
	{
		if (item.empty())
			continue;
		if (item.length() != 1 && (!isdigitString(item) || !isoperatorString(item)))
			throw ErrorException();
		if (isdigitString(item))
			tokens.push(item);
		if (isoperatorString(item) && tokens.size() < 2)
			throw ErrorException();
		else if (isoperatorString(item))
		{
			second = std::atoi(tokens.top().c_str());
			tokens.pop();
			first = std::atoi(tokens.top().c_str());
			tokens.pop();

			if (!isIntNumber(first, second, item[0]))
					throw ErrorException("Overflow result");
			if (item[0] == '+')
				tokens.push(intToString(first + second));
			else if (item[0] == '-')
				tokens.push(intToString(first - second));
			else if (item[0] == '*')
				tokens.push(intToString(first * second));
			else
			{
				if (second == 0)
					throw ErrorException("Division by zero");
				tokens.push(intToString(first / second));
			}
		}
	}
	if (tokens.size() != 1)
		throw ErrorException();

	while (!tokens.empty())
	{
		std::cout << GREEN "Result => " RESET << tokens.top() << std::endl;
		tokens.pop();
	}

	return ;
}

//Exceptions
const char* RPN::ErrorException::what() const throw()
{
	return (_message).c_str();
}