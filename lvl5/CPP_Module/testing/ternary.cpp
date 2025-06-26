/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ternary.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen,isainz-r,serferna <webserv@stu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:07:32 by danjimen,is       #+#    #+#             */
/*   Updated: 2025/06/26 23:13:47 by danjimen,is      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	int			a = 42;
	std::string	str = "TXT";
	bool		trueBool = true;
	bool		falseBool = false;

	std::cout << "int a = " << a << std::endl
	<< "string str = " << str << std::endl
	<< "bool trueBool = " << (trueBool ? std::string("true") : std::string("false")) << std::endl
	<< "bool falseBool = " << (falseBool ? std::string("true") : std::string("false")) << std::endl;

	return 0;
}
