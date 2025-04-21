/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:51:09 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/21 20:58:41 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const Fixed &x, const Fixed &y)
{
	this->_x = x;
	this->_y = y;
}

Point::Point(const Point &other)
{
	*this = other;
}

Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		this->_x = other.getX();
		this->_y = other.getY();
	}
	return *this;
}

Point::~Point()
{
}

Fixed Point::getX() const
{
	return (this->_x);
}

Fixed Point::getY() const
{
	return (this->_y);
}