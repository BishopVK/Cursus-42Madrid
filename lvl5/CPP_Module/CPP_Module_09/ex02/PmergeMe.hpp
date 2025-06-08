/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 09:45:57 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/09 01:19:02 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <cstring> // strlen
#include <list>
#include <vector>
#include <set>
#include <stdlib.h> // atoi
#include <sstream>
#include <climits> // INT_MAX
#include <time.h> // clock()

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class PmergeMe
{
	private:
		int		_argc;
		char**	_argv;
		PmergeMe() {};

	public:
		PmergeMe(int argc, const char* argv[]);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void	sortWithList();
		void	sortWithVector();
};

//void	PmergeMe(char const *argv[]);

#endif