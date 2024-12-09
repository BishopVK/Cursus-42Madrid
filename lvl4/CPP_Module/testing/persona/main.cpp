/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:28:38 by danjimen          #+#    #+#             */
/*   Updated: 2024/12/09 21:04:12 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Persona.hpp"

int	main(void)
{
	// Crear un objeto de la clase Persona
	Persona persona1("Charlotte", 40);

	// Llamar al método mostrarInformacion
	persona1.mostrarInformacion();

	// Llamar al método cambiarNombre
	persona1.cambiarNombre("Mamá");

	// Llamar al método cambiarNombre
	persona1.cambiarEdad(-10);

	// Llamar al método mostrarInformacion
	persona1.mostrarInformacion();

	return (0);
}
