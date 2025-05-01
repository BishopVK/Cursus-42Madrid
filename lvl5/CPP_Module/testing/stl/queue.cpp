/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:16:37 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/01 21:23:43 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <queue>

// queue<T>
// - FIFO (First In, First Out).
// - Usa deque internamente.

int main()
{
	std::queue<int> q;
	q.push(1);
	q.push(2);

	while (!q.empty()) {
		std::cout << q.front() << std::endl;
		q.pop();
	}

	return 0;
}
