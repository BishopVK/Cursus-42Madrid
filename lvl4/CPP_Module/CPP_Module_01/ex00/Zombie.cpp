/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:01:06 by danjimen          #+#    #+#             */
/*   Updated: 2025/01/30 18:53:56 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	Zombie::name = "no_name";
	std::cout << Zombie::name << ": " << GREEN << "has been created." << RESET << std::endl;
}

Zombie::Zombie(std::string _name)
{
	Zombie::name = _name;
	std::cout << Zombie::name << ": " << GREEN << "has been created." << RESET << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << Zombie::name << ": " << RED << "has been destroyed." << RESET << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << Zombie::name << ": " << CYAN << "BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
