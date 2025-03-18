/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:13:03 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/18 23:55:35 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.h"

bool	IsNumber(const std::string& str)
{
	for (char c : str)
	{
		if (!std::isdigit(c))
			return false;
	}

	return (!str.empty());
}

int main(int argc, char const *argv[])
{
	std::cout << "Welcome to Harl 2.0. Enter a numer from 1 to 4:" << std::endl;
	while (true || !std::cin.eof())
	{
		std::cout << GREEN << "\t1. DEBUG ✅" << RESET << std::endl;
		std::cout << CYAN << "\t2. INFO ℹ️" << RESET << std::endl;
		std::cout << YELLOW << "\t3. WARNING ⚠️" << RESET << std::endl;
		std::cout << RED << "\t4. ERROR 🆘" << RESET << std::endl;
		std::string	buffer;
		std::getline(std::cin, buffer);
		if (std::cin.eof())
		{
			std::cout << RED << std::endl << "Input interrupted. Exiting..." << RESET << std::endl;
			return (1);
		}
		if (IsNumber(buffer))
		{
			try
			{
				long long temp = std::stoll(buffer);
				if (temp < 1 || temp > 4)
				{
					std::cerr << RED << INVALID_NUMBER << RESET << std::endl;
					continue;
				}
				break;
			}
			catch(const std::exception& e)
			{
				std::cerr << RED << INVALID_NUMBER << RESET << std::endl;
			}
		}
		else
		{
			std::cerr << RED << INVALID_NUMBER << RESET << std::endl;
			continue;
		}
	}
	std::cout << GREEN << "Correct number!!" << RESET << std::endl;
	return 0;
}
