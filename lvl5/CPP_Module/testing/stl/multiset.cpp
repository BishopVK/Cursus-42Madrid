/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiset.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:14:20 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/01 21:22:33 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <set>

// multiset<T>
// - Igual que set, pero permite duplicados.

int main()
{
	std::multiset<int> ms;
	ms.insert(3);
	ms.insert(1);
	ms.insert(2);
	ms.insert(1); // Permitido (duplicado)

	for (std::multiset<int>::iterator it = ms.begin(); it != ms.end(); ++it) {
		std::cout << *it << std::endl;
	}
	
	return 0;
}
