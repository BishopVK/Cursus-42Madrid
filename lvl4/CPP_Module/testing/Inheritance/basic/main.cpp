/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:19:21 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/22 12:38:49 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Ejercicio 1: Introducción a la herencia
Crea una clase Animal con un método hablar() que imprima "Hace un sonido".
Luego, crea una clase Perro que herede de Animal y sobrescriba hablar() para imprimir "Guau guau".
*/

#include "Perro.hpp"

int main()
{
	Animal	animal;
	Perro	perro;

	animal.Hablar();
	perro.Hablar();

	return 0;
}
