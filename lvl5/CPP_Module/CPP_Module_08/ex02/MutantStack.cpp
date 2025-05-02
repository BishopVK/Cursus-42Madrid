/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:16:25 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/02 16:36:39 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
	std::cout << GREEN "MutantStack empty constructor called" RESET << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other)
{
	std::cout << GREEN "MutantStack copy constructor called" RESET << std::endl;
	*this = other;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
	std::cout << GREEN "MutantStack copy assignment constructor called" RESET << std::endl;
	if (this != &other)
		this->_data = other._data;
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << RED "MutantStack destructor called" RESET << std::endl;
}

template <typename T>
void	MutantStack<T>::push(const int &n)
{
	_data.push(n);
}

template <typename T>
void	MutantStack<T>::pop()
{
	_data.pop();
}

template <typename T>
int	MutantStack<T>::top() const
{
	return _data.top();
}

template <typename T>
bool	MutantStack<T>::empty() const
{
	return _data.empty();
}

template <typename T>
int	MutantStack<T>::size() const
{
	return _data.size();
}