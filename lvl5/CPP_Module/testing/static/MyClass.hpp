/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyClass.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:26:15 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/14 22:43:10 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATIC_HPP
# define STATIC_HPP

#include <iostream>
#include <string>

class MyClass
{
	public:
		static int	_counter;
		void	increment()
		{
			_counter++;
		}

		static void	staticIncrement()
		{
			_counter++;
		}

		static void	printCounter()
		{
			std::cout << _counter << std::endl;
		}
};

int MyClass::_counter = 0; // definición y posible valor inicial

#endif