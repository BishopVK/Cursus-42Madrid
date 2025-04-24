/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:47:43 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/25 01:01:57 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

class Test
{
	private:
		int	_i;

	public:
		Test() : _i(0) {}
		void	setI(int i) {this->_i = i;}
		int		getI() const {return this->_i;}
};

std::ostream &operator<<(std::ostream &os, const Test &t)
{
	os << "Test (" << t.getI() << ")";
	return os;
}

void	upperCase(const std::string &str)
{
	char	c;
	for (size_t i = 0; i < str.length(); i++)
	{
		c = toupper(str[i]);
		std:: cout << "Element uppercase: " << YELLOW << c << RESET << std::endl;
	}
}

int main()
{
	int			intArr[] = {4, 8, 15, 16, 23, 42};
	char		charArr[] = {'a', 'b', 'c', 'd'};
	std::string	strArr[] = {"En", "un", "lugar", "de", "la", "mancha"};
	Test		testArr[3];
	for (int i = 0; i < 3; i++)
		testArr[i].setI(i + 40);

	std::cout << std::endl << YELLOW << "-- INT ARRAY --" << RESET << std::endl;
	iter(intArr, 6, printElement);

	std::cout << std::endl << YELLOW << "-- CHAR ARRAY --" << RESET << std::endl;
	iter(charArr, 4, printElement);

	std::cout << std::endl << YELLOW << "-- STRING ARRAY --" << RESET << std::endl;
	iter(strArr, 6, printElement);

	std::cout << std::endl << YELLOW << "-- STRING ARRAY UPPERCASE --" << RESET << std::endl;
	iter(strArr, 6, upperCase);

	std::cout << std::endl << YELLOW << "-- CLASS ARRAY --" << RESET << std::endl;
	iter(testArr, 3, printElement);

	return 0;
}
