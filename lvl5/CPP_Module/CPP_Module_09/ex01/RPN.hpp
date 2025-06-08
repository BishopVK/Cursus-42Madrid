/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 23:17:02 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/08 03:16:13 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stdlib.h> // EXIT_FAILURE
#include <stack>
#include <sstream> // stringstream
#include <climits>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

class RPN
{
	private:
		std::string	_input;

	public:
		RPN();
		RPN(const std::string &input);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		void	RPNCalculator();

		std::string	getInput() const;
		void		setInput(const std::string &input);

		class ErrorException : public std::exception
		{
			private:
				std::string _message;
			public:
				ErrorException() : _message(RED "Error" RESET) {}
				ErrorException(const std::string &message) : _message(RED "Error: " + message + RESET) {}
				virtual ~ErrorException() throw() {}
				virtual const char* what() const throw();
		};
};

#endif