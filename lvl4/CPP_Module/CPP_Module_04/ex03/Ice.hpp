/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 01:48:26 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/24 02:18:04 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		//std::string	_type;
	public:
		Ice();
		Ice(const std::string &type);
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);
		~Ice();
		
		AMateria* clone() const override;
		//virtual void use(ICharacter& target);
};

#endif