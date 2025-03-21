/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:00:22 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/21 18:30:50 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Returns absolute value
float	absolute(const float &nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

float	calculateArea(const Point &a, const Point &b, const Point &c)
{
	float	area;

	area = 0.5f * absolute((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())) +
							(b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())) +
							(c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())));

	std::cout << "Area = " << area << std::endl;
	
	return (area);
}

bool	bsp(const Point &a, const Point &b, const Point &c, const Point &target)
{
	float abc;
	float abtarget;
	float actarget;
	float bctarget;

	abc = calculateArea(a, b, c);
	abtarget = calculateArea(a, b, target);
	actarget = calculateArea(a, c, target);
	bctarget = calculateArea(b, c, target);
	if (abc == (abtarget + actarget + bctarget))
		return (true);
	return (false);
}