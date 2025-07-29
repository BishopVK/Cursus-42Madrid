/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen,isainz-r,serferna <webserv@stu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:40:29 by danjimen          #+#    #+#             */
/*   Updated: 2025/07/28 09:17:49 by danjimen,is      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
	protected:
		std::string	_ideas[100];

	public:
		Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain();

		void	setIdeas(const std::string &idea);
		void	printIdeas() const;
};

#endif