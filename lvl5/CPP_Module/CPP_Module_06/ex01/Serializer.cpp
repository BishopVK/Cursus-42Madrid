/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 22:47:39 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/23 00:05:21 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << GREEN << "Empty constructor called" << RESET << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
	std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
	*this = other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	std::cout << GREEN << "Copy assignment constructor called" << RESET << std::endl;
	(void)other;
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}