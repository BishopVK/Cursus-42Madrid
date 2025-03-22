/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vehiculo.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:51:19 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/22 13:02:02 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vehiculo.hpp"

Vehiculo::Vehiculo()
{
	std::cout << GREEN << "Vehículo creado" << RESET << std::endl;
}

Vehiculo::~Vehiculo()
{
	std::cout << RED << "Vehículo destruido" << RESET << std::endl;
}