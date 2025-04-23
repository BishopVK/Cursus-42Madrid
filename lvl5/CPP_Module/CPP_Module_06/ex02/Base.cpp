/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:17:30 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/23 22:18:17 by danjimen         ###   ########.fr       */
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
	(void)p;
}

void	identify(Base& p)
{
	(void)p;
}