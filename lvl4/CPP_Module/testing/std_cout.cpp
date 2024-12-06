/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_cout.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:57:21 by danjimen          #+#    #+#             */
/*   Updated: 2024/12/06 14:11:32 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string	buff;

	std::cout << "Hello World !" << std::endl;

	std::cout << "Input a word: ";
	//std::cin >> buff; // Recibe una palabra
	std::getline(std::cin, buff); // Recibe una string, incluyendo espacios, hasta detectar un salto de línea
	std::cout << "You entered: [" << buff << "]" << std::endl;
	std::cout << "You entered: " << buff << std::endl;

	return (0);
}