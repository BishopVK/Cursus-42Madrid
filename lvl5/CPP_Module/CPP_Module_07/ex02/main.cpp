/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 00:36:29 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/01 01:36:02 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	{
		std::cout << std::endl << YELLOW "--  TEST 1 --" RESET << std::endl;
		std::cout << std::endl << CYAN "CREATING INT \"ARRAY\":" RESET<< std::endl;
		Array<int>	array(10);
		srand(time(NULL));
		for (unsigned int i = 0; i < array.size(); i++)
		{
			int value = rand();
			array[i] = value;
		}
		std::cout << std::endl << CYAN "PRINTING \"ARRAY\" VALUES:" RESET<< std::endl;
		for (unsigned int i = 0; i < array.size(); i++)
			std::cout << array[i] << std::endl;
		
		std::cout << std::endl << CYAN "CREATING \"COPY\" ARRAY FROM \"ARRAY\":" RESET<< std::endl;
		Array<int>	copy = array;

		std::cout << std::endl << CYAN "PRINTING \"COPY\" VALUES:" RESET<< std::endl;
		for (unsigned int i = 0; i < copy.size(); i++)
			std::cout << copy[i] << std::endl;

		std::cout << std::endl << CYAN "DESTRUCTORS:" RESET<< std::endl;
	}

	{
		std::cout << std::endl << YELLOW "--  TEST 2 --" RESET << std::endl;
		std::cout << std::endl << CYAN "CREATING STRINGS \"ARRAY\":" RESET<< std::endl;
		Array<std::string>	array(6);
		array[0] = "En";
		array[1] = "un";
		array[2] = "lugar";
		array[3] = "de";
		array[4] = "la";
		array[5] = "mancha";

		std::cout << std::endl << CYAN "PRINTING \"ARRAY\" VALUES:" RESET<< std::endl;
		for (unsigned int i = 0; i < array.size(); i++)
			std::cout << array[i] << " ";
		std::cout << std::endl;

		std::cout << std::endl << CYAN "DESTRUCTORS:" RESET<< std::endl;
	}

	{
		std::cout << std::endl << YELLOW "--  TEST 3 --" RESET << std::endl;
		std::cout << std::endl << CYAN "CREATING CHAR \"ARRAY\":" RESET<< std::endl;
		Array<char>	array(6);
		array[0] = 'd';
		array[1] = 'a';
		array[2] = 'n';
		array[3] = 'i';
		array[4] = 'e';
		array[5] = 'l';

		std::cout << std::endl << CYAN "PRINTING \"ARRAY\" VALUES:" RESET<< std::endl;
		for (unsigned int i = 0; i < array.size(); i++)
			std::cout << array[i];
		std::cout << std::endl;

		std::cout << std::endl << CYAN "TRYING TO ACCES TO INVALID POSITIONS" RESET<< std::endl;
		try
		{
			array[-2] = 's';
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		try
		{
			std::cout << array[6] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		std::cout << std::endl << CYAN "DESTRUCTORS:" RESET<< std::endl;
	}

	{
		std::cout << std::endl << YELLOW "--  TEST 4 --" RESET << std::endl;
		try
		{
			std::cout << std::endl << CYAN "CREATING BOOL \"ARRAY\" WHIT A SIZE OF ZERO:" RESET<< std::endl;
			Array<char>	array(0);
			array[0] = true;
			array[1] = false;
			array[2] = true;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << '\n';
		}

		try
		{
			std::cout << std::endl << CYAN "CREATING BOOL \"ARRAY\" WHIT A NEGATIVE SIZE:" RESET<< std::endl;
			Array<char>	array(-1);
			array[0] = true;
			array[1] = false;
			array[2] = true;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << '\n';
		}

		try
		{
			std::cout << std::endl << CYAN "CREATING BOOL \"ARRAY\" WHIT A BIG SIZE:" RESET<< std::endl;
			Array<char>	array(100001);
			array[0] = true;
			array[1] = false;
			array[2] = true;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << '\n';
		}

		std::cout << std::endl << CYAN "DESTRUCTORS:" RESET<< std::endl;
	}
	
	return 0;
}
