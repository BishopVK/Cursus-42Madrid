/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen,isainz-r,serferna <webserv@stu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:25:26 by danjimen          #+#    #+#             */
/*   Updated: 2025/07/28 09:14:14 by danjimen,is      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main()
{
	{
		std::cout << YELLOW << std::endl << "-- ANIMALS --" << RESET << std::endl;
		const Animal* animal = new Animal();
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();
		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		cat->makeSound(); //will output the cat sound!
		dog->makeSound(); //will output the dog sound!
		animal->makeSound(); //will output the default sound!

		delete cat;
		delete dog;
		delete animal;
	}

	{
		std::cout << YELLOW << std::endl << "-- WRONG ANIMALS --" << RESET << std::endl;
		const WrongAnimal* wrongAnimal = new WrongAnimal();
		const WrongAnimal* wrongDog = new WrongDog();
		const WrongAnimal* wrongCat = new WrongCat();
		std::cout << wrongDog->getType() << " " << std::endl;
		std::cout << wrongCat->getType() << " " << std::endl;
		wrongCat->makeSound(); //will output the default sound!
		wrongDog->makeSound(); //will output the default sound!
		wrongAnimal->makeSound(); //will output the default sound!

		delete wrongCat;
		delete wrongDog;
		delete wrongAnimal;
	}

	return 0;
}