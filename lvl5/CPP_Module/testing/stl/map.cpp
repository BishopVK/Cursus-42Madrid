/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:08:41 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/01 21:21:36 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>

// map<Key, T>
// - Almacena pares clave-valor, ordenados por clave.
// - Acceso/inserción/borrado: O(log n).
// - No permite claves duplicadas.

int main()
{
	std::map<std::string, int> m;
	m["uno"] = 1;
	m["dos"] = 2;

	for (std::map<std::string, int>::iterator it = m.begin(); it != m.end(); ++it) {
		std::cout << it->first << " => " << it->second << std::endl;
	}
	return 0;
}
