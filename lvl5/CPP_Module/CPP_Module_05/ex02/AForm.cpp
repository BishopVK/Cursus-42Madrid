/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:05:11 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/21 23:45:13 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _gradeSign(150), _gradeExecute(150)
{
	std::cout << GREEN << "AForm Empty constructor called" << RESET << std::endl;
}

AForm::AForm(const std::string &name, const int gradeSign, const int gradeExecute) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	std::cout << GREEN << "AForm Default constructor called" << RESET << std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute)
{
	std::cout << GREEN << "AForm Copy constructor called" << RESET << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << GREEN << "AForm Copy Assignment constructor called" << RESET << std::endl;
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

AForm::~AForm()
{
	std::cout << RED << "AForm destructor called" << RESET << std::endl;
}

std::ostream	&operator<<(std::ostream &os, const AForm &object)
{
	object.print(os);
	return (os); // Return of the outflow (std::cout)
}

void	AForm::print(std::ostream &os) const
{
	os << this->_name << " form:" <<std::endl
	<< "\t- Grade to sign: " << this->_gradeSign << std::endl
	<< "\t- Grade to Execute: " << this->_gradeExecute << std::endl;
	if (this->_signed == true)
		os << "\t- Signed" << std::endl;
	else
		os << "\t- Not signed" << std::endl;
}

const std::string	AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSigned() const
{
	return (this->_signed);
}

int	AForm::getGradeSing() const
{
	return (this->_gradeSign);
}

int	AForm::getGradeExecute() const
{
	return (this->_gradeExecute);
}

void	AForm::beSigned(const Bureaucrat &b)
{
	if (this->_gradeSign < b.getGrade())
		throw GradeTooLowException();

	this->_signed = true;
}

void	AForm::setSigned(bool value)
{
	this->_signed = value;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (this->_signed == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->_gradeExecute)
		throw GradeTooLowException();

	executeAction(executor);
}