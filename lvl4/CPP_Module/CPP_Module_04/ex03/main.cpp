/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen,isainz-r,serferna <webserv@stu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 02:08:45 by danjimen          #+#    #+#             */
/*   Updated: 2025/07/28 13:02:15 by danjimen,is      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	{
		std::cout << std::endl << YELLOW BOLD "\t>> TEST 1 <<" RESET << std::endl;
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
	}

	{
		std::cout << std::endl << YELLOW BOLD "\t>> TEST 2 <<" RESET << std::endl;
		std::cout << MAGENTA << std::endl << "-- CREATING AND LEARNING MATERIAS --" << RESET << std::endl;
		IMateriaSource* src = new MateriaSource();
		AMateria *ice = new Ice();
		AMateria *cure = new Cure();
		src->learnMateria(ice);
		src->learnMateria(cure);
		src->printMateriaLearned();

		std::cout << MAGENTA << std::endl << "-- CREATING A CHARACTER --" << RESET << std::endl;
		ICharacter* me = new Character("me");
		me->printStats();

		std::cout << MAGENTA << std::endl << "-- CREATING MORE MATERIAS --" << RESET << std::endl;
		AMateria* tmp = src->createMateria("ice");
		if (tmp)
			me->equip(tmp);

		AMateria* tmp2 = src->createMateria("cure");
		if (tmp2)
			me->equip(tmp2);
		
		AMateria* clonedCure = cure->clone();
		me->equip(clonedCure);
		
		std::cout << MAGENTA << std::endl << "-- CREATING A SECOND CHARACTER --" << RESET << std::endl;
		//Character* bob = new Character("bob");
		ICharacter* bob = new Character(static_cast<Character&>(*me));
		bob->setName("bob");

		std::cout << MAGENTA << std::endl << "-- PRINTING CHARACTER STATS --" << RESET << std::endl;
		me->printStats();
		bob->printStats();

		std::cout << MAGENTA << std::endl << "-- PLAYING WHIT THE INVENTORY --" << RESET << std::endl;
		me->use(0, *bob);
		me->use(1, *bob);
		me->unequip(0);
		me->unequip(1);
		me->unequip(3);
		me->unequip(4);
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
			
		std::cout << MAGENTA << std::endl << "-- PRINTING CHARACTER STATS --" << RESET << std::endl;
		me->printStats();
		bob->printStats();

		std::cout << MAGENTA << std::endl << "-- CALLING DESTRUCTORS --" << RESET << std::endl;
		delete bob;
		delete clonedCure;
		if (tmp2)
			delete tmp2;
		if (tmp)
			delete tmp;
		delete me;
		delete cure;
		delete ice;
		delete src;
	}

	return 0;
}
