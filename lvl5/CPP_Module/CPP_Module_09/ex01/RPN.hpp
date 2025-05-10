/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 23:17:02 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/10 22:43:05 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stdlib.h> // EXIT_FAILURE
#include <stack>
#include <sstream> // stringstream
#include <climits>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

int	RPN(const std::string &input);

#endif