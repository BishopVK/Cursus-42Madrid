/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:35:22 by danjimen          #+#    #+#             */
/*   Updated: 2025/01/28 11:53:45 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	public:
		std::string	firstName = "";
		std::string	lastName = "";
		std::string	nickName = "";
		std::string	phoneNumber;
		std::string	darkestSecret = "";
		// Constructor
		Contact(void);
		// Destructor
		~Contact(void);
};

#endif