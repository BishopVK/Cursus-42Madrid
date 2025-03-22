/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:34:47 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/22 21:54:50 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

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

	// Create R2D2
	FragTrap	r2d2("R2D2");
	std::cout << std::endl << BOLD << "\t-- STATS --" << RESET << std::endl;
	r2d2.printStats();

	// Create Wall·E
	DiamondTrap	wall_e("Wall·E");
	std::cout << std::endl << BOLD << "\t-- STATS --" << RESET << std::endl;
	wall_e.printStats();

	// Fighting
	std::cout << std::endl << BOLD << "\t-- ATTACKING --" << RESET << std::endl;
	bender.attack("Robocop");
	robocop.takeDamage(bender.getAttack());
	robocop.attack("R2D2");
	r2d2.takeDamage(robocop.getAttack());
	r2d2.attack("Wall·E");
	wall_e.takeDamage(r2d2.getAttack());
	wall_e.attack("Bender");
	bender.takeDamage(wall_e.getAttack());

	// Repairing
	std::cout << std::endl << BOLD << "\t-- REPAIRING --" << RESET << std::endl;
	bender.beRepaired(10);
	robocop.beRepaired(10);
	r2d2.beRepaired(10);
	wall_e.beRepaired(10);

	// Print stats
	std::cout << std::endl << BOLD << "\t-- STATS --" << RESET << std::endl;
	bender.printStats();
	robocop.printStats();
	r2d2.printStats();
	wall_e.printStats();

	// ScavTrap Guard Gate Mode
	std::cout << std::endl << BOLD << "\t-- GUARD GATE MODE --" << RESET << std::endl;
	robocop.guardGate();

	// FragTrap high-five
	std::cout << std::endl << BOLD << "\t-- HIGH FIVE --" << RESET << std::endl;
	r2d2.highFivesGuys();

	// DiamondTrap who am i
	std::cout << std::endl << BOLD << "\t-- WHO AM I --" << RESET << std::endl;
	wall_e.whoAmI();

	// Energy to zero
	std::cout << std::endl << BOLD << "\t-- LOSTING ENERGY POINTS --" << RESET << std::endl;
	bender.setEnergy(0);
	robocop.setEnergy(0);
	r2d2.setEnergy(0);
	wall_e.setHitPoints(0);

	// Print stats
	std::cout << std::endl << BOLD << "\t-- STATS --" << RESET << std::endl;
	bender.printStats();
	robocop.printStats();
	r2d2.printStats();
	wall_e.printStats();

	// Actions whitout energy points
	std::cout << std::endl << BOLD << "\t-- ATTACKING AND REPAIRING WITHOUT HIT OR ENERGY POINTS --" << RESET << std::endl;
	bender.attack("Robocop");
	bender.beRepaired(10);
	robocop.attack("R2D2");
	robocop.beRepaired(10);
	r2d2.attack("Bender");
	r2d2.beRepaired(10);
	wall_e.attack("Bender");
	wall_e.beRepaired(10);

	// ScavTrap Guard Gate Mode
	std::cout << std::endl << BOLD << "\t-- GUARD GATE MODE WHITHOUT HIT POINTS --" << RESET << std::endl;
	robocop.setHitPoints(0);
	robocop.guardGate();

	// FragTrap high-five
	std::cout << std::endl << BOLD << "\t-- HIGH FIVE WHITHOUT HIT POINTS --" << RESET << std::endl;
	r2d2.setHitPoints(0);
	r2d2.highFivesGuys();

	// DiamondTrap who am i
	std::cout << std::endl << BOLD << "\t-- WHO AM I WHITHOUT HIT POINTS --" << RESET << std::endl;
	wall_e.setHitPoints(0);
	wall_e.whoAmI();

	// Destructors autocall
	std::cout << std::endl << BOLD << "\t-- DESTRUCTORS --" << RESET << std::endl;

	return 0;
}
