/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 23:00:22 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/11 23:51:49 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << GREEN << "Intern Empty constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern &other) : _nameForm(other._nameForm), _target(other._target)
{
	std::cout << GREEN << "Intern Copy constructor called" << RESET << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	std::cout << GREEN << "Intern Copy Assignment constructor called" << RESET << std::endl;
	if (this != &other)
	{
		this->_nameForm = other._nameForm;
		this->_target = other._target;
	}
	return (*this);
}

Intern::~Intern()
{
	std::cout << RED << "Intern Destructor called" << RESET << std::endl;
}

AForm *makeShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *makeRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *makePresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &nameForm, const std::string &target)
{
	std::string	formsNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(*form[3])(std::string) = {&makeShrubbery, &makeRobotomy, &makePresidential};

	for (int i = 0; i < 3; i++)
	{
		if (formsNames[i] == nameForm)
		{
			return (form[i](target));
		}
	}
	throw notFormExist();
}