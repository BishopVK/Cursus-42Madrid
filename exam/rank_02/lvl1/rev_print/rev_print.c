/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:38:06 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/28 11:45:33 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	char	*str;
	int		str_len;

	if (argc == 2)
	{
		str = argv[1];
		str_len = ft_strlen(str) - 1;
		while (str_len >= 0)
		{
			write(1, &str[str_len], 1);
			str_len--;
		}
	}
	write (1, "\n", 1);
	return (0);
}