/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:12:19 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/25 15:56:08 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include "AMateria.hpp"

class AMateria; // Forward declaration

class ICharacter
{
	public:
		virtual ~ICharacter() {}

		virtual std::string const &getName() const = 0; // Pure virtual method
		virtual void equip(AMateria* m) = 0; // Pure virtual method
		virtual void unequip(int idx) = 0; // Pure virtual method
		virtual void use(int idx, ICharacter& target) = 0; // Pure virtual method

		virtual void	printStats() = 0;
};

#endif