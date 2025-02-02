/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:01:06 by danjimen          #+#    #+#             */
/*   Updated: 2025/02/02 12:13:57 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	Zombie::_name = "no_name";
	std::cout << Zombie::_name << ": " << GREEN << "has been created." << RESET << std::endl;
}

Zombie::Zombie(std::string _name)
{
	Zombie::_name = _name;
	std::cout << Zombie::_name << ": " << GREEN << "has been created." << RESET << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << Zombie::_name << ": " << RED << "has been destroyed." << RESET << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << Zombie::_name << ": " << CYAN << "BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

void	Zombie::set_name(std::string name)
{
	_name = name;
}
