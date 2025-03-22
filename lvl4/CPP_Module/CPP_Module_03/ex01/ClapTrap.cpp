/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:47:19 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/22 01:33:38 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("no_name")
{
	std::cout << GREEN << "ClapTrap " << this->_name << " has been created" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name)
{
	std::cout << GREEN << "ClapTrap " << this->_name << " has been created" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << GREEN << "ClapTrap " << this->_name << " has been created from a copy" << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
		{
			this->_name = other._name;
			this->_hitPoints = other._hitPoints;
			this->_energy = other._energy;
			this->_attack = other._attack;
		}
		std::cout << GREEN << "ClapTrap " << this->_name << " has been assigned from a copy" << RESET << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << INVERT << "ClapTrap " << this->_name << " has been destroyed" << RESET << std::endl;
}

std::string	ClapTrap::getName() const
{
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints() const
{
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergy() const
{
	return (this->_energy);
}

unsigned int	ClapTrap::getAttack() const
{
	return (this->_attack);
}

void	ClapTrap::setName(const std::string &name)
{
	this->_name = name;
	std::cout << YELLOW << "ClapTrap name updated to " << this->_name << RESET << std::endl;
}

void	ClapTrap::setHitPoints(const unsigned int &amount)
{
	this->_hitPoints = amount;
	std::cout << YELLOW << "ClapTrap hit points updated to " << this->_hitPoints << RESET << std::endl;
}

void	ClapTrap::setEnergy(const unsigned int &amount)
{
	this->_energy = amount;
	std::cout << YELLOW << "ClapTrap energy updated to " << this->_energy << RESET << std::endl;
}

void	ClapTrap::setAttack(const unsigned int &amount)
{
	this->_attack = amount;
	std::cout << YELLOW << "ClapTrap attack updated to " << this->_attack << RESET << std::endl;
}

void	ClapTrap::printStats() const
{
	std::cout << MAGENTA << "ClapTrap " << this->getName() << " has " << RESET << std::endl
	<< "\t> "<< this->getHitPoints() << " hit points" << std::endl
	<< "\t> "<< this->getEnergy() << " energy points" << std::endl
	<< "\t> "<< this->getAttack() << " attack points" << std::endl;
}

// REQUIRED
void	ClapTrap::attack(const std::string &target)
{
	if (this->_energy > 0 && this->_hitPoints > 0)
	{
		std::cout << CYAN << "ClapTrap " << this->_name
		<< " attacks " << target
		<< ", causing " << this->_attack
		<< " points of damage!" << RESET << std::endl;
		this->_energy--;
	}
	else if (this->_hitPoints == 0)
	{
		std::cout << RED << "ClapTrap " << this->_name
		<< " can't attack because it is dead 💀" << RESET << std::endl;
	}
	else
	{
		std::cout << RED << "ClapTrap " << this->_name
		<< " can't attack " << target
		<< " because he has " << this->_energy
		<< " points of energy! 🪫" << RESET << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > 0)
	{
		std::cout << CYAN << "ClapTrap " << this->_name
		<< " has taken " << amount
		<< " points of damage." << RESET << std::endl;
		this->_hitPoints -= amount;
		if (this->_hitPoints <= 0)
		{
			std::cout << RED << "ClapTrap " << this->_name
			<< " has died 💀" << RESET << std::endl;
		}
	}
	else
	{
		std::cout << RED << "ClapTrap " << this->_name
		<< " cannot be attacked because it is dead 💀" << RESET << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints > 0 && this->_energy > 0)
	{
		std::cout << CYAN << "ClapTrap " << this->_name
		<< " has recovered " << amount
		<< " hit points and lost 1 energy point!" << RESET << std::endl;
		this->_hitPoints += amount;
		this->_energy--;
	}
	else if (this->_hitPoints == 0)
	{
		std::cout << RED << "ClapTrap " << this->_name
		<< " cannot be repaired because it is dead 💀" << RESET << std::endl;
	}
	else
	{
		std::cout << RED << "ClapTrap " << this->_name
		<< " cannot be repaired because it has " << this->_energy
		<< " energy points 🪫" << RESET << std::endl;
	}
}