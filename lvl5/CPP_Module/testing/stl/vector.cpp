/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:03:45 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/01 21:19:21 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

// vector<T>
// - Similar a un array dinámico.
// - Acceso rápido por índice (O(1)).
// - Inserción/eliminación al final eficiente (O(1) amortizado), pero lenta en medio/inicio.
// - Requiere reallocaciones internas si se expande.

int	main(void)
{
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);

	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << "vec[" << i << "] = " << vec[i] << std::endl;
	}

	return 0;
}
