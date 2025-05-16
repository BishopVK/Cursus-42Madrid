/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 00:38:34 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/16 10:13:54 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("no_name"), _grade(150)
{
	std::cout << GREEN << "Bureaucrat " << this->_name << " Empty constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << GREEN << "Bureaucrat " << this->_name << " Default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	std::cout << GREEN << "Bureaucrat Copy Constructor called" << RESET << std::endl;
	*this = other;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << GREEN << "Bureaucrat Copy Assignment Constructor called" << RESET << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat " << this->_name << " Destructor called" << RESET << std::endl;
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade++;
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &object)
{
	os << object.getName() << ", bureaucrat grade " << object.getGrade();
	return (os); // Return of the outflow (std::cout)
}

void	Bureaucrat::signForm(AForm &f)
{
	try
	{
		if (f.getSigned())
		{
			std::cout << f.getName() << " it's already signed" << std::endl;
			return ;
		}
		f.beSigned(*this);
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn’t sign " << f.getName() << " because " <<  e.what() << std::endl;
	}
	
}

void		Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		std::cout << this->_name << " executed " << form.getName() << std::endl;
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn’t execute " << form.getName() << " because " <<  e.what() << std::endl;
	}
}

// EXTRA

void	Bureaucrat::setName(const std::string &newName)
{
	this->_name = newName;
}

void	Bureaucrat::setGrade(int newGrade)
{
	this->_grade = newGrade;
}