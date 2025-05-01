/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:15:15 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/01 21:22:53 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>

// stack<T>
// - LIFO (Last In, First Out).
// - Internamente usa deque o vector.

int main()
{
	std::stack<int> st;
	st.push(10);
	st.push(20);

	while (!st.empty()) {
		std::cout << st.top() << std::endl;
		st.pop();
	}
	
	return 0;
}
