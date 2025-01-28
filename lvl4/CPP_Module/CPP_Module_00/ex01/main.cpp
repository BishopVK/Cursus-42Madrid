/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:15:39 by danjimen          #+#    #+#             */
/*   Updated: 2025/01/23 12:58:07 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	CountWords(std::string str)
{
	int	wordCount = 0;

	if (str.empty())
	{
		std::cout << RED << "Error:" << RESET << " You have entered a void input" << std::endl;
		return (-1);
	}
	for (int i = 0; i < str.length(); i++)
	{
		if (std::isspace(str[i]))
			i++;
		else
		{
			for (i; i < str.length(); i++)
			{
				if (!std::isspace(str[i]))
					i++;
				else
				{
					for (i; i < str.length(); i++)
					{
						if (std::isspace(str[i]))
							i++;
						else
						{
							std::cout <<RED << "Error:" << RESET << " You have entered more than one word" << std::endl;
							return (-1);
						}
					}
				}
			}
		}
	}
	return (0);
}

std::string	TrimWords(std::string str)
{
	std::string	strTrimed;
	int			i = 0;

	for (i; i < str.length(); i++)
	{
		if (!std::isspace(str[i]))
			break;
	}
	// std::cout << "Salté " << i << " espacios" << std::endl; // DB
	for (i; i < str.length(); i++)
	{
		if (!std::isspace(str[i]))
			strTrimed.push_back(str[i]);
		else
			break;
	}
	std::cout << "strTrimed = " << strTrimed << std::endl;
	return (strTrimed);
}

std::string ToUpper(std::string str)
{
	for (int i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
	return (str);
}

int	main(void)
{
	Phonebook	contactList;
	std::string	input;

	std::cout << GREEN << "WELCOME TO YOUR PHONEBOOK!" << RESET << std::endl;
	std::cout << "\t- Use " << CYAN << "ADD" << RESET << " to save a new contact" << std::endl;
	std::cout << "\t- Use " << CYAN << "SEARCH" << RESET << " to display a specific contact" << std::endl;
	std::cout << "\t- Use " << CYAN << "EXIT" << RESET << " to close your PhoneBook" << std::endl;

	while (input != "EXIT" && !std::cin.eof()) // Added control por ctrl + D (EOF)
	{
		std::cout << std::endl << BOLD << "Insert a command (ADD, SEARCH, EXIT):" << RESET CYAN << std::endl;
		std::getline(std::cin, input);
		std::cout << RESET;
		std::string	inputTrimed = TrimWords(input);
		/* if (CountWords(inputTrimed) != 0)
			continue; */
		inputTrimed = ToUpper(inputTrimed);

		if (inputTrimed == "ADD")
		{
			std::cout << GREEN << "You have entered " << inputTrimed << " correctly" << RESET << std::endl;
			contactList.add();
		}
		else if (inputTrimed == "SEARCH")
			std::cout << GREEN << "You have entered " << inputTrimed << " correctly" << RESET << std::endl;
		else if (inputTrimed == "EXIT")
		{
			std::cout << GREEN << "You have entered " << inputTrimed << " correctly" << RESET << std::endl;
			return (0);
		}
		else
			std::cout << RED << "Error: " << RESET << inputTrimed << ": Incorrect command" << std::endl;
	}
	return (0);
}