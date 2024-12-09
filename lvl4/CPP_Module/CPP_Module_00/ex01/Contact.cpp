/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:35:26 by danjimen          #+#    #+#             */
/*   Updated: 2024/12/09 21:46:04 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Se ha creado un contacto" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	std::cout << "Se ha destruido un contacto" << std::endl;
	return ;
}