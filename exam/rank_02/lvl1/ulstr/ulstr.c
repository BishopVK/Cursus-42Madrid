/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:00:37 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/28 13:09:27 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	ft_switch(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int main(int argc, char **argv)
{
	int		i;
	char	*str;
	char	character;

	if (argc == 2)
	{
		str = argv[1];
		i = 0;
		while (str[i])
		{
			character = ft_switch(str[i]);
			write(1, &character, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
