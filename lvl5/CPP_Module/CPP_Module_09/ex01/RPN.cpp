/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 23:21:45 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/10 23:15:00 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

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
	{
		std::cerr << RED "Error: Overflow result" RESET << std::endl;
		return false;
	}

	return true;
}

int	RPN(const std::string &input)
{
	std::stack<std::string>	tokens;
	std::stringstream		ss(input);
	std::string 			item;
	int						first;
	int						second;

	while (std::getline(ss, item, ' '))
	{
		if (item.empty())
			continue;
		if (item.length() != 1 && (!isdigitString(item) || !isoperatorString(item)))
		{
			std::cerr << RED "Error" RESET << std::endl;
			return (EXIT_FAILURE);
		}
		if (isdigitString(item))
		{
			tokens.push(item);
		}
		if (isoperatorString(item) && tokens.size() < 2)
		{
			std::cerr << RED "Error" RESET << std::endl;
			return (EXIT_FAILURE);
		}
		else if (isoperatorString(item))
		{
			second = std::atoi(tokens.top().c_str());
			tokens.pop();
			first = std::atoi(tokens.top().c_str());
			tokens.pop();

			if (!isIntNumber(first, second, item[0]))
					return EXIT_FAILURE;
			if (item[0] == '+')
				tokens.push(intToString(first + second));
			else if (item[0] == '-')
				tokens.push(intToString(first - second));
			else if (item[0] == '*')
				tokens.push(intToString(first * second));
			else
			{
				if (second == 0)
				{
					std::cerr << RED "Error: Division by zero" RESET << std::endl;
					return (EXIT_FAILURE);
				}
				tokens.push(intToString(first / second));
			}
		}
	}
	if (tokens.size() != 1)
	{
		std::cerr << RED "Error" RESET << std::endl;
			return (EXIT_FAILURE);
	}

	while (!tokens.empty())
	{
		std::cout << GREEN "Result => " RESET << tokens.top() << std::endl;
		tokens.pop();
	}

	return EXIT_SUCCESS;
}