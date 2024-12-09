/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Persona.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:18:01 by danjimen          #+#    #+#             */
/*   Updated: 2024/12/09 20:53:12 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERSONA_HPP
# define PERSONA_HPP

// std::string
#include <string>

// Para imprimir en la consola
#include <iostream>

// Definición de la clase Persona
class Persona
{
	private:
		// Atributos privados
		std::string	nombre;
		int			edad;

	public:
		// Constructor
		Persona(std::string nombreInicial, int edadInicial);

		// Método público para mostrar la información de la persona
		void	mostrarInformacion();

		// Método para cambiar el nombre
		void	cambiarNombre(std::string nuevoNombre);

		// Método para cambiar la edad
		void	cambiarEdad(int nuevaEdad);
};

#endif // PERSONA_HPP