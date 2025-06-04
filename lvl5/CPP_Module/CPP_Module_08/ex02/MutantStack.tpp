/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 00:49:26 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/05 01:10:58 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	std::cout << GREEN "MutantStack default constructor called" RESET << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) : std::stack<T>(other)
{
	std::cout << GREEN "MutantStack copy constructor called" RESET << std::endl;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other)
{
	std::cout << GREEN "MutantStack copy assignment operator called" RESET << std::endl;
	if (this != &other)
		std::stack<T>::operator=(other);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << RED "MutantStack destructor called" RESET << std::endl;
}