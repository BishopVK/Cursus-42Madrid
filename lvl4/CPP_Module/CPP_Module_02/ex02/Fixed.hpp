/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:45:17 by danjimen          #+#    #+#             */
/*   Updated: 2025/03/21 03:14:09 by danjimen         ###   ########.fr       */
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
		~Fixed(); // Destructor

		// COMPARISON OPERATORS
		Fixed	&operator=(const Fixed &other); // Assignment Operator Overload
		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;

		// ARITHMETIC OPERATORS
		Fixed	operator+(const Fixed &other);
		Fixed	operator-(const Fixed &other);
		Fixed	operator*(const Fixed &other);
		Fixed	operator/(const Fixed &other);

		// INCREMENT/DECREMENT OPERATORS
		Fixed	&operator++(void);	//++a
		Fixed	operator++(int);	//a++
		Fixed	&operator--(void);	//--a
		Fixed	operator--(int);	//a--

		int		getRawBits( void ) const; // Returns Raw Value of the Fixed-Point Value
		void	setRawBits ( int const raw ); // Sets the Raw Value of the Fixed-Point Number
		float	toFloat( void ) const; // Converts the fixed-point value to a floating-point value
		int		toInt( void ) const; // Converts the fixed-point value to an integer value

		// OVERLOADED FUNCTIONS
		static Fixed	&min(Fixed &, Fixed &); // Returns smallest
		static const Fixed	&min(const Fixed &, const Fixed &); // Returns const smallest
		static Fixed	&max(Fixed &, Fixed &); // Returns greatest
		static const Fixed	&max(const Fixed &, const Fixed &); // Returns const greatest
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif