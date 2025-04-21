/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:45:41 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/21 22:02:42 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << GREEN << "Brain Empty Constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << GREEN << "Brain Copy Constructor called" << RESET << std::endl;
	*this = other;
}

Brain	&Brain::operator=(const Brain &other)
{
	std::cout << GREEN << "Brain Copy Assignment Constructor called" << RESET << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << RED << "Brain Destructor called" << RESET << std::endl;
}

void	Brain::setIdeas(const std::string &idea)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = idea;
	std::cout << YELLOW << "Set ideas to: " << idea << RESET << std::endl;
}

void	Brain::printIdeas() const
{
	for (int i = 0; i < 100; i++)
	{
		std::stringstream ss;
		ss << i;
		std::cout << "Idea " << ss.str() << ": " << CYAN << this->_ideas[i] << RESET << std::endl;
	}
}