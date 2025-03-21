/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:00:22 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/21 18:37:55 by danjimen         ###   ########.fr       */
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

bool	bsp(const Point &a, const Point &b, const Point &c, const Point &target)
{
	Fixed abc;
	Fixed abtarget;
	Fixed actarget;
	Fixed bctarget;

	abc = calculateArea(a, b, c, "abc");
	abtarget = calculateArea(a, b, target, "abtarget");
	actarget = calculateArea(a, c, target, "actarget");
	bctarget = calculateArea(b, c, target, "bctarget");
	if (abc == (abtarget + actarget + bctarget))
		return (true);
	return (false);
}