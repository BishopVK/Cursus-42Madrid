/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:13:30 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/19 02:03:06 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

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

class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		void	wrong(void);
		void	(Harl::*option[5])(void);
	public:
		Harl();
		~Harl();
		void	complain(const std::string &level);
	};

	void	harl_filter(const std::string &level);
	
#endif