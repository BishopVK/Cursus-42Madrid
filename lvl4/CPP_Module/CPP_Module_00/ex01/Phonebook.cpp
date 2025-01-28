/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:20:59 by danjimen          #+#    #+#             */
/*   Updated: 2025/01/28 12:33:52 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	Phonebook::current = 0;
	Phonebook::nbContacts = 0;
	return ;
}

Phonebook::~Phonebook(void)
{
	return ;
}

std::string	Phonebook::TagToLavel(std::string tag)
{
	std::string	result;

	for (int i = 0; i < tag.length(); i++)
	{
		if (i == 0)
			result.push_back(std::toupper(tag[i]));
		else if (std::isupper(tag[i]))
		{
			result.push_back(' ');
			result.push_back(std::tolower(tag[i]));
		}
		else
			result.push_back(tag[i]);
	}
	result.push_back(':');
	result.push_back(' ');
	return result;
}

void	Phonebook::ContactFields(std::string tag, int current)
{
	std::string Contact::*fieldPtr = nullptr;
	std::string lavel = TagToLavel(tag);

	if (tag == "firstName")
		fieldPtr = &Contact::firstName;
	else if (tag == "lastName")
		fieldPtr = &Contact::lastName;
	else if (tag == "nickName")
		fieldPtr = &Contact::nickName;
	else if (tag == "phoneNumber")
		fieldPtr = &Contact::phoneNumber;
	else if (tag == "darkestSecret")
		fieldPtr = &Contact::darkestSecret;
	else
	{
		std::cout << YELLOW << tag << ": Invalid tag provided." << RESET << std::endl;
		return ;
	}
	while (true)
	{
		std::cout << BOLD << lavel << RESET;
		std::getline(std::cin, contact[current].*fieldPtr);
		if (!(contact[current].*fieldPtr).empty())
			break;
		if (std::cin.eof())
		{
			std::cout << RED << "Input interrupted. Exiting..." << RESET << std::endl;
			return ;
		}
		std::cout << RED << lavel <<"Cannot be empty. Please try again." << RESET << std::endl;
	}
}

void	Phonebook::add(void)
{
	if (current == MaxContacts)
		current = 0;
	current = current % MaxContacts;
	std::cout << "current = " << current << std::endl; // DB

	ContactFields("firstName", current);
	ContactFields("lastName", current);
	ContactFields("nickName", current);
	ContactFields("phoneNumber", current);
	ContactFields("darkestSecret", current);
	
	// At the end
	current++;
	if (nbContacts < MaxContacts)
		nbContacts++;
	std::cout << "Contact added successfully.\n";
}
