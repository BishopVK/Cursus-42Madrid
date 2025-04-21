/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:36:05 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/21 21:54:28 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	this->_name = "no_name";
	ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoints = 100;
	this->_energy = 50;
	this->_attack = 30;
	std::cout << GREEN << "DiamondTrap " << this->_name << ": Empty constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = 100;
	this->_energy = 50;
	this->_attack = 30;
	std::cout << GREEN << "DiamondTrap " << this->_name << ": Default constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	*this = other;
	std::cout << GREEN << "DiamondTrap " << this->_name << ": Copy constructor called" << RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
		{
			this->_name = other._name;
			this->_hitPoints = other._hitPoints;
			this->_energy = other._energy;
			this->_attack = other._attack;
		}
		std::cout << GREEN << "DiamondTrap " << this->_name << ": Copy assignment constructor called" << RESET << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << INVERT << "DiamondTrap " << this->_name << ": Destructor called" << RESET << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

// REQUIRED
void	DiamondTrap::whoAmI()
{
	if (this->_hitPoints > 0)
	{
		std::cout << YELLOW << "My DiamondTrap name it's: " << this->_name << RESET << std::endl;
		std::cout << YELLOW << "My ClapTrap name it's: " << ClapTrap::_name << RESET << std::endl;
	}
	else
		std::cout << YELLOW << "DiamondTrap " << this->_name << " can´t say who it is because it's dead 💀" << RESET << std::endl;
}