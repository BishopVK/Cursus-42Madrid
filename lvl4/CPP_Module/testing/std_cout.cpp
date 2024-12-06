/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_cout.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:57:21 by danjimen          #+#    #+#             */
/*   Updated: 2024/12/06 12:10:10 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string	buff;

	std::cout << "Hello World !" << std::endl;

	std::cout << "Input a word: ";
	std::cin >> buff;
	std::cout << "You entered: [" << buff << "]" << std::endl;
	std::cout << "You entered: " << buff << std::endl;

	return (0);
}