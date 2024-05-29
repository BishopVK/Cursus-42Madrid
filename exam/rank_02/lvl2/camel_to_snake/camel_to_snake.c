/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:25:38 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/29 10:32:41 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int		i;
	char	character;

	i = 0;
	while (str[i])
	{
		character = str[i];
		if (character >= 'A' && character <= 'Z')
		{
			character += 32;
		}
		write(1, &character, 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_count_words(char *str)
{
	int	uppers;
	int	i;

	uppers = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			uppers++;
		i++;
	}
	return (uppers);
}

int	main(int argc, char **argv)
{
	char	*str;
	int		i;
	int		uppers;
	char	*dst;
	int		j;

	if (argc == 2)
	{
		str = argv[1];
		if (ft_strlen(str) <= 1)
			return (0);
		uppers = ft_count_words(str);
		dst = (char *)malloc(ft_strlen(str) + uppers + 1);
		i = 0;
		j = 0;
		while (str[i])
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				dst[j] = '_';
				j++;
			}
			dst[j] = str[i];
			i++;
			j++;
		}
		dst[j] = '\0';
		ft_putstr(dst);
		write(1, "\n", 1);
		free(dst);
	}
	return (0);
}
