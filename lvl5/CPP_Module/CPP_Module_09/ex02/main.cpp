/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 09:48:45 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/09 09:33:05 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	check_args(int argc)
{
	if (argc <= 1)
	{
		std::cerr << RED "Error: Wrong usage" RESET << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

int main(int argc, char const *argv[])
{
	{
		std::cout << std::endl << BLUE "-- TEST 1 --" RESET << std::endl;
		if (check_args(argc) == EXIT_FAILURE)
		return EXIT_FAILURE;
		
		try
		{
			PmergeMe pmergeMe(argc, argv);
			pmergeMe.sortWithList();
			pmergeMe.sortWithVector();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl << BLUE "-- TEST 2 --" RESET << std::endl;

		try
		{
			const char *test[] = {"./PmergeMe", "1", "-5", "42", "0", "53"};

			PmergeMe testPmergeMe(sizeof(test) / sizeof(test[0]), test);
			testPmergeMe.sortWithList();
			testPmergeMe.sortWithVector();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl << BLUE "-- TEST 3 --" RESET << std::endl;

		try
		{
			const char *test[] = {"./PmergeMe", "1", "5", "42", "0", "2147483648"};

			PmergeMe testPmergeMe(sizeof(test) / sizeof(test[0]), test);
			testPmergeMe.sortWithList();
			testPmergeMe.sortWithVector();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	return 0;
}
