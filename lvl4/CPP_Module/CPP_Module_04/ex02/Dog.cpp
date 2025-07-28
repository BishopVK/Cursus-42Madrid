/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen,isainz-r,serferna <webserv@stu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:33:14 by danjimen          #+#    #+#             */
/*   Updated: 2025/07/28 12:23:55 by danjimen,is      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << GREEN << "Dog Empty Constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	this->_brain = new Brain(*other._brain);
	this->_type = other._type;
	std::cout << GREEN << "Dog Copy Constructor called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->_type = other._type;
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	std::cout << GREEN << "Dog Copy Assignment Constructor called" << RESET << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << RED << "Dog Destructor called" << RESET << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << CYAN << this->_type << ": Guau Guau! 🐶" << RESET << std::endl;
}

void Dog::setIdeas(const std::string &idea)
{
	this->_brain->setIdeas(idea);
}

void Dog::printIdeas()
{
	this->_brain->printIdeas();
}