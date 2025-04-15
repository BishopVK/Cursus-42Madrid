/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:20:59 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/15 23:28:22 by danjimen         ###   ########.fr       */
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

bool	ContainsNotNumbers(std::string &input)
{
	//std::cout << "DB: input = " << input << std::endl; // DB
	for (size_t i = 0; i < input.length(); i++)
	{
		// DB: Not digit
		if (!std::isdigit(input[i]))
			return true;
	}
	return false;
}

bool	ContainsSpecialChars(std::string &input)
{
	//std::cout << "DB: input = " << input << std::endl; // DB
	for (size_t i = 0; i < input.length(); i++)
	{
		// DB: Not ASCII chars
		if (static_cast<unsigned char>(input[i]) > 127)
			return true;
	}
	return false;
}

int	Phonebook::ContactFields(std::string tag, int current)
{
	std::string	field;
	std::string lavel = TagToLavel(tag);

	while (true)
	{
		std::cout << "\t- "  << BOLD CYAN << lavel << RESET;
		std::getline(std::cin, field);
		if (field.empty())
		{
			if (std::cin.eof())
			{
				std::cout << RED << std::endl << "Input interrupted. Exiting..." << RESET << std::endl;
				return (-1);
			}
			std::cout << " > " << BOLD << "Error: " << BOLD_OFF RED <<"Cannot be empty. Please try again." << RESET << std::endl;
			continue ;
		}
		if (tag == "phoneNumber" && ContainsNotNumbers(field))
		{
			std::cout << " > " << BOLD << "Error: " << BOLD_OFF RED << "Not a valid number. Please insert only digits" << RESET << std::endl;
			continue ;
		}
		if (ContainsSpecialChars(field))
		{
			std::cout << " > " << BOLD << "Error: " << BOLD_OFF RED << "Not special characters allowed. Please use only standard ASCII characters." << RESET << std::endl;
			continue ;
		}
		if (tag == "firstName")
			contact[current].setFirstName(field);
		else if (tag == "lastName")
			contact[current].setLasttName(field);
		else if (tag == "nickName")
			contact[current].setNicktName(field);
		else if (tag == "phoneNumber")
			contact[current].setPhoneNumber(field);
		else if (tag == "darkestSecret")
			contact[current].setDarkestSecret(field);
		else
		{
			std::cout << YELLOW << tag << ": Invalid tag provided." << RESET << std::endl;
			return (-1);
		}
		break;
	}
	return (0);
}

void	Phonebook::add(void)
{
	if (current == MaxContacts)
		current = 0;
	current = current % MaxContacts;
	//std::cout << "current = " << current << std::endl; // DB

	std::cout << std::endl << GREEN << "CREATE A NEW CONTACT:" << RESET << std::endl;
	if (ContactFields("firstName", current) < 0 ||
		ContactFields("lastName", current) < 0 ||
		ContactFields("nickName", current) < 0 ||
		ContactFields("phoneNumber", current) < 0 ||
		ContactFields("darkestSecret", current) < 0)
		return ;
	
	// DB: At the end
	current++;
	if (nbContacts < MaxContacts)
		nbContacts++;
	std::cout << GREEN << std::endl << "Contact added successfully." << RESET << std::endl;
	std::cout << std::endl << YELLOW << "Press Enter to return to Main Menu." << RESET << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // DB: Ignore up to the new line
	if (std::cin.eof())
	{
		std::cout << RED << std::endl << "Input interrupted. Exiting..." << RESET << std::endl;
		return ;
	}
}

void	Phonebook::PrintOneContactField(std::string field, int i)
{
	std::string	Contact::*fieldPtr = NULL;
	std::string	fieldName;
	int			spaceChars = 0;

	if (field == "firstName")
		fieldName = contact[i].getFirstName();
	else if (field == "lastName")
		fieldName = contact[i].getLasttName();
	else if (field == "nickName")
		fieldName = contact[i].getNicktName();
	else
	{
		std::cout << YELLOW << field << ": Invalid field provided." << RESET << std::endl;
		return ;
	}
	if (fieldName.length() > 10)
	{
		std::cout << "|";
		for (int j = 0; j < 9; j++)
			std::cout << fieldName[j];
		std::cout << ".";
	}
	else
	{
		std::cout << "|";
		for (size_t j = 0; j < 10 - fieldName.length(); j++)
			std::cout << " ";
		std::cout << fieldName;
	}
}

