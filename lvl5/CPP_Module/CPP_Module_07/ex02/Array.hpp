/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:10:05 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/01 00:12:22 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
#include <stdlib.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

template <typename T>
class Array
{
	private:
		T*				_ptr;
		unsigned int	_size;

	public:
		Array();
		Array(const unsigned int &n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();

		T	&operator[](unsigned int i);
		unsigned int	size() const;

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#include "Array.tpp"

#endif