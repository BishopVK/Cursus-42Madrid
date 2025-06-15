/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 10:54:49 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/15 11:28:47 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(const std::string &type) : _type(type)
{
}

ATarget::ATarget(const ATarget &other)	: _type(other._type)
{

}

ATarget &ATarget::operator=(const ATarget &other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

ATarget::~ATarget()
{
	
}

std::string const &ATarget::getType() const {return this->_type;}


void	ATarget::getHitBySpell(const ASpell &aspell_ref) const
{
	std::cout << this->_type << " has been " << aspell_ref.getEffects() << "!" << std::endl;
}