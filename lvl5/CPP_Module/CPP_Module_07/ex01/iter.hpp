/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:54:30 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/03 08:38:18 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

#define YELLOW "\033[33m"
#define RESET "\033[0m"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

class Test
{
	private:
		int	_i;

	public:
		Test() : _i(0) {}
		void	setI(int i) {this->_i = i;}
		int		getI() const {return this->_i;}
};

std::ostream &operator<<(std::ostream &os, const Test &t)
{
	os << "Test (" << t.getI() << ")";
	return os;
}

template <typename T>
void	printElement(const T &element)
{
	std::cout << "Element: " << YELLOW << element << RESET << std::endl;
}

template <typename T>
void	iter(T* array, size_t len, void (*func)(const T &))
{
	if (len <= 0 || !array)
		return;
	for (size_t i = 0; i < len; ++i)
		func(array[i]);
}

void	upperCase(const std::string &str)
{
	std::string	tmp;
	for (size_t i = 0; i < str.length(); i++)
		tmp.push_back(std::toupper(str[i]));
	std:: cout << "Element uppercase: " << YELLOW << tmp << RESET << std::endl;
}

#endif