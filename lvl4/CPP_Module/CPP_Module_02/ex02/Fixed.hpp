/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:45:17 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/20 01:49:45 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <math.h> 

class Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits = 8;

	public:
		Fixed(); // Default Constructor
		Fixed(const Fixed &other); // Copy Constructor
		Fixed(const int);
		Fixed(const float);
		Fixed &operator=(const Fixed &other); // Assignment Operator Overload
		~Fixed(); // Destructor

		int		getRawBits( void ) const; // Returns Raw Value of the Fixed-Point Value
		void	setRawBits ( int const raw ); // Sets the Raw Value of the Fixed-Point Number
		float	toFloat( void ) const; // Converts the fixed-point value to a floating-point value
		int		toInt( void ) const; // Converts the fixed-point value to an integer value
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif