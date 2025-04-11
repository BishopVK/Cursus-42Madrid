/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 00:31:12 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/11 00:49:09 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	{
		std::cout << std::endl << YELLOW << "-- EXAMPLE 1 --" << RESET << std::endl;
		try
		{
			std::cout << std::endl << CYAN << "-- CONSTRUCTORS --" << RESET << std::endl;
			Bureaucrat	low("Low", 150);
			std::cout << low << std::endl;
			Bureaucrat	signer("Signer", 145);
			std::cout << signer << std::endl;
			Bureaucrat	executor("Executor", 137);
			std::cout << executor << std::endl;
			Bureaucrat	high("High", 1);
			std::cout << high << std::endl;
			ShrubberyCreationForm test_1("Test_1");
			std::cout << test_1 << std::endl;
			ShrubberyCreationForm test_2("Test_2");
			std::cout << test_2 << std::endl;

			std::cout << std::endl << CYAN << "-- TRYING TO SIGN FORMS --" << RESET << std::endl;
			low.signForm(test_1);
			signer.signForm(test_1);
			std::cout << test_1 << std::endl;

			std::cout << std::endl << CYAN << "-- TRYING TO EXECUTE FORMS --" << RESET << std::endl;
			signer.executeForm(test_1);
			executor.executeForm(test_1);
			executor.executeForm(test_2);

			std::cout << std::endl << CYAN << "-- SIGN AND EXECUTE FORMS --" << RESET << std::endl;
			executor.signForm(test_2);
			std::cout << test_2 << std::endl;
			executor.executeForm(test_2);
			high.executeForm(test_1);
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
			std::cout << std::endl << CYAN << "-- CONSTRUCTORS --" << RESET << std::endl;
			Bureaucrat	low("Low", 150);
			std::cout << low << std::endl;
			Bureaucrat	signer("Signer", 72);
			std::cout << signer << std::endl;
			Bureaucrat	executor("Executor", 45);
			std::cout << executor << std::endl;
			Bureaucrat	high("High", 1);
			std::cout << high << std::endl;
			RobotomyRequestForm test_1("Test_1");
			std::cout << test_1 << std::endl;
			RobotomyRequestForm test_2("Test_2");
			std::cout << test_2 << std::endl;

			std::cout << std::endl << CYAN << "-- TRYING TO SIGN FORMS --" << RESET << std::endl;
			low.signForm(test_1);
			signer.signForm(test_1);
			std::cout << test_1 << std::endl;

			std::cout << std::endl << CYAN << "-- TRYING TO EXECUTE FORMS --" << RESET << std::endl;
			signer.executeForm(test_1);
			executor.executeForm(test_1);
			executor.executeForm(test_2);

			std::cout << std::endl << CYAN << "-- SIGN AND EXECUTE FORMS --" << RESET << std::endl;
			executor.signForm(test_2);
			std::cout << test_2 << std::endl;
			executor.executeForm(test_2);
			high.executeForm(test_1);
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
			std::cout << std::endl << CYAN << "-- CONSTRUCTORS --" << RESET << std::endl;
			Bureaucrat	low("Low", 150);
			std::cout << low << std::endl;
			Bureaucrat	signer("Signer", 25);
			std::cout << signer << std::endl;
			Bureaucrat	executor("Executor", 5);
			std::cout << executor << std::endl;
			Bureaucrat	high("High", 1);
			std::cout << high << std::endl;
			PresidentialPardonForm test_1("Test_1");
			std::cout << test_1 << std::endl;
			PresidentialPardonForm test_2("Test_2");
			std::cout << test_2 << std::endl;

			std::cout << std::endl << CYAN << "-- TRYING TO SIGN FORMS --" << RESET << std::endl;
			low.signForm(test_1);
			signer.signForm(test_1);
			std::cout << test_1 << std::endl;

			std::cout << std::endl << CYAN << "-- TRYING TO EXECUTE FORMS --" << RESET << std::endl;
			signer.executeForm(test_1);
			executor.executeForm(test_1);
			executor.executeForm(test_2);

			std::cout << std::endl << CYAN << "-- SIGN AND EXECUTE FORMS --" << RESET << std::endl;
			executor.signForm(test_2);
			std::cout << test_2 << std::endl;
			executor.executeForm(test_2);
			high.executeForm(test_1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}