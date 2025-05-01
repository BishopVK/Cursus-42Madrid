/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 23:33:38 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/02 00:50:34 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFINDE_HPP
# define EASYFINDE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <deque>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

template <typename T>
void	easyfind(const T &cont, const int &n);

class EmptyContainerException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

#include "easyfind.tpp"

#endif