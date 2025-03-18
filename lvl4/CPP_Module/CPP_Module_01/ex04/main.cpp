/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 00:59:53 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/18 14:34:07 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedIsForLosers.h"
#include "Replacer.hpp"

int	checkParameters(int argc, char const *argv[])
{
	if (argc != 4 || !*argv[2] || !*argv[3])
	{
		if (argc != 4)
		{
			std::cerr << RED << "Incorrect number of parameters." << std::endl;
			std::cerr << "Correct usage: " << argv[0] << " filename string_to_find string_to_replace" << RESET << std::endl;
		}
		else if (!*argv[2])
			std::cerr << RED << "string_to_find parameter couldn't be void" << RESET << std::endl;
		else
			std::cerr << RED << "string_to_replace parameter couldn't be void" << RESET << std::endl;
		std::cerr << RED << "Exiting..." << RESET << std::endl;
		return -1;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	if (checkParameters(argc, argv))
		return -1;
	Replacer	replace(argv[1], argv[2], argv[3]);
	replace.setReplacedFileName(argv[1], ".replace");
	/* std::cout << "Original file name: " << replace.getFileName() << std::endl;
	std::cout << "String to find: " << replace.getStringToFind() << std::endl;
	std::cout << "String to replace: " << replace.getStringToReplace() << std::endl;
	std::cout << "Output file name: " << replace.getReplacedFileName() << std::endl; */
	replace.create_Outfile();
	std::cout << GREEN << "Replacement performed correctly! 😉" << RESET << std::endl;
	
	return 0;
}
