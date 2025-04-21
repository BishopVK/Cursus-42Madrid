/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:57:06 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/21 12:35:30 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
#include <sstream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"
#define BOLD_OFF "\033[22m"
#define RESET "\033[0m"

class Zombie
{
	private:
		std::string	_name;

	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);

		void	announce(void);
		void	set_name(std::string name);
};

Zombie*	zombieHorde( int N, std::string name );

#endif