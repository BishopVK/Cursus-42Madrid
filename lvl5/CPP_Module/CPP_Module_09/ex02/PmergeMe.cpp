/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 08:21:00 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/15 23:32:42 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*------------------------------*/
/*				LIST			*/
/*------------------------------*/
void	print_list(std::list<int> list, const std::string &print, const std::string &msg)
{
	std::list<int>::iterator	it = list.begin();
	int							counter = 0;
	
	std::cout << msg << ": ";
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

void	move_to_big_and_small_list(std::list<int> &list, std::list<int> &big, std::list<int> &small)
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

std::list<int>	create_jacobsthal_list(std::list<int> small)
{
	std::list<int>	jacobsthal;
	size_t			j0 = 0;
	size_t			j1 = 1;

	while (j1 < small.size())
	{
		jacobsthal.push_back(j1);
		size_t	next = j1 + 2 * j0;
		j0 = j1;
		j1 = next;
	}
	print_list(jacobsthal, "full", "Jacobsthal"); // DB
	return jacobsthal;
}

int	get_element_at(const std::list<int> &small, size_t index)
{
	std::list<int>::const_iterator it = small.begin();
	std::advance(it, index);
	return *it;
}

void	insert_from_small_to_big_list(std::list<int> &big, std::list<int> &small)
{
	std::list<int>	jacobsthal = create_jacobsthal_list(small);
	std::set<size_t> used_index;

	// Step 1: Insert according to the Jacobsthal sequence
	for (std::list<int>::iterator it = jacobsthal.begin(); it != jacobsthal.end(); ++it)
	{
		size_t	index = *it;
		if (index >= small.size())
			continue ;

		int	value = get_element_at(small, index);
		std::list<int>::iterator insert_pos = big.begin();
		while (insert_pos != big.end() && *insert_pos < value)
			++insert_pos;
		big.insert(insert_pos, value);
		used_index.insert(index);
	}

	// Step 2: Insert the rest of the elements
	for (size_t i = 0; i < small.size(); ++i)
	{
		if (used_index.find(i) != used_index.end())
			continue ;

		int	value = get_element_at(small, i);
		std::list<int>::iterator insert_pos = big.begin();
		while (insert_pos != big.end() && *insert_pos < value)
			++insert_pos;
		big.insert(insert_pos, value);
	}
}

void	insert_hunged_nbr_to_big_list(bool has_hunged_nbr, int hunged_nbr, std::list<int> &big)
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

	move_to_big_and_small_list(list, big, small);
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
	insert_from_small_to_big_list(big, small);
	insert_hunged_nbr_to_big_list(has_hunged_nbr, hunged_nbr, big);

	list.clear();
	list.splice(list.end(), big);
	//list->insert(list->end(), big.begin(), big.end());
}

void	check_list_ordered(std::list<int> &list)
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

/*----------------------------------*/
/*				VECTOR				*/
/*----------------------------------*/
void	print_vector(std::vector<int> vector, const std::string &print, const std::string &msg)
{
	std::vector<int>::iterator	it = vector.begin();
	int							counter = 0;
	
	std::cout << msg;
	while (it != vector.end())
	{
		if (print == "part" && vector.size() > 4 && counter >= 4)
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

std::vector<int>	create_vector(char const *argv[])
{
	std::vector<int>	vector;
	
	int	i = 1;
	while (argv[i])
	{
		vector.push_back(atoi(argv[i]));
		i++;
	}
	return vector;
}

void	move_to_big_and_small_vector(std::vector<int> &vector, std::vector<int> &big, std::vector<int> &small)
{
	std::vector<int>::iterator it = vector.begin();
	while (it != vector.end())
	{
		std::vector<int>::iterator it_first = it++;
		if (it == vector.end())
			break;
		std::vector<int>::iterator it_second = it++;

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

		vector.erase(it_second);
		vector.erase(it_first);
		it = vector.begin();
	}
}

void	insert_from_small_to_big_vector(std::vector<int> &big, std::vector<int> &small)
{
	std::vector<int>::iterator it;
	for (it = small.begin(); it != small.end(); ++it)
	{
		int	value = *it;
		std::vector<int>::iterator insert_pos = big.begin();
		while (insert_pos != big.end() && *insert_pos < value)
			++insert_pos;
		big.insert(insert_pos, value);
	}
}

void	insert_hunged_nbr_to_big_vector(bool has_hunged_nbr, int hunged_nbr, std::vector<int> &big)
{
	if (has_hunged_nbr)
	{
		std::vector<int>::iterator insert_pos = big.begin();
		while (insert_pos != big.end() && *insert_pos < hunged_nbr)
			++insert_pos;
		big.insert(insert_pos, hunged_nbr);
	}
}

void	sort_vector(std::vector<int> &vector)
{
	std::vector<int>	big;
	std::vector<int>	small;
	int					hunged_nbr;
	bool				has_hunged_nbr = false;

	if (vector.size() <= 1)
	return ;
	
	if (vector.size() % 2 != 0)
	{
		std::vector<int>::iterator it_last = vector.end();
		--it_last;
		hunged_nbr = *it_last;
		vector.erase(it_last);
		has_hunged_nbr = true;
	}
	
	move_to_big_and_small_vector(vector, big, small);
	sort_vector(big); // Recursivity
	insert_from_small_to_big_vector(big, small);
	insert_hunged_nbr_to_big_vector(has_hunged_nbr, hunged_nbr, big);

	vector.clear();
	//vector.splice(list.end(), big);
	vector.insert(vector.end(), big.begin(), big.end());
}

void	check_vector_ordered(std::vector<int> &vector)
{
	std::vector<int>::iterator it = vector.begin();
	while (it != vector.end())
	{
		std::vector<int>::iterator it_first = it++;
		if (it == vector.end())
			break;
		std::vector<int>::iterator it_second = it;

		if (*it_first > *it_second)
		{
			std::cout << RED "VECTOR NOT IN ORDER" RESET << std::endl;
			return ;
		}
	}
	std::cout << GREEN "VECTOR IN ORDER" RESET << std::endl;
}

/*----------------------------------*/
/*				PmergeMe			*/
/*----------------------------------*/
void	PmergeMe(char const *argv[])
{
	{
		std::cout << std::endl << YELLOW "\t-- LIST --" RESET << std::endl;
		std::list<int>	list;
		
		list	= create_list(argv);
		print_list(list, "part", "Before");
		clock_t			start_time_list = clock();
		sort_list(list);
		double	end_list = static_cast<double>(clock() - start_time_list) / CLOCKS_PER_SEC * 10000;
		print_list(list, "part", "After");
		check_list_ordered(list); // DB
		std::cout << "Time to process a range of " << list.size() << " elements with std::list : " << end_list << " us" << std::endl;
	}

	{
		std::cout << std::endl << YELLOW "\t-- VECTOR --" RESET << std::endl;
		std::vector<int>	vector;
		
		vector	= create_vector(argv);
		print_vector(vector, "part", "Before");
		clock_t			start_time_list = clock();
		sort_vector(vector);
		double	end_list = static_cast<double>(clock() - start_time_list) / CLOCKS_PER_SEC * 10000;
		print_vector(vector, "part", "After");
		check_vector_ordered(vector); // DB
		std::cout << "Time to process a range of " << vector.size() << " elements with std::list : " << end_list << " us" << std::endl;
	}

}