/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:28:17 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/25 01:44:09 by danjimen         ###   ########.fr       */
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
		this->_name = other._name;
	return (*this);
}

Character::~Character()
{
	std::cout << RED << "Character Destructor called" << RESET << std::endl;

	// Delete Materias from inventory
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != nullptr)
			delete inventory[i];
	}

	// Delete Materias from floor list
	for (AMateria* materia : floor)
	{
		delete materia;
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
		std::cout << RED << "Empty inventory slot to unequip" << RESET << std::endl;
		return;
	}
	inventory[idx]->use(target);
}