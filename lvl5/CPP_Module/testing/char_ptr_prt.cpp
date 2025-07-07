/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_ptr_prt.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen,isainz-r,serferna <webserv@stu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:39:31 by danjimen,is       #+#    #+#             */
/*   Updated: 2025/07/07 11:02:04 by danjimen,is      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <string.h>

int main()
{
	{
		std::cout << ">> TEST 1 <<" << std::endl;
		std::vector<std::string> vector;

		vector.push_back("hola");
		vector.push_back("adios");
		vector.push_back("que");
		vector.push_back("tal");
		vector.push_back("estas");

		char** ptr_ptr = new char*[vector.size() + 1];
		ptr_ptr[vector.size()] = NULL;

		for (int i = 0; i < vector.size(); ++i)
		{
			int	size = vector[i].length() + 1;
			char* str = new char[size];
			strcpy(str, const_cast<char*>(vector.at(i).c_str()));
			ptr_ptr[i] = str;
		}

		int i = 0;
		while (ptr_ptr[i])
		{
			std::cout << ptr_ptr[i] << std::endl;
			delete[] ptr_ptr[i];
			i++;
		}

		delete[] ptr_ptr;
	}

	{
		std::cout << ">> TEST 2 <<" << std::endl;
		std::vector<std::string> vector;

		vector.push_back("hola");
		vector.push_back("adios");
		vector.push_back("que");
		vector.push_back("tal");
		vector.push_back("estas");

		char** ptr_ptr = new char*[vector.size() + 1];
		ptr_ptr[vector.size()] = NULL;

		for (int i = 0; i < vector.size(); ++i)
		{
			ptr_ptr[i] = const_cast<char*>(vector.at(i).c_str());
		}

		int i = 0;
		while (ptr_ptr[i])
		{
			std::cout << ptr_ptr[i] << std::endl;
			i++;
		}

		delete[] ptr_ptr;
	}
	
	return 0;
}
