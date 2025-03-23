/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 01:32:12 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/23 01:37:48 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << GREEN << "WrongCat Empty Constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal()
{
	*this = other;
	std::cout << GREEN << "WrongCat Copy Constructor called" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << GREEN << "WrongCat Copy Assignment Constructor called" << RESET << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << RED << "WrongCat Destructor called" << RESET << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << CYAN << this->_type << ": Miaaaaaaaau! 😸" << RESET << std::endl;

}