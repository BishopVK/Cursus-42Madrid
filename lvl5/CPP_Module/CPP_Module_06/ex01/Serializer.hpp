/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 22:47:37 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/23 00:25:23 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include "Data.hpp"

#define RED	"\033[31m"
#define GREEN "\033[32m"
#define YELLOW	"\033[33m"
#define RESET "\033[0m"

typedef	size_t	uintptr_t;

class Serializer
{
	private:
		Serializer();
		
	public:
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		~Serializer();

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
