/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:25:26 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/23 22:45:23 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	/* {
		std::cout << std::endl << "-- BASIC TESTS --" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		Dog dog;

		std::cout << std::endl << "-- DOG SET IDEAS --" << std::endl;
		dog.setIdeas("I want to go out and play in the mud");

		std::cout << std::endl << "-- DOG IDEAS --" << std::endl;
		dog.printIdeas();

		std::cout << std::endl << "-- CREATE A DOG COPY --" << std::endl;
		Dog dogCopy(dog);

		std::cout << std::endl << "-- DOG COPY IDEAS --" << std::endl;
		dogCopy.printIdeas();

		std::cout << std::endl << "-- UPDATE DOG IDEAS --" << std::endl;
		dog.setIdeas("I want to eat");

		std::cout << std::endl << "-- DOG IDEAS --" << std::endl;
		dog.printIdeas();

		std::cout << std::endl << "-- DOG COPY IDEAS --" << std::endl;
		dogCopy.printIdeas();

		std::cout << std::endl << "-- GET TYPE --" << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << dog.getType() << " " << std::endl;
		std::cout << dogCopy.getType() << " " << std::endl;
		
		std::cout << std::endl << "-- MAKE DOUND --" << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		dog.makeSound();
		dogCopy.makeSound();
		
		std::cout << std::endl << "-- DELETE OBJECTS --" << std::endl;
		delete i;
		delete j;
		delete meta;
	} */

	{
		std::cout << std::endl << "-- ARRAY TESTS --" << std::endl;
		std::cout << std::endl << "-- FILL ARRAY WHIT 50 DOGS AND 50 CATS --" << std::endl;
		const Animal* array[10];
		for (int i = 0; i < 10; i++)
		{
			if (i % 2 == 0)
				array[i] = new Dog();
			else
				array[i] = new Cat();
		}

		std::cout << std::endl << "-- ARRAY GET TYPE AND MAKE SOUNDS --" << std::endl;
		for (int i = 0; i < 10; i++)
		{
			std::cout << array[i]->getType() << std::endl;
			array[i]->makeSound();
		}

		std::cout << std::endl << "-- DELETE ALL OBJECTS --" << std::endl;
		for (int i = 0; i < 10; i++)
			delete array[i];
	}

	return 0;
}