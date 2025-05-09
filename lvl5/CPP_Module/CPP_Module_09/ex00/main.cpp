/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:38:16 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/09 23:14:27 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	check_args(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cerr << RED "Error: Wrong use." RESET << std::endl;
		return EXIT_FAILURE;
	}

	std::ifstream	infile;
	infile.open(argv[1]);
	if (!infile)
	{
		std::cerr << RED "Error: could not open input file." RESET << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

int main(int argc, char const *argv[])
{
	if (check_args(argc, argv) == EXIT_FAILURE)
		return EXIT_FAILURE;
	if (exchange(argv[1]) == EXIT_FAILURE)
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

