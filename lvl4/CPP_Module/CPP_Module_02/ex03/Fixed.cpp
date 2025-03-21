/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:58:47 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/21 03:16:12 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(const Fixed &other)
{
	*this = other; // Calls assignmet operator
}

Fixed::Fixed(const int number)
{
	this->_value = number << this->_fractionalBits; // Shifts bits 8 positions to the left (= *256)
}

Fixed::Fixed(const float number)
{
	this->_value = static_cast<int>(roundf(number * (1 << this->_fractionalBits))); // Shifts bits 8 positions to the left (= *256) and round the result decimals
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
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
	out << fixed.toFloat(); // Convertimos el fixed-point a float antes de imprimirlo
	return out;
}

// COMPARISON OPERATORS
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_value = other.getRawBits(); // Copy the value if it is not itself
	return *this;
}

bool	Fixed::operator>(const Fixed &other) const
{
	if (this->getRawBits() > other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed &other) const
{
	if (this->getRawBits() < other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	if (this->getRawBits() >= other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	if (this->getRawBits() <= other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &other) const
{
	if (this->getRawBits() == other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	if (this->getRawBits() != other.getRawBits())
		return (true);
	return (false);
}

// ARITHMETIC OPERATORS
Fixed	Fixed::operator+(const Fixed &other)
{
	Fixed	result;
	result.setRawBits(this->getRawBits() + other.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other)
{
	Fixed	result;
	result.setRawBits(this->getRawBits() - other.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed &other)
{
	Fixed	result;
	result.setRawBits((this->toFloat() * other.toFloat()) * (1 << _fractionalBits));
	return (result);
}

Fixed	Fixed::operator/(const Fixed &other)
{
	Fixed	result;
	result.setRawBits((this->toFloat() / other.toFloat()) * (1 << _fractionalBits));
	return (result);
}

// INCREMENT/DECREMENT OPERATORS
// ++a
Fixed	&Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

// a++
Fixed	Fixed::operator++(int)
{
	Fixed	before_increment;

	before_increment = *this;
	this->_value++;
	return (before_increment);
}

// --a
Fixed	&Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

// a--
Fixed	Fixed::operator--(int)
{
	Fixed	before_decrement;

	before_decrement = *this;
	this->_value--;
	return (before_decrement);
}

// OVERLOADED FUNCTIONS
// Returns smallest
Fixed	&Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 < fixed2)
		return (fixed1);
	return (fixed2);
}

// Returns const smallest
const Fixed	&Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1 < fixed2)
		return (fixed1);
	return (fixed2);
}

// Returns greatest
Fixed	&Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 > fixed2)
		return (fixed1);
	return (fixed2);
}

// Returns const greatest
const Fixed	&Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1 > fixed2)
		return (fixed1);
	return (fixed2);
}