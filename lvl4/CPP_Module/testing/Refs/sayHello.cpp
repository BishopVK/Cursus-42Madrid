/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sayHello.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:55:23 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/13 23:42:37 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	sayHelloNotModified(std::string name)
{
	name = "Hola, " + name; // No modifica la variable original. Hace una copia.
}

void	sayHelloModified(std::string &name)
{
	name = "Hola, " + name; // Modifica la variable original
}

int	main()
{
	std::string	myName = "Dani";
	sayHelloNotModified(myName); // Pasamos la variable
	std::cout << myName << std::endl; // La variable original NO ha sido modificada
	sayHelloModified(myName); // Pasamos la variable por referencia
	std::cout << myName << std::endl; // La variable original SI ha sido modificada
	return 0;
}