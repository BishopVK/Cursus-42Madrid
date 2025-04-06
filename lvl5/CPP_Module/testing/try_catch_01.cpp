/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_catch_01.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 23:23:28 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/06 23:45:28 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int	main()
{
	int a = 10, b = 0;

	try
	{
		if (b == 0)
			throw "Error: División por cero";
		cout << "Resultado: " << a / b << endl;
	}
	catch (const char* msg)
	{
		cout << "Excepción atrapada: " << msg << endl;
	}

	return 0;
}
