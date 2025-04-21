/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:49:36 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/21 23:45:08 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExecute;

	public:
		AForm();
		AForm(const std::string &name, const int gradeSign, const int gradeExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		friend std::ostream	&operator<<(std::ostream &os, const AForm &object); // Friend function so you can have access to private members
		virtual ~AForm(); // Abstract class must hace virtual destructor

		virtual void	print(std::ostream &os) const;
		void			execute(Bureaucrat const & executor) const;
		virtual void	executeAction(Bureaucrat const & executor) const = 0; // Pure abstract to override

		const std::string	getName() const;
		bool				getSigned() const;
		int					getGradeSing() const;
		int					getGradeExecute() const;
		void				setSigned(bool value);

		void	beSigned(const Bureaucrat &b);
	
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Exception: Grade too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Exception: Grade too low");
				}
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Exception: Form is not signed");
				}
		};
};

#endif