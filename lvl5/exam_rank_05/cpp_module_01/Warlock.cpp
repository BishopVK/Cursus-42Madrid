/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 10:17:13 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/15 16:58:11 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title) : _name(name), _title(title)
{
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->_name << ": My job here is done!" << std::endl;
}

std::string const &Warlock::getName() const { return (this->_name);}

std::string const &Warlock::getTitle() const { return (this->_title);}

void	Warlock::setTitle(const std::string &title) {this->_title = title;}

void	Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell *aspell_ptr)
{
	_speel_array.insert(std::pair<const std::string, ASpell *>(aspell_ptr->getName(), aspell_ptr->clone()));
}

void	Warlock::forgetSpell(std::string spell_name)
{
	std::map<std::string, ASpell *>::iterator it = _speel_array.find(spell_name);
	if (it != _speel_array.end())
		delete it->second;
	_speel_array.erase(spell_name);
}

void	Warlock::launchSpell(std::string spell_name, const ATarget &atarget_ref)
{
	ASpell *spell = _speel_array[spell_name];
	if (spell)
		spell->launch(atarget_ref);
}
