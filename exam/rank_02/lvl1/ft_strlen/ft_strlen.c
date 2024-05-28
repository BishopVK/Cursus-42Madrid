/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:58:33 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/28 11:02:52 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* #include <stdio.h>

int	main(void)
{
	char	*str = "Hola mundo!";
	int		str_len;

	str_len = ft_strlen(str);
	printf("'%s' len = %i\n", str, str_len);
	return (0);
} */