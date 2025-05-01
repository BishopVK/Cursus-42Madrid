/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 23:08:40 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/01 23:09:34 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
	std::vector<int> v;
	v.push_back(3);
	v.push_back(1);
	v.push_back(2);
	v.push_back(1);

	int cantidad = std::count(v.begin(), v.end(), 1);
	std::cout << "Número de veces que aparece 1: " << cantidad << std::endl;

	return 0;
}