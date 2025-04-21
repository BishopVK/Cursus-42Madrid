/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:40:18 by danjimen          #+#    #+#             */
/*   Updated: 2025/04/21 21:00:53 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define BOLD "\033[1m"
# define BOLD_OFF "\033[22m"
# define ITALIC "\033[3m"
# define RESET "\033[0m"

class Point
{
	private:
		Fixed	_x;
		Fixed	_y;

	public:
		Point();
		Point(const Fixed &x, const Fixed &y);
		Point(const Point &other);
		Point &operator=(const Point &other);
		~Point();

		Fixed	getX() const;
		Fixed	getY() const;
	};
	
bool	bsp(const Point &a, const Point &b, const Point &c, const Point &point);

#endif