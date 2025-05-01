/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_and_find.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:29:03 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/01 23:08:13 by danjimen         ###   ########.fr       */
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

	std::sort(v.begin(), v.end()); // Ordena el vector
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << "v[" << i << "] = " << v[i] << std::endl;
	}

	std::vector<int>::iterator it = std::find(v.begin(), v.end(), 2);
	if (it != v.end())
		std::cout << "Encontrado: " << *it << std::endl;
	else
		std::cout << "No entcontrado" << std::endl;


	return 0;
}