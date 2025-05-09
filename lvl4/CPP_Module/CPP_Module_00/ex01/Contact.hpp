/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:35:22 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/15 23:24:37 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

	public:
		// Constructor
		Contact(void);
		// Destructor
		~Contact(void);

	std::string	getFirstName() const;
	std::string	getLasttName() const;
	std::string	getNicktName() const;
	std::string	getPhoneNumber() const;
	std::string	getDarkestSecret() const;

	void	setFirstName(const std::string &value);
	void	setLasttName(const std::string &value);
	void	setNicktName(const std::string &value);
	void	setPhoneNumber(const std::string &value);
	void	setDarkestSecret(const std::string &value);
};

#endif