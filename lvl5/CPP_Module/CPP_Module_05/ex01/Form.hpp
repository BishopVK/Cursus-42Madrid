/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:49:36 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/21 23:41:33 by danjimen         ###   ########.fr       */
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
		friend std::ostream	&operator<<(std::ostream &os, const Form &object); // Friend function so you can have access to private members
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

#endif