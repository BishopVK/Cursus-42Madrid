/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:13:03 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/19 01:03:12 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	welcomeMessage()
{
	std::cout << "Welcome to Harl 2.0. Select an option:" << std::endl;
	std::cout << GREEN << "\tDEBUG ✅" << RESET << std::endl;
	std::cout << CYAN << "\tINFO ℹ️" << RESET << std::endl;
	std::cout << YELLOW << "\tWARNING ⚠️" << RESET << std::endl;
	std::cout << RED << "\tERROR 🆘" << RESET << std::endl;
}

int main(int argc, char const *argv[])
{
	std::string	selected_word;

	while (true || !std::cin.eof())
	{
		welcomeMessage();
		std::getline(std::cin, selected_word);
		if (std::cin.eof())
		{
			std::cout << RED << std::endl << "Input interrupted. Exiting..." << RESET << std::endl;
			return (1);
		}
		if (selected_word != "DEBUG" && selected_word != "INFO" && selected_word != "WARNING" && selected_word != "ERROR")
		{
			std::cerr << RED << "Invalid option selected." << RESET << std::endl << std::endl;
			continue ;
		}
		break ;
	}
	Harl harl;
	harl.complain(selected_word);
	return 0;
}
