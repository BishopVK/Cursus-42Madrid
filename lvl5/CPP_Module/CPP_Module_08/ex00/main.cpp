/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 23:31:38 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/02 00:52:02 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	{
		std::cout << std::endl << YELLOW << "-- TEST 1 --" << RESET << std::endl;
		std::vector<int> vec;
		vec.push_back(3);
		vec.push_back(1);
		vec.push_back(2);
		
		try
		{
			easyfind(vec, 1);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
		}
	}

	{
		std::cout << std::endl << YELLOW << "-- TEST 2 --" << RESET << std::endl;
		std::vector<int> vec;
		vec.push_back(3);
		vec.push_back(1);
		vec.push_back(2);
		
		try
		{
			easyfind(vec, 5);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
		}
	}

	{
		std::cout << std::endl << YELLOW << "-- TEST 3 --" << RESET << std::endl;
		std::vector<int> vec;

		try
		{
			easyfind(vec, 5);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
		}
	}

	{
		std::cout << std::endl << YELLOW << "-- TEST 4 --" << RESET << std::endl;
		std::list<int>	lst;
		lst.push_back(10);
		lst.push_back(20);
		lst.push_back(18);

		try
		{
			easyfind(lst, 18);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
		}
	}

	{
		std::cout << std::endl << YELLOW << "-- TEST 5 --" << RESET << std::endl;
		std::deque<int>	dq;
		dq.push_back(10);
		dq.push_front(20);
		dq.push_back(18);

		try
		{
			easyfind(dq, 10);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
		}
	}

	return 0;
}
