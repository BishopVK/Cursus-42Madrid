/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_catch_04.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 23:23:28 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/06 23:42:32 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
using namespace std;

class MiExcepcion : public exception {
public:
	const char* what() const noexcept override {
		return "¡Esto es una excepción personalizada!";
	}
};

int main()
{
	try
	{
		throw MiExcepcion();
	}
	catch (const MiExcepcion& e)
	{
		cout << "Excepción atrapada: " << e.what() << endl;
	}

	return 0;
}
