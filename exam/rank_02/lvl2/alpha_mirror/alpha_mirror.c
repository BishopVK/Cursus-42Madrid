/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:51:27 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/29 09:24:17 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*str;
	int		i;
	int		char_value;
	char	character;

	if (argc == 2)
	{
		str = argv[1];
		i = 0;
		while (str[i])
		{
			char_value = str[i];
			if (str[i] >= 'A' && str[i] <= 'M')
			{
				char_value = 'Z' - (char_value - 'A');
				character = char_value;
				write(1, &character, 1);
			}
			else if (str[i] >= 'N' && str[i] <= 'Z')
			{
				char_value = 'A' + ('Z' - char_value);
				character = char_value;
				write(1, &character, 1);
			}
			else if (str[i] >= 'a' && str[i] <= 'm')
			{
				char_value = 'z' - (char_value - 'a');
				character = char_value;
				write(1, &character, 1);
			}
			else if (str[i] >= 'n' && str[i] <= 'z')
			{
				char_value = 'a' + ('z' - char_value);
				character = char_value;
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
