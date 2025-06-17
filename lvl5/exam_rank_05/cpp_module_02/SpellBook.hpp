/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:08:16 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/15 17:16:42 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include "ASpell.hpp"
#include <map>

class SpellBook
{
	private:
		SpellBook(const SpellBook &other);
		SpellBook &operator=(const SpellBook &other);

		std::map<std::string, ASpell *> _speel_array;

	public:
		SpellBook();
		~SpellBook();

		void	learnSpell(ASpell *aspell_ptr);
		void	forgetSpell(const std::string &spell_name);
		ASpell	*createSpell(const std::string &spell_name);
};

#endif