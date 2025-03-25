/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 01:52:06 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/25 02:18:44 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria()
{
	this->_type = "cure";
	std::cout << GREEN << "Cure Empty Constructor called" << RESET << std::endl;
}

Cure::Cure(const std::string &type) : AMateria(type)
{
	this->_type = type;
	std::cout << GREEN << "Cure Default Constructor called" << RESET << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other._type)
{
	std::cout << GREEN << "Cure Copy Constructor called" << RESET << std::endl;
	*this = other;
}

Cure &Cure::operator=(const Cure &other)
{
	std::cout << GREEN << "Cure Copy Assignment Constructor called" << RESET << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

Cure::~Cure()
{
	std::cout << RED << "Cure Destructor called" << RESET << std::endl;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << YELLOW << "* heals " << target.getName() << "’s wounds *" << RESET << std::endl;
}

bool Cure::is_dynamic() const
{
	return true;
}