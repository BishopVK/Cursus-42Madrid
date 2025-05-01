/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:29:03 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/01 23:21:59 by danjimen         ###   ########.fr       */
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

	// NO borra elementos, solo los mueve al final y devuelve nuevo fin lógico
	// remove() no cambian el tamaño del contenedor. Debes usar erase manualmente si quieres acortar el contenedor.
	std::vector<int>::iterator nuevo_fin = std::remove(v.begin(), v.end(), 2);
	std::cout << *nuevo_fin << std::endl;

	v.erase(nuevo_fin, v.end()); // Borra físicamente los elementos movidos

	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << "v[" << i << "] = " << v[i] << std::endl;
	}

	v.erase(v.begin(), v.end());

	if (v.size() != 0)
	{
		for (size_t i = 0; i < v.size(); ++i) {
			std::cout << "v[" << i << "] = " << v[i] << std::endl;
		}
	}
	else
		std::cout << "v is empty" << std::endl;

	return 0;
}