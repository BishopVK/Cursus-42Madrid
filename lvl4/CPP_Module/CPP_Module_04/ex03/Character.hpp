/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:12:19 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/26 02:13:28 by danjimen         ###   ########.fr       */
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
		AMateria	*inventory[4] = {nullptr, nullptr, nullptr, nullptr};
		std::list<AMateria*> floor; // Lista para Materias desequipadas
		bool		_slot_occupied[4] = {false, false, false, false};
	public:
		Character(const std::string &name);
		Character(const Character &other);
		Character &operator=(const Character &other);
		~Character();

		std::string const	&getName() const override;
		void	equip(AMateria* m) override;
		void	unequip(int idx) override;
		void	use(int idx, ICharacter& target) override;

		void	printStats() override;
		void	setName(const std::string &name) override;
};

#endif