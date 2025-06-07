/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 23:21:45 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/10 00:06:13 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool	isdigit_string(const std::string &str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

std::stack<std::string> split(const std::string &input, char delimiter)
{
	std::stack<std::string>	tokens;
	std::stringstream		ss(input);
	std::string 			item;

	while (std::getline(ss, item, delimiter))
		tokens.push(item);
	
	return tokens;
}

int	check_input(std::stack<std::string> tokens)
{
	if (tokens.empty())
	{
		std::cerr << RED "Void argument its invalid" RESET << std::endl;
		return EXIT_FAILURE;
	}

	while (!tokens.empty())
	{
		if (tokens.top().length() != 1)
		{
			std::cerr << RED "Error" RESET << std::endl;
			return EXIT_FAILURE;
		}
		if (!(isdigit_string(tokens.top()) || tokens.top()[0] == '+'
			|| tokens.top()[0] == '-' || tokens.top()[0] == '*' || tokens.top()[0] == '/'))
		{
			std::cerr << RED "Error: Invalid argument token" RESET << std::endl;
			return EXIT_FAILURE;
		}
		tokens.pop();
	}
	std::cout << GREEN "All tokens are OK!" RESET << std::endl;
	return EXIT_SUCCESS;
}

int	RPN(const std::string &input)
{
	std::stack<std::string> tokens = split(input, ' ');
	if (check_input(tokens) == EXIT_FAILURE)
		return EXIT_FAILURE;
	int	i = 1;
	while (!tokens.empty())
	{
		std::cout << "Token " << i << " => " << tokens.top() << std::endl;
		tokens.pop();
	}
	return EXIT_SUCCESS;
}