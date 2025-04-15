/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:35:26 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/15 13:13:32 by danjimen         ###   ########.fr       */
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

std::string	Contact::setFirstName(const std::string &value)
{
	this->_firstName = value;
}

std::string	Contact::setLasttName(const std::string &value)
{
	this->_lastName = value;
}

std::string	Contact::setNicktName(const std::string &value)
{
	this->_nickName = value;
}

std::string	Contact::setPhoneNumber(const std::string &value)
{
	this->_phoneNumber = value;
}

std::string	Contact::setDarkestSecret(const std::string &value)
{
	this->_darkestSecret = value;
}