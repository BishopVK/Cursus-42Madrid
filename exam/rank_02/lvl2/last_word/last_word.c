/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:27:37 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/29 19:51:35 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	last_word(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (str[i] >= 9 && str[i] <= 32 && i)
		i--;
	while (str[i] > 32 && i)
		i--;
	i++;
	while (str[i] > 32 && str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		last_word(argv[1]);
	}
	write (1, "\n", 1);
	return (0);
}