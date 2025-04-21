/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:45:17 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/21 20:00:25 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define RESET "\033[0m"

class Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits = 8;

	public:
		Fixed(); // Default Constructor
		Fixed(const Fixed &other); // Copy Constructor
		Fixed &operator=(const Fixed &other); // Assignment Operator Overload
		~Fixed(); // Destructor

		int		getRawBits( void ) const; // Returns Raw Value of the Fixed-Point Value
		void	setRawBits ( int const raw ); // Sets the Raw Value of the Fixed-Point Number
};

#endif