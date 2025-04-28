/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 01:48:26 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/11 01:31:02 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	private:
		//std::string	_type;
	public:
		Cure();
		Cure(const std::string &type);
		Cure(const Cure &other);
		Cure &operator=(const Cure &other);
		~Cure();
		
		AMateria* clone() const;
		void use(ICharacter& target);

		bool is_dynamic() const;
};

#endif