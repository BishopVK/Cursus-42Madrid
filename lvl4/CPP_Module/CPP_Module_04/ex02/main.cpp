/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen,isainz-r,serferna <webserv@stu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:25:26 by danjimen          #+#    #+#             */
/*   Updated: 2025/07/28 12:27:26 by danjimen,is      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		std::cout << std::endl << YELLOW BOLD "\t>> BASIC TESTS <<" RESET << std::endl;
		//const Animal* meta = new Animal(); // Can't be instantiable
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();
		Dog newDog;

		std::cout << std::endl << "-- DOG SET IDEAS --" << std::endl;
		newDog.setIdeas("I want to go out and play in the mud");

		std::cout << std::endl << "-- DOG IDEAS --" << std::endl;
		newDog.printIdeas();

		std::cout << std::endl << "-- CREATE A DOG COPY --" << std::endl;
		Dog dogCopy(newDog);

		std::cout << std::endl << "-- DOG COPY IDEAS --" << std::endl;
		dogCopy.printIdeas();

		std::cout << std::endl << "-- UPDATE DOG IDEAS --" << std::endl;
		newDog.setIdeas("I want to eat");

		std::cout << std::endl << "-- DOG IDEAS --" << std::endl;
		newDog.printIdeas();

		std::cout << std::endl << "-- DOG COPY IDEAS --" << std::endl;
		dogCopy.printIdeas();

		std::cout << std::endl << "-- GET TYPE --" << std::endl;
		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		std::cout << newDog.getType() << " " << std::endl;
		std::cout << dogCopy.getType() << " " << std::endl;
		
		std::cout << std::endl << "-- MAKE DOUND --" << std::endl;
		cat->makeSound(); //will output the cat sound!
		dog->makeSound();
		//meta->makeSound();
		newDog.makeSound();
		dogCopy.makeSound();
		
		std::cout << std::endl << "-- DELETE OBJECTS --" << std::endl;
		delete cat;
		delete dog;
		//delete meta;
	}

	{
		std::cout << std::endl << YELLOW BOLD "\t>> ARRAY TESTS <<" RESET << std::endl;
		std::cout << std::endl << "-- FILL ARRAY WHIT 50 DOGS AND 50 CATS --" << std::endl;
		const Animal* array[10];
		for (int i = 0; i < 10; i++)
		{
			if (i % 2 == 0)
				array[i] = new Dog();
			else
				array[i] = new Cat();
			std::cout << std::endl;
		}

		std::cout << std::endl << "-- ARRAY GET TYPE AND MAKE SOUNDS --" << std::endl;
		for (int i = 0; i < 10; i++)
		{
			std::cout << array[i]->getType() << std::endl;
			array[i]->makeSound();
			std::cout << std::endl;
		}

		std::cout << std::endl << "-- DELETE ALL OBJECTS --" << std::endl;
		for (int i = 0; i < 10; i++)
		{
			delete array[i];
			std::cout << std::endl;
		}
	}

	return 0;
}