/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 09:45:57 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/13 08:25:12 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <stdlib.h> // atoi
#include <sstream>
#include <climits> // INT_MAX
#include <time.h> // clock()


#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

void	PmergeMe(char const *argv[]);

#endif