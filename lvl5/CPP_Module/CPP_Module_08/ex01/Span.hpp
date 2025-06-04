/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:37:39 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/05 00:23:20 by danjimen         ###   ########.fr       */
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
#define BLUE "\033[34m"
#define RESET "\033[0m"


class Span
{
	private:
		std::vector<int>	_data;
		std::size_t				_maxInts;
		
	public:
		Span();
		Span(const unsigned int &n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void		addNumber(const int &n);
		long long	shortestSpan() const;
		long long	longestSpan() const;

		template <typename It>
		void	addRange(It begin, It end);

		void		printSpan() const; // Extra

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

template <typename It>
void Span::addRange(It begin, It end)
{
	for (It it = begin; it != end; ++it)
	{
		if (_data.size() >= _maxInts)
			throw ContainerFilledException();
		_data.push_back(*it);
	}
}

#endif