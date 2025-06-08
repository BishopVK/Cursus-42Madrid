/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 09:48:45 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/15 01:39:22 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	check_args(int argc, char const *argv[])
{
	if (argc <= 1)
	{
		std::cerr << RED "Error: Wrong usage" RESET << std::endl;
		return EXIT_FAILURE;
	}
	for (int i = 1; i < argc; ++i)
	{
		for (long unsigned int j = 0; j < static_cast<std::string>(argv[i]).length(); ++j)
		{
			if (!isdigit(argv[i][j]))
			{
				std::cerr << RED "Error: '" << argv[i] << "' not a positive int" RESET << std::endl;
				return EXIT_FAILURE;
			}
		}
		long int nbr = atol(argv[i]);
		if (nbr > INT_MAX)
		{
			std::cerr << RED "Error: '" << argv[i] << "' int overflow" RESET << std::endl;
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}

int main(int argc, char const *argv[])
{
	if (check_args(argc, argv) == EXIT_FAILURE)
		return EXIT_FAILURE;
	PmergeMe(argv);
	return 0;
}
