/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:18:30 by danjimen          #+#    #+#             */
/*   Updated: 2025/02/02 12:05:58 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int			number = 5;
	std::string	name = "Generic_zombie";

	Zombie	unnamed_zombie;
	unnamed_zombie.announce();

	Zombie	named_zombie("named_zombie");
	named_zombie.announce();

	Zombie	*zombie_horde;
	zombie_horde = zombieHorde(number, name);

	for (int i = 0; i < number; i++)
		zombie_horde[i].announce();

	delete[] zombie_horde;

	return (0);
}
