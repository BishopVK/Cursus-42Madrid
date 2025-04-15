/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:35:26 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/15 23:24:39 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string	Contact::getFirstName() const
{
	return (this->_firstName);
}

std::string	Contact::getLasttName() const
{
	return (this->_lastName);
}

std::string	Contact::getNicktName() const
{
	return (this->_nickName);
}

std::string	Contact::getPhoneNumber() const
{
	return (this->_phoneNumber);
}

std::string	Contact::getDarkestSecret() const
{
	return (this->_darkestSecret);
}

void	Contact::setFirstName(const std::string &value)
{
	this->_firstName = value;
}

void	Contact::setLasttName(const std::string &value)
{
	this->_lastName = value;
}

void	Contact::setNicktName(const std::string &value)
{
	this->_nickName = value;
}

void	Contact::setPhoneNumber(const std::string &value)
{
	this->_phoneNumber = value;
}

void	Contact::setDarkestSecret(const std::string &value)
{
	this->_darkestSecret = value;
}