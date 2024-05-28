/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:26:35 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/28 12:34:37 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	char	*str;
	int		i;
	//int		char_nbr;
	char	character;

	if (argc == 2)
	{
		str = argv[1];
		i = 0;
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				character = str[i] + 1;
				if (str[i] == 'z')
					write(1, "a", 1);
				else
					write(1, &character, 1);
			}
			else if (str[i] >= 'A' && str[i] <= 'Z')
			{
				character = str[i] + 1;
				if (str[i] == 'Z')
					write(1, "A", 1);
				else
					write(1, &character, 1);
			}
			else
				write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
