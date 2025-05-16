/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:49:36 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/16 09:59:54 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExecute;

	public:
		Form();
		Form(const std::string &name, const int gradeSign, const int gradeExecute);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		const std::string	getName() const;
		bool				getSigned() const;
		int					getGradeSing() const;
		int					getGradeExecute() const;

		void	beSigned(const Bureaucrat &b);
	
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Exception: Grade too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Exception: Grade too low");
				}
		};
};

std::ostream	&operator<<(std::ostream &os, const Form &object);

#endif