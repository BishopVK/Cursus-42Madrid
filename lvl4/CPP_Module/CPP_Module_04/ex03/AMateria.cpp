/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 01:30:39 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/29 01:03:25 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << GREEN << "AMateria Empty Constructor called" << RESET << std::endl;
}

AMateria::AMateria(const std::string &type) : _type(type)
{
	std::cout << GREEN << "AMateria Default Constructor called" << RESET << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	std::cout << GREEN << "AMateria Copy Constructor called" << RESET << std::endl;
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	std::cout << GREEN << "AMateria Copy Assignment Constructor called" << RESET << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << RED << "AMateria Destructor called" << RESET << std::endl;
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << YELLOW << "Attack " << target.getName() << " with matter" << RESET << std::endl;
}