bool	IsNumber(const std::string& str)
{
	for (char c : str)
	{
		// DB: Validate if there are a char that its not a digit
		if (!std::isdigit(c))
			return false;
	}

	// Verify its not empty
	return (!str.empty());
}

void	Phonebook::PrintContatDetails(int contactIndex)
{
	int	index = contactIndex - 1;

	std::cout << std::endl << GREEN << "PRINTING DETAILS OF CONTACT:" << RESET << std::endl;
	std::cout << "\t- " << BOLD CYAN << "First name: " << RESET << contact[index].getFirstName() << RESET << std::endl;
	std::cout << "\t- " << BOLD CYAN << "Last name: " << RESET << contact[index].getLasttName() << RESET << std::endl;
	std::cout << "\t- " << BOLD CYAN << "Nick name: " << RESET << contact[index].getNicktName() << RESET << std::endl;
	std::cout << "\t- " << BOLD CYAN << "Phone Number: " << RESET << contact[index].getPhoneNumber() << RESET << std::endl;
	std::cout << "\t- " << BOLD CYAN << "Darkest Secret: " << RESET << contact[index].getDarkestSecret() << RESET << std::endl;

	std::cout << std::endl << YELLOW << "Press Enter to return to Main Menu." << RESET << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // DB: Ignore up to the new line
	if (std::cin.eof())
	{
		std::cout << RED << std::endl << "Input interrupted. Exiting..." << RESET << std::endl;
		return ;
	}
}

void	Phonebook::PrintAllContacts(void)
{
	std::string	contactSelected;
	int			number = -1;

	std::cout << std::endl << GREEN << "PHONEBOOK CONTACTS:" << RESET << std::endl;
	std::cout << std::endl << "|     " << BOLD CYAN << "INDEX" << RESET << "|" << BOLD CYAN << "FIRST NAME" << RESET <<
		"|" << BOLD CYAN << " LAST NAME" << RESET << "|" << BOLD CYAN << "  NICKNAME" << RESET << "|" << std::endl;
	for (int i = 0; i < nbContacts; i++)
	{
		std::cout << "|         " << i + 1;
		PrintOneContactField("firstName", i);
		PrintOneContactField("lastName", i);
		PrintOneContactField("nickName", i);
		std::cout << "|" << std::endl;
	}
	while (true)
	{
		std::cout << std::endl << BOLD << "Select a valid " << CYAN << "INDEX" << WHITE <<  " to view contact details: " << RESET;
		std::getline(std::cin, contactSelected);

		if (contactSelected.empty())
		{
			if (std::cin.eof())
			{
				std::cout << RED << std::endl << "Input interrupted. Exiting..." << RESET << std::endl;
				return ;
			}
			std::cout << RED <<"Cannot be empty. Please try again." << RESET << std::endl;
			continue ;
		}
		if (IsNumber(contactSelected))
		{
			try
			{
				long long temp = std::stoll(contactSelected);

				if (temp >= INT_MIN && temp <= INT_MAX)
				{
					number = static_cast<int>(temp);
					//std::cout << "You have entered the number: " << number << std::endl; // DB
					if (number < 1 || number > nbContacts)
					{
						std::cout << " > " << BOLD << "Error:" << BOLD_OFF RED << " Please insert a valid index." << RESET << std::endl;
						continue ;
					}
					PrintContatDetails(number);
					break;
				}
				else
					std::cout << " > " << BOLD << "Error:" << BOLD_OFF RED << " The number its out of a int number." << RESET << std::endl;
			}
			catch (const std::exception& e)
			{
				std::cout << " > " << BOLD << "Error:" << BOLD_OFF RED << " Not a valid index." << RESET << std::endl;
			}
		}
		else
			std::cout << " > " << BOLD << "Error:" << BOLD_OFF RED << " Not valid index. Please insert only digits." << RESET << std::endl;
	}
	
}

void	Phonebook::search(void)
{
	if (nbContacts <= 0)
	{
		std::cout << std::endl << YELLOW << "No contact was added to the phonebook." << RESET << std::endl;
		return ;
	}
	else
		PrintAllContacts();
}