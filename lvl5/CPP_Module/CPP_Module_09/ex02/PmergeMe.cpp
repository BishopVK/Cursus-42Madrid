/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 08:21:00 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/14 10:20:08 by danjimen         ###   ########.fr       */
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
	std::list<int>	little;
	int				hunged_nbr = 0;

	if (list->size() % 2 != 0)
	{
		hunged_nbr = *list->end();
		list->pop_back();
	}

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