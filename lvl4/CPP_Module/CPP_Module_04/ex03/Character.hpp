/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:12:19 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/11 01:33:56 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*inventory[4] = {NULL, NULL, NULL, NULL};
		std::list<AMateria*> floor; // Lista para Materias desequipadas
		bool		_slot_occupied[4] = {false, false, false, false};
	public:
		Character(const std::string &name);
		Character(const Character &other);
		Character &operator=(const Character &other);
		~Character();

		std::string const	&getName() const;
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);

		void	printStats();
		void	setName(const std::string &name);
};

#endif