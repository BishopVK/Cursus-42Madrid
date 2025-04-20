/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:40:32 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/21 00:31:12 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>
#include <limits>

int main(void)
{
	{
		std::cout << std::endl << "-- EXAMPLE INT --" << std::endl;
		int	i = 65;
		
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float>(i) << std::endl;
		std::cout << "double: " << static_cast<double>(i) << std::endl;
		std::cout << "char: " << static_cast<char>(i) << std::endl;
	}

	{
		std::cout << std::endl << "-- EXAMPLE FLOAT --" << std::endl;
		float	i = 65.3f;
		
		std::cout << "float: " << i << std::endl;
		std::cout << "int: " << static_cast<int>(i) << std::endl;
		std::cout << "double: " << static_cast<double>(i) << std::endl;
		std::cout << "char: " << static_cast<char>(i) << std::endl;
	}

	{
		std::cout << std::endl << "-- EXAMPLE DOUBLE --" << std::endl;
		double	i = 65.45;
		
		std::cout << "double: " << i << std::endl;
		std::cout << "int: " << static_cast<int>(i) << std::endl;
		std::cout << "float: " << static_cast<float>(i) << std::endl;
		std::cout << "char: " << static_cast<char>(i) << std::endl;
	}

	{
		std::cout << std::endl << "-- EXAMPLE CHAR --" << std::endl;
		char	i = 'A';
		
		std::cout << "char: " << i << std::endl;
		std::cout << "int: " << static_cast<int>(i) << std::endl;
		std::cout << "float: " << static_cast<float>(i) << std::endl;
		std::cout << "double: " << static_cast<double>(i) << std::endl;
	}

	{
		std::cout << std::endl << "-- EXAMPLE DOUBLE ESPECIALS --" << std::endl;
		//double nan = std::sqrt(-1.0);	// devuelve NaN (not a number)
		//double nan = 0.0 / 0.0;	// devuelve NaN (not a number)
		double nan = std::numeric_limits<double>::quiet_NaN(); // en <limits>
		double pos_inf = 1.0 / 0.0;		// +infinito
		double neg_inf = -1.0 / 0.0;	// -infinito

		std::cout << "double NaN: " << nan << std::endl;
		std::cout << "double +inf: " << pos_inf << std::endl;
		std::cout << "double -inf: " << neg_inf << std::endl;
	}

	return 0;
}
