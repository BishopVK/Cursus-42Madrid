/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:47:43 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/03 08:38:22 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int			intArr[] = {4, 8, 15, 16, 23, 42};
	char		charArr[] = {'a', 'b', 'c', 'd'};
	std::string	strArr[] = {"En", "un", "lugar", "de", "la", "mancha"};
	Test		testArr[3];
	for (int i = 0; i < 3; i++)
		testArr[i].setI(i + 40);

	std::cout << std::endl << YELLOW << "-- INT ARRAY --" << RESET << std::endl;
	iter(intArr, ARRAY_SIZE(intArr), printElement);

	std::cout << std::endl << YELLOW << "-- CHAR ARRAY --" << RESET << std::endl;
	iter(charArr, ARRAY_SIZE(charArr), printElement);

	std::cout << std::endl << YELLOW << "-- STRING ARRAY --" << RESET << std::endl;
	iter(strArr, ARRAY_SIZE(strArr), printElement);

	std::cout << std::endl << YELLOW << "-- STRING ARRAY UPPERCASE --" << RESET << std::endl;
	iter(strArr, ARRAY_SIZE(strArr), upperCase);

	std::cout << std::endl << YELLOW << "-- CLASS ARRAY --" << RESET << std::endl;
	iter(testArr, ARRAY_SIZE(testArr), printElement);

	return 0;
}
