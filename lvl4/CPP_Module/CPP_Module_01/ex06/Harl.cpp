/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:26:00 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/21 19:48:21 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	option[0] = &Harl::debug;
	option[1] = &Harl::info;
	option[2] = &Harl::warning;
	option[3] = &Harl::error;
	option[4] = &Harl::wrong;
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << GREEN << std::endl << "DEBUG ✅" << std::endl << RESET << ITALIC << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << RESET << std::endl;
}

void	Harl::info(void)
{
	std::cout << CYAN << std::endl << "INFO ℹ️" << std::endl << RESET << ITALIC << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << RESET << std::endl;
}

void	Harl::warning(void)
{
	std::cout << YELLOW << std::endl << "WARNING ⚠️" << std::endl << RESET << ITALIC << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << RESET << std::endl;
}

void	Harl::error(void)
{
	std::cout << RED << std::endl << "ERROR 🆘" << std::endl << RESET << ITALIC << "This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
}

void	Harl::wrong(void)
{
	std::cout << ITALIC << "[ Probably  complaining  about  insignificant  problems  ]" << RESET << std::endl;
}

void	Harl::complain(const std::string &level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i;
	int			size = sizeof(levels) / sizeof(levels[0]); // Total number of bytes in the array divided by the number of bytes in an array element = number of elements

	for (i = 0; i < size; i++)
	{
		if (levels[i] == level)
		{
			(this->*option[i])();
			return ;
		}
	}

	(this->*option[i])(); // Wrong case
}

void harl_filter(const std::string &level)
{
	Harl harl;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i;

	for (i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			break ;
	}
	switch (i)
	{
		case 0:
			harl.complain(levels[0]);
			// fall through
		case 1:
			harl.complain(levels[1]);
			// fall through
		case 2:
			harl.complain(levels[2]);
			// fall through
		case 3:
			harl.complain(levels[3]);
			break ;
		default:
			harl.complain(levels[4]);
			break ;
	}
}