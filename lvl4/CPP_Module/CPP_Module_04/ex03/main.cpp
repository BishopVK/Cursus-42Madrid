/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 02:08:45 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/24 02:28:35 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
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

	return 0;
}
