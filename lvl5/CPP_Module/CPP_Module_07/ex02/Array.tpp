/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:20:24 by danjimen          #+#    #+#             */
/*   Updated: 2025/06/04 08:31:54 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : _ptr(NULL), _size(0)
{
	std::cout << GREEN "Array Empty constructor called" RESET << std::endl;
}

template <typename T>
Array<T>::Array(const unsigned int &n)
{
	std::cout << GREEN "Array n defined constructor called" RESET << std::endl;
	if (n > MAX_SIZE)
		throw std::length_error("Array size to large");
	this->_ptr = (new T[n]());
	this->_size = n;
}

template <typename T>
Array<T>::Array(const Array &other) : _ptr(NULL), _size(0)
{
	std::cout << GREEN "Array Copy constructor called" RESET << std::endl;
	*this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	std::cout << GREEN "Array Copy Assignment constructor called" RESET << std::endl;
	if (this != &other)
	{
		delete[] this->_ptr;
		this->_size = other.size();
		this->_ptr = new T[this->_size]();
		for (unsigned int i = 0; i < this->_size; i++)
			this->_ptr[i] = other._ptr[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	std::cout << RED "Array Destructor called" RESET << std::endl;
	if (_ptr)
		delete[] this->_ptr;
}

template <typename T>
T	&Array<T>::operator[](unsigned int n)
{
	if (n >= this->_size)
		throw Array<T>::OutOfBoundsException();
	else
		return this->_ptr[n];
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return this->_size;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return "Index out of bounds";
}