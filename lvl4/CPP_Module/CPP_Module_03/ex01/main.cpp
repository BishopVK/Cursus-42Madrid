/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:34:47 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/22 14:27:25 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	// Create Bender
	ClapTrap bender("Bender");
	std::cout << std::endl << BOLD << "\t-- STATS --" << RESET << std::endl;
	bender.printStats();

	// Create Robocop
	ScavTrap	robocop("Robocop");
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

	// ScavTrap Guard Gate Mode
	std::cout << std::endl << BOLD << "\t-- GUARD GATE MODE--" << RESET << std::endl;
	robocop.guardGate();

	// Energy to zero
	std::cout << std::endl << BOLD << "\t-- LOSTING ENERGY POINTS AND HIT POINTS --" << RESET << std::endl;
	bender.setEnergy(0);
	robocop.setHitPoints(0);

	// Print stats
	std::cout << std::endl << BOLD << "\t-- STATS --" << RESET << std::endl;
	bender.printStats();
	robocop.printStats();

	// Actions whitout energy points
	std::cout << std::endl << BOLD << "\t-- ATTACKING AND REPAIRING WITHOUT ENERGY POINTS --" << RESET << std::endl;
	bender.attack("Robocop");
	bender.beRepaired(10);
	robocop.attack("Bender");
	robocop.beRepaired(10);

	// ScavTrap Guard Gate Mode
	std::cout << std::endl << BOLD << "\t-- GUARD GATE MODE--" << RESET << std::endl;
	robocop.guardGate();

	// Destructors autocall
	std::cout << std::endl << BOLD << "\t-- DESTRUCTORS --" << RESET << std::endl;

	return 0;
}
