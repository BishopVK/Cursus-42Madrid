/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:37:39 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/04 13:18:38 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"


class Span
{
	private:
		std::vector<int>	_data;
		long unsigned int	_maxInts;
		Span();

	public:
		Span(const unsigned int &n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void	addNumber(const int &n);
		int		shortestSpan();
		int		longestSpan();

		void	fillSpan();

		void	printSpan();

		class ContainerFilledException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class EnoughElementsException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif