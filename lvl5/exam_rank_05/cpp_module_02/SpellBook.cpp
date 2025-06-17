/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:14:26 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/15 17:27:42 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *>::iterator it_begin = _speel_array.begin();
	std::map<std::string, ASpell *>::iterator it_end = _speel_array.begin();
	while (it_begin != it_end)
	{
		delete it_begin->second;
		++it_begin;
	}
	this->_speel_array.clear();
}

void	SpellBook::learnSpell(ASpell *aspell_ptr)
{
	if (aspell_ptr)
		_speel_array.insert(std::pair<const std::string, ASpell *>(aspell_ptr->getName(), aspell_ptr->clone()));
}

void	SpellBook::forgetSpell(const std::string &spell_name)
{
	std::map<std::string, ASpell *>::iterator it = _speel_array.find(spell_name);
	if (it != _speel_array.end())
		delete it->second;
	_speel_array.erase(spell_name);
}

ASpell	*SpellBook::createSpell(const std::string &spell_name)
{
	std::map<std::string, ASpell *>::iterator it = _speel_array.find(spell_name);
	if (it != _speel_array.end())
		return it->second->clone();
	return NULL;
}
