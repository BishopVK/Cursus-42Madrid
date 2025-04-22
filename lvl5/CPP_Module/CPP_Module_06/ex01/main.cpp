/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 22:43:03 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/23 00:23:14 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Serializer.hpp"

int main()
{
	Data data;
	data.str = "Hola!";
	uintptr_t	serialized;
	Data		*deserialized = NULL;

	std::cout << std::endl << YELLOW << "\t-- COMPARISON OF POINTERS --" << RESET  << std::endl;
	if (&data == deserialized)
		std::cout << GREEN << "Data pointer and deserialized have the same memory address" << RESET << std::endl;
	else
		std::cout << RED << "The data pointer and the deserialized pointer have different memory addresses" << RESET << std::endl;


	std::cout << std::endl << YELLOW << "\t-- DATA --" << RESET << std::endl;
	std::cout << "Data:" << std::endl
	<< "\t- Pointer: " << &data << std::endl
	<< "\t- String value: " << data.str << std::endl;


	std::cout << std::endl << YELLOW << "\t-- DATA SERIALIZED --" << RESET  << std::endl;
	serialized = Serializer::serialize(&data);
	std::cout << "Data serialized: " << serialized << std::endl << std::endl;


	std::cout << std::endl << YELLOW << "\t-- DATA SERIALIZED DESERIALIZED --" << RESET  << std::endl;
	deserialized = Serializer::deserialize(serialized);
	std::cout << "Data serialized deserialized:" << std::endl
	<< "\t- Pointer: " << deserialized << std::endl
	<< "\t- String value: " << deserialized->str << std::endl;


	std::cout << std::endl << YELLOW << "\t-- COMPARISON OF POINTERS --" << RESET  << std::endl;
	if (&data == deserialized)
		std::cout << GREEN << "Data pointer and deserialized have the same memory address" << RESET << std::endl;
	else
		std::cout << RED << "The data pointer and the deserialized pointer have different memory addresses" << RESET << std::endl;

	return 0;
}
