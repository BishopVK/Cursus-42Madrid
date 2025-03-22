/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:36:05 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/22 18:10:02 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->_name = "no_name";
	this->_hitPoints = 100;
	this->_energy = 100;
	this->_attack = 30;
	std::cout << GREEN << "FragTrap " << this->_name << ": Empty constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const std::string &name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energy = 100;
	this->_attack = 30;
	std::cout << GREEN << "FragTrap " << this->_name << ": Default constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
	*this = other;
	std::cout << GREEN << "FragTrap " << this->_name << ": Copy constructor called" << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
		{
			this->_name = other._name;
			this->_hitPoints = other._hitPoints;
			this->_energy = other._energy;
			this->_attack = other._attack;
		}
		std::cout << GREEN << "FragTrap " << this->_name << ": Copy assignment constructor called" << RESET << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << INVERT << "FragTrap " << this->_name << ": Destructor called" << RESET << std::endl;
}

// REQUIRED
void	FragTrap::highFivesGuys()
{
	if (this->_hitPoints > 0)
		std::cout << YELLOW << "FragTrap " << this->_name << " high-fives the other Traps because it's a cool 'guy' 🖐️" << RESET << std::endl;
	else
		std::cout << YELLOW << "FragTrap " << this->_name << " is dead and can never high-five again 💀" << RESET << std::endl;

}