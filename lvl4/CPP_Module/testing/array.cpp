/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 23:34:05 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/30 18:29:33 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define SIZEOF(x) (sizeof(x) / sizeof(x[0]))

class Test
{
	private:
		std::string	_name;
		int			age;
	public:
		std::string	getName() const;
		int			getAge() const;
};

int main()
{
	{
		std::cout << std::endl << "-- TEST 1 --" << std::endl;
		int	array[15];
		Test	array2[9];
		int	array3[] = {10, 17, 2, -5, 44};

		int	size1 = sizeof(array) / sizeof(array[0]);
		std::cout << "int array len: " << size1 << std::endl;
		int	size2 = sizeof(array2) / sizeof(array2[0]);
		std::cout << "int array len: " << size2 << std::endl;
		int	size3 = sizeof(array3) / sizeof(array3[0]);
		std::cout << "int array len: " << size3 << std::endl;
	}

	{
		std::cout << std::endl << "-- TEST 2 --" << std::endl;
		int	array[15];
		Test	array2[9];
		int	array3[] = {10, 17, 2, -5, 44};

		std::cout << "int array len: " << SIZEOF(array) << std::endl;
		std::cout << "int array len: " << SIZEOF(array2) << std::endl;
		std::cout << "int array len: " << SIZEOF(array3) << std::endl;
	}

	return 0;
}
