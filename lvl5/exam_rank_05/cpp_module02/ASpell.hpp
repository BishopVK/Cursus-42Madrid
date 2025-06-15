/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 10:41:19 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/15 11:26:13 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include <string>

class ATarget;

class ASpell
{
	protected:
		std::string	_name;
		std::string	_effects;

	public:
		ASpell();
		ASpell(const std::string &name, const std::string &effects);
		ASpell(const ASpell &other);
		ASpell &operator=(const ASpell &other);
		virtual ~ASpell();

		std::string const &getName() const;
		std::string const &getEffects() const;

		virtual ASpell	*clone() const = 0;

		void	launch(const ATarget &atarget_ref) const;

};

#include "ATarget.hpp"

#endif