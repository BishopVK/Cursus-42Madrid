/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ternary.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen,isainz-r,serferna <webserv@stu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:07:32 by danjimen,is       #+#    #+#             */
/*   Updated: 2025/07/17 02:28:52 by danjimen,is      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int			a = 42;
	string		str = "TXT";
	bool		trueBool = true;
	bool		falseBool = false;

	cout << "int a = " << a << endl
	<< "string str = " << str << std::endl
	<< "bool trueBool = " << (trueBool ? std::string("true") : std::string("false")) << endl
	<< "bool falseBool = " << (falseBool ? std::string("true") : std::string("false")) << endl;

	return 0;
}
