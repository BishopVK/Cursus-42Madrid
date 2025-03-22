/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Coche.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:52:44 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/22 13:02:24 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Coche.hpp"

Coche::Coche()
{
	std::cout << GREEN << "Coche creado" << RESET << std::endl;
}

Coche::~Coche()
{
	std::cout << RED << "Coche destruido" << RESET << std::endl;
}