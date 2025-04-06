/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_catch_02.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 23:23:28 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/06 23:34:13 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int main()
{
	int arr[3] = {1, 2, 3};

	try
	{
		int index = 5;
		if (index < 0 || index >= 3)
			throw out_of_range("Índice fuera de rango");
		cout << "Valor: " << arr[index] << endl;
	}
	catch (const out_of_range& e)
	{
		cout << "Excepción atrapada: " << e.what() << endl;
	}

	return 0;
}
