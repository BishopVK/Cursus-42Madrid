/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:55:01 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/10 23:37:38 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>		// rand() and srand()
#include <ctime>		// time()
#include <sys/time.h>	// gettimeofday()
#include <iostream>

int	main()
{
	{
	// Inicializa la semilla del generador con el tiempo actual
	std::srand(std::time(0));

	// Genera un número aleatorio entre 0 y RAND_MAX
	int numero = std::rand();
	std::cout << numero << std::endl;

	// Si quieres un número entre 0 y 99, por ejemplo:
	int entre0y99 = std::rand() % 100;
	std::cout << entre0y99 << std::endl;
	}

	{
		struct timeval tv;
		gettimeofday(&tv, 0);
	
		unsigned int seed = tv.tv_sec ^ tv.tv_usec;
		std::srand(seed);
	
		std::cout << std::rand() % 2 << std::endl;
	
		return 0;
	}

	return 0;
}