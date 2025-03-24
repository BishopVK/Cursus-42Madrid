/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 01:48:26 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/24 02:15:45 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

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
		
		AMateria* clone() const override;
		//virtual void use(ICharacter& target);
};

#endif