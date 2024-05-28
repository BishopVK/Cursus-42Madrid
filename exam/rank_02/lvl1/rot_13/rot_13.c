/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:46:36 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/28 12:25:53 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*str;
	int		i;
	int		char_nbr;
	char	character;

	if (argc == 2)
	{
		str = argv[1];
		i = 0;
		while (str[i])
		{
			char_nbr = str[i] - 13;
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				if (char_nbr < 97)
				{
					character = str[i] + 13;
					write(1, &character, 1);
				}
				else
				{
					character = str[i] - 13;
					write(1, &character, 1);
				}
			}
			else if (str[i] >= 'A' && str[i] <= 'Z')
			{
				if (char_nbr < 65)
				{
					character = str[i] + 13;
					write(1, &character, 1);
				}
				else
				{
					character = str[i] - 13;
					write(1, &character, 1);
				}
			}
			else
				write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
