/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multimap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen,isainz-r,serferna <webserv@stu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:10:57 by danjimen          #+#    #+#             */
/*   Updated: 2025/07/06 17:36:44 by danjimen,is      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>

// multimap<Key, T>
// - Igual que map, pero permite claves duplicadas.

int main()
{
	std::multimap<std::string, int> mm;
	mm.insert(std::make_pair("clave1", 1));
	mm.insert(std::make_pair("clave2", 2));
	mm.insert(std::make_pair("clave1", 3));
	mm.insert(std::make_pair("clave2", 4));
	mm.insert(std::make_pair("clave2", 5));

	for (std::multimap<std::string, int>::iterator it = mm.begin(); it != mm.end(); ++it) {
		std::cout << it->first << " => " << it->second << std::endl;
	}

	// Using key range
	std::pair<std::multimap<std::string, int>::iterator, std::multimap<std::string, int>::iterator> rango = mm.equal_range("clave2");

	std::cout << "Valores para la clave2:" << std::endl;
	std::multimap<std::string, int>::iterator it;
	for (it = rango.first; it != rango.second; ++it)
	{
		std::cout << "- Valor: " << it->second << std::endl;
	}


	return 0;
}
