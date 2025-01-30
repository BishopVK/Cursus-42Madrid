/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:18:30 by danjimen          #+#    #+#             */
/*   Updated: 2025/01/30 18:45:47 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	unnamed_zombie;
	unnamed_zombie.announce();

	Zombie	named_zombie("Dumb");
	named_zombie.announce();

	Zombie	*test_zombie;
	test_zombie = newZombie("Dumby");
	test_zombie->announce();
	
	randomChump("Dumbledore");

	delete test_zombie;

	return (0);
}
