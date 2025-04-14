/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:29:54 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/14 22:43:20 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyClass.hpp"

int main()
{
	MyClass a, b;
	std::cout << "a counter = "<< a._counter << std::endl;
	std::cout << "b counter = "<< b._counter << std::endl;
	a.increment();
	std::cout << "a counter = "<< a._counter << std::endl;
	std::cout << "b counter = "<< b._counter << std::endl;
	MyClass::_counter = 5;
	MyClass::staticIncrement();
	MyClass::printCounter();
	return 0;
}
