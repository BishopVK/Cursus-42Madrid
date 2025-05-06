/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:38:11 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/06 12:27:27 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream> // std::ifstream, open()
#include <stdlib.h> // EXIT_FAILURE
#include <limits.h>
#include <map>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

#define DATA_CSV "./cpp_09/data.csv"

int	exchange(const std::string &infile);

#endif