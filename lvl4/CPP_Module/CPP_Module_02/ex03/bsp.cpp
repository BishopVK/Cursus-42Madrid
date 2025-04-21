/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:00:22 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/21 21:03:07 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Returns absolute value
Fixed	absolute(const Fixed &nb)
{
	if (nb < 0)
		return (Fixed(nb) * -1);
	return (nb);
}

Fixed	calculateArea(const Point &a, const Point &b, const Point &c, const std::string &name)
{
	Fixed	area;

	area = Fixed(0.5f) * absolute((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())) +
							(b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())) +
							(c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())));

	std::cout << "Area " << name << " = " << area << std::endl;
	
	return (area);
}

bool	bsp(const Point &a, const Point &b, const Point &c, const Point &point)
{
	Fixed abc;
	Fixed abpoint;
	Fixed acpoint;
	Fixed bcpoint;

	abc = calculateArea(a, b, c, "a-b-c");
	abpoint = calculateArea(a, b, point, "a-b-point");
	acpoint = calculateArea(a, c, point, "a-c-point");
	bcpoint = calculateArea(b, c, point, "b-c-point");
	if (abc == (abpoint + acpoint + bcpoint))
		return (true);
	return (false);
}