/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:05:11 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/08 00:58:20 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _gradeSign(150), _gradeExecute(150)
{
	std::cout << GREEN << "Form Empty constructor called" << RESET << std::endl;
}

Form::Form(const std::string &name, const int gradeSign, const int gradeExecute) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	std::cout << GREEN << "Form Default constructor called" << RESET << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute)
{
	std::cout << GREEN << "Form Copy constructor called" << RESET << std::endl;
}

Form &Form::operator=(const Form &other)
{
	std::cout << GREEN << "Form Copy Assignment constructor called" << RESET << std::endl;
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

Form::~Form()
{
	std::cout << RED << "Form destructor called" << RESET << std::endl;
}

std::ostream	&operator<<(std::ostream &os, const Form &object)
{
	os << object._name << " form:" <<std::endl
	<< "\t- Grade to sign: " << object._gradeSign << std::endl
	<< "\t- Grade to Execute: " << object._gradeExecute << std::endl;
	if (object._signed == true)
		os << "\t- Signed" << std::endl;
	else
		os << "\t- Not signed" << std::endl;
	return (os); // Return of the outflow (std::cout)
}

const std::string	Form::getName() const
{
	return (this->_name);
}

bool	Form::getSigned() const
{
	return (this->_signed);
}

const int	Form::getGradeSing() const
{
	return (this->_gradeSign);
}

const int	Form::getGradeExecute() const
{
	return (this->_gradeExecute);
}

void	Form::beSigned(const Bureaucrat &b)
{
	if (this->_gradeSign < b.getGrade())
		throw GradeTooLowException();

	this->_signed = true;
}