/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_catch_03.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 23:23:28 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/06 23:40:34 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input = "abc";

	try
	{
		int num = stoi(input); // Lanza excepción si no es un número válido
		cout << "Número convertido: " << num << endl;
	}
	catch (const invalid_argument& e)
	{
		cout << "Excepción atrapada: entrada no válida -> " << e.what() << endl;
	}

	return 0;
}
