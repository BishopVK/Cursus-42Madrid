/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 08:21:00 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/15 00:13:00 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	print_list(std::list<int> list)
{
	std::list<int>::iterator	it = list.begin();
	
	while (it != list.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

std::list<int>	create_list(char const *argv[])
{
	std::list<int>	list;
	
	int	i = 1;
	while (argv[i])
	{
		list.push_back(atoi(argv[i]));
		i++;
	}
	return list;
}

void	sort_list(std::list<int> *list)
{
	std::list<int>	big;
	std::list<int>	small;
	int				hunged_nbr;
	bool			has_hunged_nbr = false;

	if (list->size() % 2 != 0)
	{
		std::list<int>::iterator it_last = list->end();
		--it_last;
		hunged_nbr = *it_last;
		list->erase(it_last);
		list->pop_back();
		has_hunged_nbr = true;
	}

	std::list<int>::iterator it = list->begin();
	while (it != list->end())
	{
		std::list<int>::iterator it_first = it++;
		if (it == list->end())
			break;
		std::list<int>::iterator it_second = it++;

		if (*it_first > *it_second)
		{
			big.push_back(*it_first);
			small.push_back(*it_second);
		}
		else
		{
			big.push_back(*it_second);
			small.push_back(*it_first);
		}

		list->erase(it_second);
		list->erase(it_first);
	}

	std::cout << std::endl << "-- BIG --" << std::endl;
	print_list(big);
	std::cout << std::endl << "-- SMALL --" << std::endl;
	print_list(small);
	std::cout << std::endl << "-- HUNGED NBR --" << std::endl;
	if (has_hunged_nbr)
		std::cout << "Hunged number: " << hunged_nbr << std::endl;
	else
		std::cout << "No hunged number" << std::endl;
}

void	PmergeMe(char const *argv[])
{
	std::list<int>	list;
	clock_t			time_list = clock();

	list	= create_list(argv);
	std::cout << static_cast<double>(time_list) / CLOCKS_PER_SEC * 1000 << std::endl; // DB
	//print_list(list); // DB
	sort_list(&list);
}