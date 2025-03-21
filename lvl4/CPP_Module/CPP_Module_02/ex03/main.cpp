/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:44:38 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/21 18:40:33 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	Point a(2,2);
	Point b(4,7);
	Point c(9,3);
	Point target(3,3);

	if (bsp(a, b, c, target))
		std::cout << GREEN << "Target point (" << target.getX() << "," << target.getY() << ") its inside the triangle" << RESET << std::endl;
	else
		std::cout << RED << "Target point (" << target.getX() << "," << target.getY() << ") its outside the triangle" << RESET << std::endl;

	return 0;
}
