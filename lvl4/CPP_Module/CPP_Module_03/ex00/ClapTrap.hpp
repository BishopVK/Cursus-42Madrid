/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:18:58 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/21 21:11:24 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

#define BOLD "\033[1m"
#define BOLD_OFF "\033[22m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"
#define INVERT "\033[7m"

class ClapTrap
{
	private:
		std::string _name;
		int			_hitPoints;
		int			_energy;
		int			_attack;

	public:
		ClapTrap();
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();

		std::string		getName() const;
		unsigned int	getHitPoints() const;
		unsigned int	getEnergy() const;
		unsigned int	getAttack() const;
		void			setName(const std::string &name);
		void			setHitPoints(const unsigned int &amount);
		void			setEnergy(const unsigned int &amount);
		void			setAttack(const unsigned int &amount);
		void			printStats() const;

		// REQUIRED
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif