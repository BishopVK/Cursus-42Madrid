/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:23:48 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/21 23:46:35 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", _signRequired, _execRequired), _target("none")
{
	std::cout << GREEN << "RobotomyRequestForm Empty constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", _signRequired, _execRequired), _target(target)
{
	std::cout << GREEN << "RobotomyRequestForm Default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other.getName(), _signRequired, _execRequired), _target(other._target)
{
	std::cout << GREEN << "RobotomyRequestForm Copy constructor called" << RESET << std::endl;
	this->setSigned(other.getSigned());
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << GREEN << "RobotomyRequestForm Copy Assignment constructor called" << RESET << std::endl;
	this->_target = other._target;
	this->setSigned(other.getSigned());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm Destructor called" << RESET << std::endl;
}

void RobotomyRequestForm::executeAction(Bureaucrat const & executor) const
{
	struct timeval	tv;
	unsigned int	seed;

	gettimeofday(&tv, 0);
	seed = tv.tv_sec ^ tv.tv_usec;
	std::srand(seed); // Initialize srand generator whit a seed
	if (std::rand() % 2 == 0)
		std::cout << "🪛 Bzzzzzzz bzzzzzzzzzzzz... " << this->_target << " has been robotomized by " << executor.getName() << std::endl;
	else
		std::cout << this->_target << " robotomy failed 🤞🏼" << std::endl;
}

void RobotomyRequestForm::print(std::ostream &os) const
{
	AForm::print(os);
	os << "\t- Target: " << this->_target << std::endl;
}