/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:05:47 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/02 16:45:59 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top value in stack: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size of stack: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	int i = 0;
	while (it != ite)
	{
	std::cout << "Value at " << i << " position: " << *it << std::endl;
	i++;
	++it;
	}
	std::stack<int> s(mstack);
	return 0;
}