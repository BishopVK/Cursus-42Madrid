/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 23:34:05 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/29 01:31:05 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

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
	int	array[15];
	Test	array2[9];
	int	array3[] = {10, 17, 2, -5, 44};

	int	size1 = sizeof(array) / sizeof(array[0]);
	std::cout << "int array len: " << size1 << std::endl;
	int	size2 = sizeof(array2) / sizeof(array2[0]);
	std::cout << "int array len: " << size2 << std::endl;
	int	size3 = sizeof(array3) / sizeof(array3[0]);
	std::cout << "int array len: " << size3 << std::endl;
	return 0;
}
