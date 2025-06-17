/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 10:11:51 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/15 10:39:24 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>

class Warlock
{
	private:
		std::string	_name;
		std::string	_title;

		Warlock();
		Warlock(const Warlock &other);
		Warlock &operator=(const Warlock &other);

	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();

		std::string const &getName() const;
		std::string const &getTitle() const;

		void	setTitle(const std::string &title);

		void	introduce() const;

};

#endif