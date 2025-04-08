/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 00:31:12 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/09 01:16:55 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	{
		std::cout << std::endl << YELLOW << "-- EXAMPLE 1 --" << RESET << std::endl;
		try
		{
			Bureaucrat	hermes("Hermes Conrad", 34);
			std::cout << hermes << std::endl;
			ShrubberyCreationForm form("prueba");
			std::cout << form << std::endl;
			hermes.executeForm(form);
			hermes.signForm(form);
			std::cout << form << std::endl;
			hermes.executeForm(form);
			hermes.signForm(form);
			std::cout << form << std::endl;
			hermes.executeForm(form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}