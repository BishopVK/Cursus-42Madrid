/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:34:47 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/22 01:37:02 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	// Create Bender
	ClapTrap bender("Bender");
	std::cout << std::endl << BOLD << "\t-- STATS --" << RESET << std::endl;
	bender.printStats();

	// Create Robocop
	ClapTrap	robocop(bender);
	robocop.setName("Robocop");
	std::cout << std::endl << BOLD << "\t-- STATS --" << RESET << std::endl;
	robocop.printStats();

	// Fighting
	std::cout << std::endl << BOLD << "\t-- ATTACKING --" << RESET << std::endl;
	bender.attack("Robocop");
	robocop.takeDamage(bender.getAttack());
	robocop.attack("Bender");

	// Repairing
	std::cout << std::endl << BOLD << "\t-- REPAIRING --" << RESET << std::endl;
	bender.beRepaired(10);
	robocop.beRepaired(10);

	// Print stats
	std::cout << std::endl << BOLD << "\t-- STATS --" << RESET << std::endl;
	bender.printStats();
	robocop.printStats();

	std::cout << std::endl << BOLD << "\t-- LOSTING ALL ENERGY POINTS --" << RESET << std::endl;
	while (bender.getEnergy() > 0)
		bender.beRepaired(10);
	std::cout << std::endl << BOLD << "\t-- STATS --" << RESET << std::endl;
	bender.printStats();

	std::cout << std::endl << BOLD << "\t-- ATTACKING AND REPAIRING WITHOUT ENERGY POINTS --" << RESET << std::endl;
	bender.attack("Robocop");
	bender.beRepaired(10);

	return 0;
}
