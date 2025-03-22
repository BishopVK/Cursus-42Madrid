/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:36:05 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/22 14:36:45 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->_name = "no_name";
	this->_hitPoints = 100;
	this->_energy = 50;
	this->_attack = 20;
	std::cout << GREEN << "ScavTrap " << this->_name << ": Empty constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energy = 50;
	this->_attack = 20;
	std::cout << GREEN << "ScavTrap " << this->_name << ": Default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	*this = other;
	std::cout << GREEN << "ScavTrap " << this->_name << ": Copy constructor called" << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
		{
			this->_name = other._name;
			this->_hitPoints = other._hitPoints;
			this->_energy = other._energy;
			this->_attack = other._attack;
		}
		std::cout << GREEN << "ScavTrap " << this->_name << ": Copy assignment constructor called" << RESET << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << INVERT << "ScavTrap " << this->_name << ": Destructor called" << RESET << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_energy > 0 && this->_hitPoints > 0)
	{
		std::cout << CYAN << "ScavTrap " << this->_name
		<< " cause " << this->_attack
		<< " damage points to " << target
		<< " whit a powerfull ScavAttack" << RESET << std::endl;
		this->_energy--;
	}
	else if (this->_hitPoints == 0)
	{
		std::cout << RED << "ScavTrap " << this->_name
		<< " it's dead and can't attack 💀" << RESET << std::endl;
	}
	else
	{
		std::cout << RED << "ScavTrap " << this->_name
		<< " have " << this->_energy
		<< " energy points! 🪫"
		<< " Can't attack " << target << RESET << std::endl;
	}
}

// REQUIRED
void	ScavTrap::guardGate()
{
	if (this->_hitPoints > 0)
		std::cout << YELLOW << "ScavTrap " << this->_name << " it's now in gate keeper mode! 🛡️" << RESET << std::endl;
	else
		std::cout << YELLOW << "ScavTrap " << this->_name << " it's dead and couldn't enter in gate keeper mode! 💀" << RESET << std::endl;

}