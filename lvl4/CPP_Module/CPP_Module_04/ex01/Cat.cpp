/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen,isainz-r,serferna <webserv@stu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:33:14 by danjimen          #+#    #+#             */
/*   Updated: 2025/07/28 12:15:26 by danjimen,is      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << GREEN << "Cat Empty Constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	this->_brain = new Brain(*other._brain);
	this->_type = other._type;
	std::cout << GREEN << "Cat Copy Constructor called" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		this->_type = other._type;
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	std::cout << GREEN << "Cat Copy Assignment Constructor called" << RESET << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << RED << "Cat Destructor called" << RESET << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << CYAN << this->_type << ": Miaaaaaaaau! 😸" << RESET << std::endl;
}

void Cat::setIdeas(const std::string &idea)
{
	this->_brain->setIdeas(idea);
}

void Cat::printIdeas()
{
	this->_brain->printIdeas();
}