/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multimap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:10:57 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/01 21:21:51 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>

// multimap<Key, T>
// - Igual que map, pero permite claves duplicadas.

int main()
{
	std::multimap<std::string, int> mm;
	mm.insert(std::make_pair("clave", 1));
	mm.insert(std::make_pair("clave", 2));

	for (std::multimap<std::string, int>::iterator it = mm.begin(); it != mm.end(); ++it) {
		std::cout << it->first << " => " << it->second << std::endl;
	}
	return 0;
}
