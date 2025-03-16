/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:41:40 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/16 21:11:44 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"
#define BOLD_OFF "\033[22m"
#define RESET "\033[0m"

class Weapon
{
	private:
		std::string	_type;

	public:
		Weapon(const std::string &type); // Es una referencia constante para no duplicar el string recibido
		~Weapon();
		const std::string&	getType(void) const; // El retorno es una referencia constante al string interno. Const al final indica que este método no modificará el estado del objeto
		void				setType(const std::string &type); // Referencia constante por eficiencia
};

#endif