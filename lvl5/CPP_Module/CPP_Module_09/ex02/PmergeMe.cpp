/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 08:21:00 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/15 11:00:30 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	print_list(std::list<int> list, const std::string &print)
{
	std::list<int>::iterator	it = list.begin();
	int							counter = 0;
	
	while (it != list.end())
	{
		if (print == "part" && list.size() > 4 && counter >= 4)
		{
			std::cout << "[...]";
			break ;
		}
		std::cout << *it << " ";
		counter++;
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

/*------------------------------*/
/*				LIST			*/
/*------------------------------*/
void	move_to_big_and_small(std::list<int> &list, std::list<int> &big, std::list<int> &small)
{
	std::list<int>::iterator it = list.begin();
	while (it != list.end())
	{
		std::list<int>::iterator it_first = it++;
		if (it == list.end())
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

		list.erase(it_second);
		list.erase(it_first);
	}
}

void	insert_from_small_to_big(std::list<int> &big, std::list<int> &small)
{
	std::list<int>::iterator it;
	for (it = small.begin(); it != small.end(); ++it)
	{
		int	value = *it;
		std::list<int>::iterator insert_pos = big.begin();
		while (insert_pos != big.end() && *insert_pos < value)
			++insert_pos;
		big.insert(insert_pos, value);
	}
}

void	insert_hunged_nbr_to_big(bool has_hunged_nbr, int hunged_nbr, std::list<int> &big)
{
	if (has_hunged_nbr)
	{
		std::list<int>::iterator insert_pos = big.begin();
		while (insert_pos != big.end() && *insert_pos < hunged_nbr)
			++insert_pos;
		big.insert(insert_pos, hunged_nbr);
	}
}

void	sort_list(std::list<int> &list)
{
	std::list<int>	big;
	std::list<int>	small;
	int				hunged_nbr;
	bool			has_hunged_nbr = false;

	if (list.size() <= 1)
		return ;

	if (list.size() % 2 != 0)
	{
		std::list<int>::iterator it_last = list.end();
		--it_last;
		hunged_nbr = *it_last;
		list.erase(it_last);
		has_hunged_nbr = true;
	}

	move_to_big_and_small(list, big, small);
	// DB
	// std::cout << std::endl << "-- BIG --" << std::endl;
	// print_list(big);
	// std::cout << std::endl << "-- SMALL --" << std::endl;
	// print_list(small);
	// std::cout << std::endl << "-- HUNGED NBR --" << std::endl;
	// if (has_hunged_nbr)
	// 	std::cout << "Hunged number: " << hunged_nbr << std::endl;
	// else
	// 	std::cout << "No hunged number" << std::endl;
	sort_list(big); // Recursivity
	insert_from_small_to_big(big, small);
	insert_hunged_nbr_to_big(has_hunged_nbr, hunged_nbr, big);

	list.clear();
	list.splice(list.end(), big);
	//list->insert(list->end(), big.begin(), big.end());
}

void	check_ordered(std::list<int> &list)
{
	std::list<int>::iterator it = list.begin();
	while (it != list.end())
	{
		std::list<int>::iterator it_first = it++;
		if (it == list.end())
			break;
		std::list<int>::iterator it_second = it;

		if (*it_first > *it_second)
		{
			std::cout << RED "LIST NOT IN ORDER" RESET << std::endl;
			return ;
		}
	}
	std::cout << GREEN "LIST IN ORDER" RESET << std::endl;
}

void	PmergeMe(char const *argv[])
{
	std::list<int>	list;
	
	list	= create_list(argv);
	print_list(list, "full"); // DB
	clock_t			start_time_list = clock();
	sort_list(list);
	check_ordered(list);
	double	end_list = static_cast<double>(clock() - start_time_list) / CLOCKS_PER_SEC * 10000;
	std::cout << "Time to process a range of " << list.size() << " elements with std::list : " << end_list << " us" << std::endl;
	
	// clock_t			end_time_list = clock();
	// double duration_microseconds = static_cast<double>((end_time_list - start_time_list) * 1e6 / CLOCKS_PER_SEC);
	// double	duration_seconds = double(end_time_list - start_time_list) / CLOCKS_PER_SEC;
	// double	duration_microseconds = duration_seconds * 1e6;
	//std::cout << static_cast<double>(time_list) / CLOCKS_PER_SEC * 1000 << std::endl; // DB

	print_list(list, "full"); // DB
}