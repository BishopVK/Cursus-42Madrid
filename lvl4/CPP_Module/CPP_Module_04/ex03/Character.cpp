/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:28:17 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/29 01:03:05 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string &name) : _name(name)
{
	std::cout << GREEN << "Character Default Constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
		_slot_occupied[i] = false;
	}
	_floor_size = 1;
	floor = new AMateria*[_floor_size];
	floor[0] = NULL;
}

Character::Character(const Character &other)
{
	std::cout << GREEN << "Character Copy Constructor called" << RESET << std::endl;
	*this = other;
}

Character &Character::operator=(const Character &other)
{
	std::cout << GREEN << "Character Copy Assignment Constructor called" << RESET << std::endl;
	if (this != &other)
	{
		this->_name = other._name;

		//Delete old materias
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i] != NULL)
			{
				delete this->inventory[i];
				this->inventory[i] = NULL;
			}
		}

		// Copy inventory and _slot_occupied
		for (int i = 0; i < 4; i++)
		{
			if (other.inventory[i] != NULL)
			{
				if (other.inventory[i]->getType() == "ice")
					this->inventory[i] = new Ice();
				else if (other.inventory[i]->getType() == "cure")
					this->inventory[i] = new Cure();
				else
					this->inventory[i] = new Ice(other.inventory[i]->getType());
				this->_slot_occupied[i] = true;
			}
			else
			{
				this->inventory[i] = NULL;
				this->_slot_occupied[i] = false;
			}
		}

		//Delete old floor
		for (int i = 0; i < _floor_size; i++)
		{
			if (this->floor[i] != NULL)
			{
				delete this->floor[i];
				this->floor[i] = NULL;
			}
		}
		delete[] floor;

		// Copy floor list
		this->_floor_size = other._floor_size;
		this->floor = new AMateria*[this->_floor_size];
		for (int i = 0; i < this->_floor_size; i++)
		{
			this->floor[i] = NULL;
			if (other.floor[i]) // Not NULL
				this->floor[i] = other.floor[i]->clone();
		}
	}
	return (*this);
}

Character::~Character()
{
	std::cout << RED << "Character Destructor called" << RESET << std::endl;

	// Delete Materias from inventory
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
	}

	// Delete Materias from floor list
	for (int i = 0; i < this->_floor_size; i++)
	{
		if (this->floor[i])
		{
			delete this->floor[i];
			this->floor[i] = NULL;
		}
	}
	delete[] this->floor;
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	int	i;

	if (m == NULL)
		return ;
	for (i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			std::cout << "Equiped " << m->getType() << " in inventory slot " << i << std::endl;
			inventory[i] = m->clone();
			_slot_occupied[i] = true;
			break;
		}
	}
	if (i == 4)
		std::cout << "The inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << RED << "Invalid inventory index" << RESET << std::endl;
		return;
	}
	if (_slot_occupied[idx] == false)
	{
		std::cout << RED << "Empty inventory slot to unequip" << RESET << std::endl;
		return;
	}
	else
	{
		std::cout << CYAN << "Unequiped " << inventory[idx]->getType() << " from inventory" << RESET << std::endl;
		// Creating a new floor array with +1 size and whit the older material
		AMateria **new_floor = new AMateria*[_floor_size + 1]();
		for (int i = 0; i < this->_floor_size; i++)
			new_floor[i] = this->floor[i];
		new_floor[_floor_size] = inventory[idx];
		delete[] this->floor;
		this->floor = new_floor;
		this->_floor_size++;
		inventory[idx] = NULL;
		_slot_occupied[idx] = false;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << RED << "Invalid inventory index" << RESET << std::endl;
		return;
	}
	if (_slot_occupied[idx] == false)
	{
		std::cout << RED << "Empty inventory slot to use" << RESET << std::endl;
		return;
	}
	inventory[idx]->use(target);
}

void	Character::printStats()
{
	std::cout << YELLOW << std::endl << "-- NAME --" << RESET << std::endl;
	std::cout << this->getName() << std::endl;

	std::cout << YELLOW << std::endl << "-- INVENTORY --" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot_occupied[i])
			std::cout << "Slot " << i << " has: " << this->inventory[i]->getType() << std::endl;
		else
			std::cout << "Slot " << i << " is empty" << std::endl;
	}

	std::cout << YELLOW << std::endl << "-- FLOOR --" << RESET << std::endl;
	if (_floor_size == 0 || (_floor_size == 1 && !floor[0]))
		std::cout << "There are no objects on the floor" << std::endl;
	else
	{
		for (int i = 0; i < this->_floor_size; i++)
		{
			if (floor[i])
				std::cout << "Materia " << i << " in the floor: " << floor[i]->getType() << std::endl;
		}
	}
}

void	Character::setName(const std::string &name)
{
	this->_name = name;
}