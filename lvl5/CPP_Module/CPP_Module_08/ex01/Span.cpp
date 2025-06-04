/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:44:23 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/04 12:05:20 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxInts(0)
{
	std::cout << GREEN "Empty constructor called" RESET << std::endl;
}

Span::Span(const unsigned int &n) : _maxInts(n)
{
	std::cout << GREEN "Capacity constructor called" RESET << std::endl;
	this->_data.reserve(n);
}

Span::Span(const Span &other) : _maxInts(other._data.capacity())
{
	std::cout << GREEN "Copy constructor called" RESET << std::endl;
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	std::cout << GREEN "Copy assignment constructor called" RESET << std::endl;
	if (this != &other)
	{
		this->_maxInts = other._maxInts;
		this->_data.clear();
		this->_data = other._data;
	}
	return *this;
}

Span::~Span()
{
	std::cout << RED "Destructor called" RESET << std::endl;
	this->_data.clear();
}

void	Span::addNumber(const int &n)
{
	if (this->_data.size() <= this->_maxInts)
		this->_data.push_back(n);
	else
		throw ContainerFilledException();
}

int	Span::shortestSpan()
{
	if (this->_data.size() <= 1)
		throw EnoughElementsException();

	std::vector<int> copy = this->_data;
	std::sort(copy.begin(), copy.end());

	int	span = INT_MAX;
	for (size_t i = 1; i < copy.size(); ++i)
	{
		int diff = copy[i] - copy[i - 1];
		if (diff < span)
			span = diff;
	}
	return span;
}

int	Span::longestSpan()
{
	if (this->_data.size() <= 1)
		throw EnoughElementsException();

	std::vector<int>::iterator minIt = std::min_element(_data.begin(), _data.end());
	std::vector<int>::iterator maxIt = std::max_element(_data.begin(), _data.end());

	return (*maxIt - *minIt);
}

// Exceptions
const char* Span::ContainerFilledException::what() const throw()
{
	return "The containter is full!";
}

const char* Span::EnoughElementsException::what() const throw()
{
	return "Not enough elements to find a span";
}