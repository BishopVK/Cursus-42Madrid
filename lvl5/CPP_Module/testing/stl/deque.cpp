/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:07:03 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/01 21:20:41 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <deque>

// deque<T> (double-ended queue)
// - Acceso por índice como vector.
// - Inserciones rápidas en ambos extremos.
// - Internamente más complejo que vector.

int main()
{
	std::deque<int> dq;
	dq.push_back(10);
	dq.push_front(5);

	for (size_t i = 0; i < dq.size(); ++i) {
		std::cout << "dq[" << i << "] = " << dq[i] << std::endl;
	}
	
	return 0;
}
