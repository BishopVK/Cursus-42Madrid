/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 09:45:57 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/09 09:13:03 by danjimen         ###   ########.fr       */
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
#include <stdexcept>

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

		void	validateArgv();

		void	sortWithList();
		void	sortWithVector();

		class WrongInputValueException : public std::exception
		{
			private:
				std::string _argv;
				std::string	_message;

			public:
				WrongInputValueException(const std::string &argv, const std::string &errorMsg) : _argv(argv) {
					_message = "Error: " + this->_argv + errorMsg;
				}
				virtual ~WrongInputValueException() throw() {}
				virtual const char* what() const throw();
		};
};

#endif