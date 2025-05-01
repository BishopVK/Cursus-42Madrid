/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority_queue.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:16:37 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/01 21:24:40 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <queue>

// priority_queue<T>
// - Montículo (heap) para acceder al elemento mayor.
// - Usa vector y make_heap internamente.

int main()
{
	std::priority_queue<int> pq;
	pq.push(5);
	pq.push(1);
	pq.push(10);

	while (!pq.empty()) {
		std::cout << pq.top() << std::endl; // siempre devuelve el mayor
		pq.pop();
	}

	return 0;
}
