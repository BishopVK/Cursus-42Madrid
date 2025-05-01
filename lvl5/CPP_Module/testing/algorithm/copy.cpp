/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:29:03 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/01 23:11:51 by danjimen         ###   ########.fr       */
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

	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << "v[" << i << "] = " << v[i] << std::endl;
	}

	std::vector<int> destino(v.size());
	std::copy(v.begin(), v.end(), destino.begin());
	for (size_t i = 0; i < destino.size(); ++i) {
		std::cout << "v[" << i << "] = " << destino[i] << std::endl;
	}

	return 0;
}