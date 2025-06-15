/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 10:43:19 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/15 11:01:38 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(const std::string &name, const std::string &effects) : _name(name), _effects(effects)
{
}

ASpell::ASpell(const ASpell &other)	: _name(other._name), _effects(other._effects)
{

}

ASpell &ASpell::operator=(const ASpell &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_effects = other._effects;
	}
	return *this;
}

ASpell::~ASpell()
{
	
}

std::string const &ASpell::getName() const {return this->_name;}

std::string const &ASpell::getEffects() const {return this->_effects;}

void	ASpell::launch(const ATarget &atarget_ref) const
{
	atarget_ref.getHitBySpell(*this);
}