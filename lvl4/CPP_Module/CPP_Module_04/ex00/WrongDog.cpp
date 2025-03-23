/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 01:32:36 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/23 01:38:48 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal()
{
	this->_type = "WrongDog";
	std::cout << GREEN << "WrongDog Empty Constructor called" << RESET << std::endl;
}

WrongDog::WrongDog(const WrongDog &other) : WrongAnimal()
{
	*this = other;
	std::cout << GREEN << "WrongDog Copy Constructor called" << RESET << std::endl;
}

WrongDog &WrongDog::operator=(const WrongDog &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << GREEN << "WrongDog Copy Assignment Constructor called" << RESET << std::endl;
	return (*this);
}

WrongDog::~WrongDog()
{
	std::cout << RED << "WrongDog Destructor called" << RESET << std::endl;
}

void	WrongDog::makeSound() const
{
	std::cout << CYAN << this->_type << ": Guau Guau! 🐶" << RESET << std::endl;
}