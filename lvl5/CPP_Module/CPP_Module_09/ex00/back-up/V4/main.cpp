/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:38:16 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/06 00:32:11 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2) {
		std::cerr << "Usage: ./btc <input_file>\n";
		return 1;
	}

	try {
		BitcoinExchange btc("data.csv");
		btc.processInputFile(argv[1]);
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
		return 1;
	}

	return 0;
}

