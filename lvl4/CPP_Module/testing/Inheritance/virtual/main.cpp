/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:40:12 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/22 12:44:42 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Ejercicio 2: Uso de virtual en métodos
Modifica el ejercicio anterior para que hablar() sea virtual en Animal,
de manera que el comportamiento correcto se mantenga incluso con punteros de clase base.
*/

#include "Perro.hpp"

int main()
{
	Animal	*animal = new Perro();
	Animal	a;
	Perro	p;

	animal->Hablar(); // Guau guau (Gracias a `virtual`)
	a.Hablar(); // Hace un sonido
	p.Hablar(); // Guau guau

	delete animal;

	return 0;
}