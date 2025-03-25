/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 01:52:06 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/25 01:50:06 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria()
{
	this->_type = "ice";
	std::cout << GREEN << "Ice Empty Constructor called" << RESET << std::endl;
}

Ice::Ice(const std::string &type) : AMateria(type)
{
	this->_type = type;
	std::cout << GREEN << "Ice Default Constructor called" << RESET << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other._type)
{
	std::cout << GREEN << "Ice Copy Constructor called" << RESET << std::endl;
	*this = other;
}

Ice &Ice::operator=(const Ice &other)
{
	std::cout << GREEN << "Ice Copy Assignment Constructor called" << RESET << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

Ice::~Ice()
{
	std::cout << RED << "Ice Destructor called" << RESET << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << YELLOW << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}