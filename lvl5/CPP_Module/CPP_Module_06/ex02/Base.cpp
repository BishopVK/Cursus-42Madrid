/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:17:30 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/23 09:05:51 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}

Base	*generate(void)
{
	struct timeval	tv;
	gettimeofday(&tv, 0);

	unsigned int	seed = tv.tv_sec ^ tv.tv_usec;
	srand(seed); // Initialize srand generator whit a seed
	int	random = rand() % 3;

	switch (random)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	case 2:
		return new C();
	default:
		return NULL;
	}
	
	return NULL;
}

void	identify(Base* p)
{
	std::cout << GREEN << "POINTER IDENTIFY() CALL:" << RESET << std::endl;
	if (dynamic_cast<A*>(p))
	{
		std::cout << "Pointer type: " << CYAN << "A" << RESET << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "Pointer type: " << CYAN << "B" << RESET << std::endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "Pointer type: " << CYAN << "C" << RESET << std::endl;
	}
	else
		std::cout << RED << "Invalid pointer type" << RESET << std::endl;
}

void	identify(Base& p)
{
	std::cout << GREEN << "REFERENCE IDENTIFY() CALL:" << RESET << std::endl;
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Reference type: " << CYAN << "A" << RESET << std::endl;
		return;
	} catch (std::exception&) {}

	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Reference type: " << CYAN << "B" << RESET << std::endl;
		return;
	} catch (std::exception&) {}

	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Reference type: " << CYAN << "C" << RESET << std::endl;
		return;
	} catch (std::exception&) {}
}