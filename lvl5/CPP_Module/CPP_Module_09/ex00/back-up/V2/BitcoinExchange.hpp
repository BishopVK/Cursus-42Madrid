/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:38:11 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/08 22:22:28 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream> // std::ifstream, open()
#include <stdlib.h> // EXIT_FAILURE
#include <climits>
#include <map>
#include <iomanip>
#include <cmath> // std::isnan(), NAN

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

#define DATA_CSV "./cpp_09/data.csv"

int	exchange(const std::string &infile);

#endif