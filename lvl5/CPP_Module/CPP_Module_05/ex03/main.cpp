/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 00:31:12 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/12 00:34:21 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	{
		std::cout << std::endl << YELLOW << "-- EXAMPLE 1 --" << RESET << std::endl;

		AForm	*shrubbery = NULL;
		AForm	*robotomy = NULL;
		AForm	*presidential = NULL;
		AForm	*random = NULL;

		try
		{
			std::cout << std::endl << CYAN << "-- CONSTRUCTORS --" << RESET << std::endl;
			Bureaucrat	bender("Bender", 1);
			std::cout << bender << std::endl;
			Intern	someRandomIntern;

			shrubbery = someRandomIntern.makeForm("shrubbery creation", "Bender");
			std::cout << *shrubbery << std::endl;

			robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
			std::cout << *robotomy << std::endl;

			presidential = someRandomIntern.makeForm("presidential pardon", "Bender");
			std::cout << *presidential << std::endl;

			std::cout << std::endl << CYAN << "-- TRYING TO SIGN FORMS --" << RESET << std::endl;
			bender.signForm(*shrubbery);
			std::cout << *shrubbery << std::endl;
			bender.signForm(*robotomy);
			std::cout << *robotomy << std::endl;
			bender.signForm(*presidential);
			std::cout << *presidential << std::endl;

			std::cout << std::endl << CYAN << "-- TRYING TO EXECUTE FORM --" << RESET << std::endl;
			bender.executeForm(*shrubbery);
			bender.executeForm(*robotomy);
			bender.executeForm(*presidential);

			std::cout << std::endl << CYAN << "-- TRYING TO CREATE A NON-EXISTENT FORM --" << RESET << std::endl;
			random = someRandomIntern.makeForm("random form", "Bender");
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			if (shrubbery)
				delete shrubbery;
			if (robotomy)
				delete robotomy;
			if (presidential)
				delete presidential;
			if (random)
				delete random;
			return 1;
		}

		std::cout << std::endl << CYAN << "-- DELETING POINTERS --" << RESET << std::endl;
		delete shrubbery;
		delete robotomy;
		delete presidential;
		delete random;
	}

	return 0;
}