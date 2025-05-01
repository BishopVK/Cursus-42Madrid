/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:12:08 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/01 21:22:10 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <set>

// set<T>
// - Almacena valores únicos, ordenados.
// - Internamente similar a map, pero solo guarda claves.

int main()
{
	std::set<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(2);
	s.insert(1); // Ignorado (duplicado)

	for (std::set<int>::iterator it = s.begin(); it != s.end(); ++it) {
		std::cout << *it << std::endl;
	}
	return 0;
}
