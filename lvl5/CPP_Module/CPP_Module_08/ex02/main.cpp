/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:05:47 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/05 01:16:20 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	{
		std::cout << std::endl << YELLOW "-- TEST 1 --" RESET << std::endl;
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
		std::cout << std::endl << "mstack values:" << std::endl;
		while (it != ite)
		{
			std::cout << "Value at " << i++ << " position: " << *it << std::endl;
			++it;
		}
		
		std::stack<int> s(mstack);
		i = 1;
		std::cout << std::endl << "s values:" << std::endl;
		while (!s.empty())
		{
			std::cout << "Value at " << s.size() - i << " position: " << s.top() << std::endl;
			s.pop();
		}
	}

	{
		std::cout << std::endl << YELLOW "-- TEST 2 --" RESET << std::endl;
		MutantStack<int>	mstack;
		std::list<int>		lst;

		mstack.push(5);
		mstack.push(17);
		lst.push_back(5);
		lst.push_back(17);

		std::cout << "Top value in mstack: " << mstack.top() << std::endl;
		std::cout << "Top value in list: " << lst.back() << std::endl;

		mstack.pop();
		lst.pop_back();

		std::cout << "Size of mstack: " << mstack.size() << std::endl;
		std::cout << "Size of list: " << lst.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);

		std::cout << std::endl << BLUE "CREATE mstack ITERATORS AND PRINT VALUES" RESET << std::endl;
		MutantStack<int>::iterator mstack_it = mstack.begin();
		MutantStack<int>::iterator mstack_ite = mstack.end();

		++mstack_it;
		--mstack_it;
		int i = 0;
		std::cout << std::endl << "mstack values:" << std::endl;
		while (mstack_it != mstack_ite)
		{
			std::cout << "mstack value at " << i++ << " position: " << *mstack_it << std::endl;
			++mstack_it;
		}
		
		std::cout << std::endl << BLUE "CREATE lst ITERATORS AND PRINT VALUES" RESET << std::endl;
		std::list<int>::iterator lst_it = lst.begin();
		std::list<int>::iterator lst_ite = lst.end();

		++lst_it;
		--lst_it;
		i = 0;
		std::cout << std::endl << "lst values:" << std::endl;
		while (lst_it != lst_ite)
		{
			std::cout << "lst value at " << i++ << " position: " << *lst_it << std::endl;
			++lst_it;
		}
	}

	{
		std::cout << std::endl << YELLOW "-- TEST 3 --" RESET << std::endl;
		MutantStack<int> mstack;

		srand(time(NULL));
		for (int i = 0; i < 100; ++i)
			mstack.push(rand() % 100);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		int i = 0;
		std::cout << std::endl << "mstack values:" << std::endl;
		while (it != ite)
		{
			std::cout << "Value at " << i++ << " position: " << *it << std::endl;
			++it;
		}
	}
	return 0;
}