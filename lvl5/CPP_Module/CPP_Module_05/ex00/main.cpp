/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 00:31:12 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/07 02:52:12 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	{
		std::cout << std::endl << YELLOW << "-- EXAMPLE 1 --" << RESET << std::endl;
		try
		{
			Bureaucrat	Hermes("Hermes Conrad", 34);
			std::cout << Hermes << std::endl;
			Hermes.incrementGrade();
			std::cout << Hermes << std::endl;
			Hermes.decrementGrade();
			std::cout << Hermes << std::endl;
			Hermes.setGrade(1);
			std::cout << Hermes << std::endl;
			Hermes.incrementGrade();
			std::cout << Hermes << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl << YELLOW << "-- EXAMPLE 2 --" << RESET << std::endl;
		try
		{
			Bureaucrat	Hermes("Hermes Conrad", 34);
			std::cout << Hermes << std::endl;
			Hermes.setGrade(149);
			std::cout << Hermes << std::endl;
			Hermes.decrementGrade();
			std::cout << Hermes << std::endl;
			Hermes.decrementGrade();
			std::cout << Hermes << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl << YELLOW << "-- EXAMPLE 3 --" << RESET << std::endl;
		try
		{
			Bureaucrat	god("God", 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		
		try
		{
			Bureaucrat	looser("Looser", 250);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		
		try
		{
			Bureaucrat	unnamed;
			std::cout << unnamed << std::endl;
			unnamed.decrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}