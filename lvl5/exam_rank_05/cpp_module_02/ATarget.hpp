/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 10:52:40 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/15 11:26:22 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include <string>

class ASpell;

class ATarget
{
	protected:
		std::string	_type;

	public:
		ATarget();
		ATarget(const std::string &type);
		ATarget(const ATarget &other);
		ATarget &operator=(const ATarget &other);
		virtual ~ATarget();

		std::string const &getType() const;

		virtual ATarget	*clone() const = 0;

		void	getHitBySpell(const ASpell &aspell_ref) const;

};

#include "ASpell.hpp"

#endif