/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:09:56 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/23 22:47:02 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	{
		std::cout << std::endl << YELLOW << "-- Test 1 --" << RESET << std::endl;
		A	*a = new A();
		B	*b = new B();
		C	*c = new C();

		identify(a);
		identify(b);
		identify(c);

		identify(*a);
		identify(*b);
		identify(*c);

		delete a;
		delete b;
		delete c;
	}

	{
		std::cout << std::endl << YELLOW << "-- Test 2 --" << RESET << std::endl;
		Base	*base;
		
		base = generate();
		
		identify(base);
		identify(*base);

		delete base;
	}

	return 0;
}
