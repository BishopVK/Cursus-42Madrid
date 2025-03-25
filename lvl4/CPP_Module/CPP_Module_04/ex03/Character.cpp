/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:28:17 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/25 16:22:56 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string &name) : _name(name)
{
	std::cout << GREEN << "Character Default Constructor called" << RESET << std::endl;
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
			if (this->inventory[i] != nullptr && this->inventory[i]->is_dynamic())
			{
				delete this->inventory[i];
				this->inventory[i] = nullptr;
			}
		}

		// Copy inventory and _slot_occupied
		for (int i = 0; i < 4; i++)
		{
			if (other.inventory[i] != nullptr)
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
				this->inventory[i] = nullptr;
				this->_slot_occupied[i] = false;
			}
		}

		// Copy floor list
		for (std::list<AMateria*>::const_iterator it = other.floor.begin(); it != other.floor.end(); ++it)
		{
			if (*it) // Not nullptr
			{
				if ((*it)->getType() == "ice")
					this->floor.push_back(new Ice());
				else if ((*it)->getType() == "cure")
					this->floor.push_back(new Cure());
				else
					this->floor.push_back(new Ice((*it)->getType()));
			}
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
		if (inventory[i] != nullptr && inventory[i]->is_dynamic())
			delete inventory[i];
	}

	// Delete Materias from floor list
	for (std::list<AMateria*>::iterator it = floor.begin(); it != floor.end(); ++it)
	{
		if (*it && (*it)->is_dynamic()) // It's not nullptr and it's created dynamicly
			delete *it;
	}
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	int i = 0;

	if (m == nullptr)
		return ;
	for (i; i < 4; i++)
	{
		if (inventory[i] == nullptr)
		{
			std::cout << "Equiped " << m->getType() << " in inventory slot " << i << std::endl;
			inventory[i] = m;
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
		floor.push_back(inventory[idx]); // Move to floor list
		inventory[idx] = nullptr;
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
	std::cout << std::endl << "-- NAME --" << std::endl;
	std::cout << this->getName() << std::endl;

	std::cout << std::endl << "-- INVENTORY --" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot_occupied[i])
			std::cout << "Slot " << i << " have: " << this->inventory[i]->getType() << std::endl;
		else
			std::cout << "Slot " << i << " it's Empty" << std::endl;
	}

	std::cout << std::endl << "-- FLOOR --" << std::endl;
	if (floor.empty())
		std::cout << "There are no objects on the floor" << std::endl;
	else
	{
		int i = 0;
		for (std::list<AMateria*>::const_iterator it = this->floor.begin(); it != this->floor.end(); ++it)
		{
			if (*it) // Not nullptr
				std::cout << "Materia " << i << " in the floor: " << (*it)->getType() << std::endl;
			i++;
		}
	}
}