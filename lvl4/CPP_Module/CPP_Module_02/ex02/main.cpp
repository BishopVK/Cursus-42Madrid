/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:44:38 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/21 20:55:57 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	Fixed c = 12;
	Fixed d = 21;
	Fixed e (c + d);
	
	std::cout << e << std::endl;
	if (c < d)
		std::cout << c << std::endl;
	else
		std::cout << d << std::endl;

	Fixed f = 8;
	Fixed g = 16;
	const Fixed h = 24;
	const Fixed i = 32;
	std::cout << Fixed::min(f, g) << std::endl;
	std::cout << Fixed::max(f, g) << std::endl;
	std::cout << Fixed::min(h, i) << std::endl;
	std::cout << Fixed::max(h, i) << std::endl;

	return 0;
}
