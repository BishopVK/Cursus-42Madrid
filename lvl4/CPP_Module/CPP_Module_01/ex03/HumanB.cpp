/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:14:31 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/21 12:39:14 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : _name(name), _weapon(NULL)
{
	std::cout << GREEN << "Human B '" << this->_name << "' was created." << RESET << std::endl;
}

HumanB::~HumanB()
{
	std::cout << RED << "Human B '" << this->_name << "' was destroyed." << RESET << std::endl;
}

void	HumanB::attack() const
{
	if (_weapon == NULL)
		std::cout << this->_name << " can't attack because he doesn't have a weapon." << std::endl;
	else
		std::cout << this->_name << " attacks with their '" << this->_weapon->getType() << "'" << std::endl;

}

void	HumanB::setWeapon(Weapon &newWeapon)
{
	if (_weapon == NULL)
	{
		std::cout << this->_name  << " receives: ";
		this->_weapon = &newWeapon;
		std::cout << this->_weapon->getType() << std::endl;
	}
	else
	{
		std::cout << "'" << this->_weapon->getType() << "' was replaced by: ";
		this->_weapon = &newWeapon;
		std::cout << this->_weapon->getType() << std::endl;
	}
}