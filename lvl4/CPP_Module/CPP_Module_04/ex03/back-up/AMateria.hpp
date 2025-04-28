/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 01:25:33 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/25 15:40:51 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string>
#include <list>
#include "ICharacter.hpp"

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

class ICharacter; // Forward declaration

class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria();
		AMateria(const std::string &type);
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		virtual ~AMateria();
		
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

		virtual bool is_dynamic() const;
};

#endif