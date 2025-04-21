/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:23:48 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/21 23:51:07 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", _signRequired, _execRequired), _target("none")
{
	std::cout << GREEN << "PresidentialPardonForm Empty constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", _signRequired, _execRequired), _target(target)
{
	std::cout << GREEN << "PresidentialPardonForm Default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other.getName(), _signRequired, _execRequired), _target(other._target)
{
	std::cout << GREEN << "PresidentialPardonForm Copy constructor called" << RESET << std::endl;
	this->setSigned(other.getSigned());
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << GREEN << "PresidentialPardonForm Copy Assignment constructor called" << RESET << std::endl;
	this->_target = other._target;
	this->setSigned(other.getSigned());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "PresidentialPardonForm Destructor called" << RESET << std::endl;
}

void PresidentialPardonForm::executeAction(Bureaucrat const & executor) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox 🫱🏽‍🫲🏼" << std::endl;
	(void)executor;
}

void PresidentialPardonForm::print(std::ostream &os) const
{
	AForm::print(os);
	os << "\t- Target: " << this->_target << std::endl;
}