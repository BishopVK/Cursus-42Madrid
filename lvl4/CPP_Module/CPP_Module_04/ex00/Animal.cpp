/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen,isainz-r,serferna <webserv@stu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:33:14 by danjimen          #+#    #+#             */
/*   Updated: 2025/07/28 09:15:18 by danjimen,is      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Generic Animal")
{
	std::cout << GREEN << "Animal Empty Constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal &other)
{
	*this = other;
	std::cout << GREEN << "Animal Copy Constructor called" << RESET << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << GREEN << "Animal Copy Assignment Constructor called" << RESET << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << RED << "Animal Destructor called" << RESET << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << CYAN << this->_type << ": default sound" << RESET << std::endl;
}

std::string		Animal::getType() const
{
	return (this->_type);
}