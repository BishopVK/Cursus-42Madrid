/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 00:31:50 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/16 10:57:40 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "AForm.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"
#define BOLD_OFF "\033[22m"
#define ITALIC "\033[3m"
#define RESET "\033[0m"

class AForm;

class Bureaucrat
{
	private:
		std::string	_name;
		int			_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, const int &grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat		&operator=(const Bureaucrat &other);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();

		void		signForm(AForm &f);
		void		executeForm(AForm const & form);

		// EXTRA
		void		setName(const std::string &newName);
		void		setGrade(int newGrade);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Exception: Bureaucrat of too high a level");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Exception: Bureaucrat of too low a level");
				}
		};
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &object);

#endif