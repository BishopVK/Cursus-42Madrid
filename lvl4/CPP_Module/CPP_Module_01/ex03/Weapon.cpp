/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:46:05 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/16 22:51:43 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/* Weapon::Weapon(std::string type)
{
	this->_type = type;
	std::cout << GREEN << "Weapon " << _type << " was created." << std::endl;
} */

Weapon::Weapon(const std::string &type) : _type(type) // Inicialización directa con una "Lista de inicialización". Las referencias deben inicializarse al ser creadas
{
	std::cout << GREEN << "Weapon '" << _type << "' was created." << std::endl;
}

Weapon::~Weapon()
{
	std::cout << RED << "Weapon '" << _type << "' was destroyed." << std::endl;
}

const std::string&	Weapon::getType(void) const
{
	return this->_type;
}

void	Weapon::setType(const std::string &type)
{
	std::cout << CYAN << this->_type  << " was replaced by: ";
	this->_type = type;
	std::cout << this->_type << RESET << std::endl;
	//std::cout << CYAN << "Weapon was replaced by: " << _type << RESET << std::endl;
}