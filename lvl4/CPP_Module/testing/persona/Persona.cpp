/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Persona.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:23:15 by danjimen          #+#    #+#             */
/*   Updated: 2025/01/16 12:29:47 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Persona.hpp"

// Implementación del constructor
Persona::Persona(std::string nombreInicial, int edadInicial)
{
	if (nombreInicial == "")
		nombre = "sin_nombre";
	else
		nombre = nombreInicial;
	edad = edadInicial;
}

// Implementación del método mostrarInformación
void	Persona::mostrarInformacion()
{
	std::cout << std::endl << "Datos de contacto:" << std::endl;
	std::cout << "\t- Nombre: " << nombre << std::endl;
	std::cout << "\t- Edad: " << edad << std::endl << std::endl;
}

void	Persona::cambiarNombre(std::string nuevoNombre)
{
	std::cout << nombre << " cambió su nombre a: " << nuevoNombre << std::endl;
	nombre = nuevoNombre;
}

void	Persona::cambiarEdad(int nuevaEdad)
{
	if (nuevaEdad < 0)
	{
		std::cout << "Error: No se puede introducir una edad negativa" << std::endl;
		return ;
	}
	else if (nuevaEdad > edad)
		std::cout << nombre << " envejeció. Ahora tiene " << nuevaEdad << " años." << std::endl;
	else if (nuevaEdad < edad)
		std::cout << nombre << " rejuveneció. Ahora tiene " << nuevaEdad << " años." << std::endl;
	else
		std::cout << nombre << " sigue teniendo " << edad << " años." << std::endl;
	edad = nuevaEdad;
}
