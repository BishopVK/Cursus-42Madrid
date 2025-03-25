/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 02:08:45 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/25 22:09:31 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int main()
{
	/* {
		const AMateria *ice = new Ice();
		const AMateria *cure = new Cure();
		Ice		ice2;
		Cure	cure2;

		std::cout << "Ice type: " << ice->getType() << std::endl;
		std::cout << "Cure type: " << cure->getType() << std::endl;
		std::cout << "Ice2 type: " << ice2.getType() << std::endl;
		std::cout << "Cure2 type: " << cure2.getType() << std::endl;

		delete cure;
		delete ice;
	} */

	{
		/* IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure()); */

		AMateria *ice = new Ice();
		AMateria *cure = new Cure();
		AMateria *cure2 = new Cure();

		Character* me = new Character("me");
		me->printStats();


		/* AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure"); */
		
		me->equip(ice);
		me->equip(cure);
		
		Character* bob = new Character(*me);
		//ICharacter* bob = new Character(dynamic_cast<Character&>(*me));

		me->printStats();
		me->use(0, *bob);
		me->use(1, *bob);
		me->unequip(0);
		me->use(0, *bob);
		me->use(1, *bob);
		me->equip(cure2);
		
		std::cout << ">> ME <<" << std::endl;
		me->printStats();
		std::cout << ">> BOB <<" << std::endl;
		bob->printStats();
		delete bob;
		delete me;
		//delete src;
	}

	return 0;
}
