/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:58:47 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/21 20:42:09 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
	*this = other; // Calls assignmet operator
}

Fixed::Fixed(const int number)
{
	std::cout << GREEN << "Int constructor called" << RESET << std::endl;
	this->_value = number << this->_fractionalBits; // Shifts bits 8 positions to the left (= *256)
}

Fixed::Fixed(const float number)
{
	std::cout << GREEN << "Float constructor called" << RESET << std::endl;
	this->_value = static_cast<int>(roundf(number * (1 << this->_fractionalBits))); // Shifts bits 8 positions to the left (= *256) and round the result decimals
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << GREEN << "Copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		this->_value = other.getRawBits(); // Copy the value if it is not itself
	return *this;
}

Fixed::~Fixed()
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->_value) / (1 << this->_fractionalBits)); // (/ 256)
}

int		Fixed::toInt( void ) const
{
	return (this->_value >> this->_fractionalBits); // (/ 256)
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat(); // We convert the fixed-point to float before printing it
	return out;
}