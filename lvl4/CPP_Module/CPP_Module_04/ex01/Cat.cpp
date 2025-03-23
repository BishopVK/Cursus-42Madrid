/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:33:14 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/23 01:38:19 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << GREEN << "Cat Empty Constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal()
{
	*this = other;
	std::cout << GREEN << "Cat Copy Constructor called" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << GREEN << "Cat Copy Assignment Constructor called" << RESET << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << RED << "Cat Destructor called" << RESET << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << CYAN << this->_type << ": Miaaaaaaaau! 😸" << RESET << std::endl;
}