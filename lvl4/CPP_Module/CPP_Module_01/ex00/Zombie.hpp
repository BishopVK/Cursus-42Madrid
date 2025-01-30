/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:57:06 by danjimen          #+#    #+#             */
/*   Updated: 2025/01/30 18:51:51 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif