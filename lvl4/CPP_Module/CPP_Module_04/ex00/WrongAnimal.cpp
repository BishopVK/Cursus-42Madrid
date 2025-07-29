/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen,isainz-r,serferna <webserv@stu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:33:14 by danjimen          #+#    #+#             */
/*   Updated: 2025/07/28 09:16:27 by danjimen,is      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Generic Wrong Animal")
{
	std::cout << GREEN << "WrongAnimal Empty Constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
	std::cout << GREEN << "WrongAnimal Copy Constructor called" << RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << GREEN << "WrongAnimal Copy Assignment Constructor called" << RESET << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal Destructor called" << RESET << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << CYAN << this->_type << ": default sound" << RESET << std::endl;
}

std::string		WrongAnimal::getType() const
{
	return (this->_type);
}