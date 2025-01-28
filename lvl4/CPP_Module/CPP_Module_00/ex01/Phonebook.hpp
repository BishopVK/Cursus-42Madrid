/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:36:44 by danjimen          #+#    #+#             */
/*   Updated: 2025/01/28 12:37:09 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

#define MaxContacts 3

class Phonebook
{
	private:
		int		current;
		int		nbContacts;
		Contact	contact[MaxContacts];
	public:
		// Constructor
		Phonebook(void);
		// Destructor
		~Phonebook(void);

		void		add(void);
		std::string	TagToLavel(std::string tag);
		void		ContactFields(std::string tag, int current);
		/* void	search(void);
		void	PrintAllContacts(void);
		void	PrintOneContact(void);
		void	EraseContact(void); */
};

#endif