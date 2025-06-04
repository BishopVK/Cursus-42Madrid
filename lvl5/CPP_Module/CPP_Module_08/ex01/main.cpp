/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:33:13 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/05 00:24:45 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	{
		try
		{
			std::cout << std::endl << YELLOW "-- TEST 1 --" RESET << std::endl;
			Span sp = Span(5);
			
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);

			std::cout << std::endl << YELLOW "PRINT SPAN VALUES" RESET << std::endl;
			sp.printSpan();

			std::cout << std::endl << YELLOW "TRY SHORTEST AND LONGEST" RESET << std::endl;
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
		try
		{
			std::cout << std::endl << YELLOW "-- TEST 5 --" RESET << std::endl;
			Span sp = Span(10000);

			std::cout << std::endl << BLUE "CREATE AND FILL values VECTOR WHIT RANDOM INTS" RESET << std::endl;
			std::vector<int> values(10000);
			std::srand(time(0));
			for (size_t i = 0; i < values.capacity(); ++i)
			{
				values[i] = std::rand();
				//std::cout << "values[" << i << "] = " << values[i] << std::endl;
			}

			std::cout << std::endl << BLUE "ADD VALUES FROM values VECTOR TO sp SPAN USING ITERATORS" RESET << std::endl;
			sp.addRange(values.begin(), values.end());

			//sp.printSpan();

			std::cout << std::endl << BLUE "SHORTEST AND LONGEST SPAN" RESET << std::endl;
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
