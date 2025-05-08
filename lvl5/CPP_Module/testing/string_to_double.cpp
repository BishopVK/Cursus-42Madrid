/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:52:17 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/08 22:58:56 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string str1 = "21454";
	std::string str2 = "5.42";
	std::string str3 = "5.42.16";
	std::string str4 = "-4";

	char* endptr;
	double d1 = std::strtod(str1.c_str(), &endptr);
	if (*endptr == '\0')
		std::cout << "Conversión exitosa: " << d1 << std::endl;
	else
		std::cout << "Error al convertir: parte no convertible = " << endptr << std::endl;

	double d2 = std::strtod(str2.c_str(), &endptr);
	if (*endptr == '\0')
		std::cout << "Conversión exitosa: " << d2 << std::endl;
	else
		std::cout << "Error al convertir: parte no convertible = " << endptr << std::endl;

	double d3 = std::strtod(str3.c_str(), &endptr);
	if (*endptr == '\0')
		std::cout << "Conversión exitosa: " << d3 << std::endl;
	else
		std::cout << "Error al convertir: parte no convertible = " << endptr << std::endl;

	double d4 = std::strtod(str4.c_str(), &endptr);
	if (*endptr == '\0')
		std::cout << "Conversión exitosa: " << d4 << std::endl;
	else
		std::cout << "Error al convertir: parte no convertible = " << endptr << std::endl;


	return 0;
}
