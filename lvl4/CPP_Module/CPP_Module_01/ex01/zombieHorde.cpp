/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:47:16 by danjimen          #+#    #+#             */
/*   Updated: 2025/02/02 12:14:00 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	if (N <= 0)
	{
		std::cout << RED BOLD << "Error: " << RESET << "number of zombies must be more than 0." << std::endl; 
		return (NULL);
	}

	Zombie *zombie = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombie[i].set_name(name);

	return (zombie);
}
