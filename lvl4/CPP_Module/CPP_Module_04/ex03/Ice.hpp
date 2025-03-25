/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 01:48:26 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/25 02:16:46 by danjimen         ###   ########.fr       */
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
		void use(ICharacter& target);

		bool is_dynamic() const;
};

#endif