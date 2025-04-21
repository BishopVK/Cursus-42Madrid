/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:47:16 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/21 08:23:32 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	if (N <= 0)
	{
		std::cerr << RED BOLD << "Error: " << RESET << "number of zombies must be more than 0." << std::endl; 
		return (NULL);
	}

	Zombie *zombie = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombie[i].set_name(name + "_" + std::to_string(i + 1));

	return (zombie);
}
