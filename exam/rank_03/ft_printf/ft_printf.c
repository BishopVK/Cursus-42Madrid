/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.e      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:43:25 by danjimen          #+#    #+#             */
/*   Updated: 2024/09/10 15:52:50 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	putstr(char *str, int i)
{
	if (str == NULL)
		return (putstr("(null)", i));
	if (str[i] == '\0')
		return (i);
	write(1, &str[i], 1);
	return (putstr(str, i + 1));
}

int	main(void)
{
	char	*str = "Hola!";

	return (putstr(str, 0));
}

