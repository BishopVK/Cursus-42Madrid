/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 23:13:00 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/08 03:18:01 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char const *argv[])
{
	{
		std::cout << std::endl << YELLOW "-- TEST 1 --" RESET << std::endl;
		if (argc != 2)
		{
			std::cerr << RED "Error: Wrong use." RESET << std::endl;
			return EXIT_FAILURE;
		}

		try
		{
			RPN rpn(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl << YELLOW "-- TEST 2 --" RESET << std::endl;
		try
		{
			RPN rpn("8 9 * 9 - 9 - 9 - 4 - 1 +");

			rpn.setInput("7 7 * 7 -");
			rpn.RPNCalculator();

			rpn.setInput("1 2 * 2 / 2 * 2 4 - +");
			rpn.RPNCalculator();

			rpn.setInput("(1 + 1)");
			rpn.RPNCalculator();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl << YELLOW "-- TEST 3 --" RESET << std::endl;
		try
		{
			RPN rpn("9 9 9 9 9 9 9 9 9 9 * * * * * * * * * ");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			RPN rpn("5 0 /");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			RPN rpn("5 0 3 +");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			RPN rpn("5 0 + -");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			RPN rpn("12 4 +");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			RPN rpn("2 4 a");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			RPN rpn("2 +4 +");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			RPN rpn("2 -4 +");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	
	return EXIT_SUCCESS;
}
