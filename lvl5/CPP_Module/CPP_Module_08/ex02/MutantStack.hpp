/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:07:11 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/02 16:42:18 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

template <typename T>
class MutantStack : public std::stack<T>
{
	private:
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}
};

/* template <typename T>
class MutantStack
{
	private:
		std::stack<int>	_data;

	public:
		MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack &operator=(const MutantStack &other);
		~MutantStack();

		void	push(const int &n);
		void	pop();
		int		top() const;
		bool	empty() const;
		int		size() const;


}; */

#endif