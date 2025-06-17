/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 10:17:13 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/15 22:07:19 by danjimen         ###   ########.fr       */
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
	_book.learnSpell(aspell_ptr);
}

void	Warlock::forgetSpell(std::string spell_name)
{
	_book.forgetSpell(spell_name);
}

void	Warlock::launchSpell(std::string spell_name, const ATarget &atarget_ref)
{
	ATarget const *test = 0;
	if (test == &atarget_ref)
		return ;
	ASpell *spell = _book.createSpell(spell_name);
	if (spell)
		spell->launch(atarget_ref);
}
