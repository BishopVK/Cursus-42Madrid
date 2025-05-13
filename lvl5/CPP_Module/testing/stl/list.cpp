/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:05:24 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/13 09:40:06 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>

// list<T> (lista doblemente enlazada)
// - Inserciones/eliminaciones eficientes en cualquier parte (O(1)).
// - No permite acceso por índice directo.
// - Más memoria por punteros extra.

/* int	main(void)
{
	std::list<int> lst;
	lst.push_back(1);
	lst.push_front(0);

	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
		std::cout << *it << std::endl;
	}
	return 0;
} */

int main()
{
	std::list<int> l1;
	l1.push_back(1);
	l1.push_back(3);
	l1.push_back(9);
	l1.push_back(7);
	l1.push_back(5);

	l1.sort();
	for (std::list<int>::iterator it = l1.begin(); it != l1.end(); ++it) {
		std::cout << *it << std::endl;
	}
	return 0;
}

