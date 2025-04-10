/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:23:48 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/11 00:38:52 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", _signRequired, _execRequired), _target("none")
{
	std::cout << GREEN << "ShrubberyCreationForm Empty constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", _signRequired, _execRequired), _target(target)
{
	std::cout << GREEN << "ShrubberyCreationForm Default constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other.getName(), _signRequired, _execRequired), _target(other._target)
{
	std::cout << GREEN << "ShrubberyCreationForm Copy constructor called" << RESET << std::endl;
	this->setSigned(other.getSigned());
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << GREEN << "ShrubberyCreationForm Copy Assignment constructor called" << RESET << std::endl;
	this->_target = other._target;
	this->setSigned(other.getSigned());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "ShrubberyCreationForm Destructor called" << RESET << std::endl;
}

void ShrubberyCreationForm::executeAction(Bureaucrat const & executor) const
{
	std::string		fileName = this->_target + "_shrubbery";
	std::ofstream	file;

	try
	{
		file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
		file.open(fileName.c_str(), std::ios::in | std::ios::out | std::ios::app);
		file
		<< "        __ _.--..--._ _" << std::endl
		<< "     .-' _/   _/\\_   \\_'-." << std::endl
		<< "    |__ /   _/\\__/\\_   \\__|" << std::endl
		<< "       |___/\\_\\__/  \\___|" << std::endl
		<< "              \\__/" << std::endl
		<< "              \\__/" << std::endl
		<< "               \\__/" << std::endl
		<< "                \\__/" << std::endl
		<< "             ____\\__/___" << std::endl
		<< "       . - '             ' -." << std::endl
		<< "      /                      \\" << std::endl
		<< "~~~~~~~  ~~~~~ ~~~~~  ~~~ ~~~  ~~~~~" << std::endl
		<< "  ~~~   ~~~~~   ~ ~~   ~~ ~  ~ ~ ~~" << std::endl
		<< "PLANTED BY: " << executor.getName() << std::endl << std::endl;
		std::cout << "Correctly planted " << fileName << " Shrubbery 🌲" << std::endl;
	}
	catch(std::ofstream::failure& e)
	{
		std::cerr << RED << "Could not create or wite to file " << fileName << RESET << std::endl;
		std::cerr << RED << "Reason: " << e.what() << RESET << std::endl;
	}
}