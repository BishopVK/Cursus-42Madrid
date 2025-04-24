/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:54:30 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/25 00:38:00 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

#define YELLOW "\033[33m"
#define RESET "\033[0m"

template <typename T>
void	printElement(const T &element)
{
	std::cout << "Element: " << YELLOW << element << RESET << std::endl;
}

template <typename T>
void	iter(T* array, int len, void (*func)(const T &))
{
	if (len <= 0 || !array)
		return;
	for (int i = 0; i < len; ++i)
		func(array[i]);
}

#endif