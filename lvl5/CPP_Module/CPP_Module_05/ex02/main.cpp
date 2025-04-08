/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 00:31:12 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/08 01:04:04 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	{
		std::cout << std::endl << YELLOW << "-- EXAMPLE 1 --" << RESET << std::endl;
		try
		{
			Bureaucrat	hermes("Hermes Conrad", 34);
			std::cout << hermes << std::endl;
			Form	form("WowForm", 35, 100);
			std::cout << form << std::endl;
			hermes.signForm(form);
			std::cout << form << std::endl;
			hermes.signForm(form);
			std::cout << form << std::endl;
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
			Bureaucrat	hermes("Hermes Conrad", 34);
			std::cout << hermes << std::endl;
			hermes.decrementGrade();
			hermes.decrementGrade();
			hermes.decrementGrade();
			Form	form("WowForm", 35, 100);
			std::cout << form << std::endl;
			hermes.signForm(form);
			std::cout << form << std::endl;
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
			Bureaucrat	hermes;
			std::cout << hermes << std::endl;
			Form	form;
			std::cout << form << std::endl;
			hermes.signForm(form);
			std::cout << form << std::endl;
			hermes.decrementGrade();
			std::cout << hermes << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}