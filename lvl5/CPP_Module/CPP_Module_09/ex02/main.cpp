/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 09:48:45 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/11 10:35:34 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char const *argv[])
{
	if (argc <= 1)
	{
		std::cerr << RED "Error: Wrong usage" RESET << std::endl;
		return EXIT_FAILURE;
	}
	for (int i = 1; i < argc; ++i)
	{
		for (int j = 0; j < static_cast<std::string>(argv[i]).length(); ++j)
		{
			if (!isdigit(argv[i][j]))
			{
				std::cerr << RED "Error: '" << argv[i] << "' not a positive int" RESET << std::endl;
				return EXIT_FAILURE;
			}
		}
	}
	std::cout << GREEN "allright!!" RESET << std::endl;
	return 0;
}
