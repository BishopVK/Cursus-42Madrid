/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:33:13 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/02 14:35:59 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	{
		std::cout << std::endl << YELLOW "-- TEST 1 --" RESET << std::endl;
		Span sp = Span(5);
		
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		try
		{
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		try
		{
			std::cout << std::endl << YELLOW "-- TEST 2 --" RESET << std::endl;
			Span sp = Span(1);

			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	{
		try
		{
			std::cout << std::endl << YELLOW "-- TEST 3 --" RESET << std::endl;
			Span sp = Span(0);

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	{
		try
		{
			std::cout << std::endl << YELLOW "-- TEST 4 --" RESET << std::endl;
			Span sp = Span(1);

			sp.addNumber(6);

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl << YELLOW "-- TEST 5 --" RESET << std::endl;
		Span sp = Span(10000);

		std::srand(time(0));
		for (int i = 0; i < 10000; ++i)
			sp.addNumber(std::rand());

		try
		{
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	return 0;
}
