/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 10:11:51 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/15 17:29:13 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
	private:
		std::string	_name;
		std::string	_title;

		std::map<std::string, ASpell *> _speel_array;

		SpellBook	_book;

		Warlock();
		Warlock(const Warlock &other);
		Warlock &operator=(const Warlock &other);

	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();

		std::string const &getName() const;
		std::string const &getTitle() const;

		void	setTitle(const std::string &title);

		void	introduce() const;

		void	learnSpell(ASpell *aspell_ptr);
		void	forgetSpell(std::string spell_name);
		void	launchSpell(std::string spell_name, const ATarget &atarget_ref);

};

#endif