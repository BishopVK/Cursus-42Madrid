/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:29:01 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/29 14:56:55 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	char	tmp;
	int		str_len;
	int		times;
	int		i;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	times = str_len / 2;
	i = 0;
	while (times > 0)
	{
		tmp = str[i];
		str[i] = str[str_len - 1 - i];
		str[str_len - 1 - i] = tmp;
		i++;
		times--;
	}
	return (str);
}

#include <stdio.h>

int	main(void)
{
	char	str[] = "Hola";

	printf("str before: %s\n", str);
	ft_strrev(str);
	printf("str after: %s\n", str);
	return (0);
}