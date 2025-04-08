/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:49:36 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/08 22:44:30 by danjimen         ###   ########.fr       */
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
		AForm(const Form &other);
		AForm &operator=(const AForm &other);
		friend std::ostream	&operator<<(std::ostream &os, const AForm &object); // Friend function so you can have access to private members
		~AForm();

		const std::string	getName() const;
		bool				getSigned() const;
		const int			getGradeSing() const;
		const int			getGradeExecute() const;

		void	beSigned(const Bureaucrat &b);
	
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const noexcept override
				{
					return ("Exception: Grade too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const noexcept override
				{
					return ("Exception: Grade too low");
				}
		};
};

#endif