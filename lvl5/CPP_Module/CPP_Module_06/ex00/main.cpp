/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 08:57:48 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/16 22:51:40 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << RED << "Error: Incorrect use." << std::endl
		<< RESET << "Correct usage: " << argv[0] << " parameter"<< std::endl;
		return -1;
	}
	std::cout << GREEN << "CORRECT! 😉" << std::endl; // DB
	ScalarConverter::convert(argv[1]);
	return 0;
}