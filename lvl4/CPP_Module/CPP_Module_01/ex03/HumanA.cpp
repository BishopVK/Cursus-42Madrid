/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:20:06 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/16 23:02:08 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : _name(name), _weapon(&weapon)
{
	std::cout << GREEN << "Human A '" << this->_name << "' was created." << RESET << std::endl;
}

HumanA::~HumanA()
{
	std::cout << RED << "Human A '" << this->_name << "' was destroyed." << RESET << std::endl;
}

void	HumanA::attack() const
{
	std::cout << this->_name << " attacks with their '" << this->_weapon->getType() << "'" << std::endl;
}

void	HumanA::setWeapon(Weapon &newWeapon)
{
	std::cout << "'" << this->_weapon->getType() << "' was replaced by: ";
	this->_weapon = &newWeapon;
	std::cout << this->_weapon->getType() << std::endl;
}