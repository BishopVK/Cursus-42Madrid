/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:13:03 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/19 02:06:07 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cerr << RED << "Incorrect number of parameters" << std::endl;
		std::cerr << "Correct use: " << argv[0] << " 'DEBUG/INFO/WARNING/ERROR'" << std::endl;
		std::cerr << "Exiting..." << RESET << std::endl;
		return 1;
	}
	harl_filter(argv[1]);
	return 0;
}
