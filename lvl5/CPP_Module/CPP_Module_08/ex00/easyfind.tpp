/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 23:39:06 by danjimen          #+#    #+#             */
/*   Updated: 2025/05/02 00:45:49 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void	easyfind(const T &cont, const int &n)
{
	if (cont.size() == 0)
		throw EmptyContainerException();
	typename T::const_iterator it = std::find(cont.begin(), cont.end(), n);
	if (it != cont.end())
		std::cout << GREEN << n << " found in the container" << RESET << std::endl;
	else
		throw NotFoundException();
}



const char* EmptyContainerException::what() const throw()
{
	return "The container is empty ⚠️";
}

const char* NotFoundException::what() const throw()
{
	return "Number not found in the container ❌";
}