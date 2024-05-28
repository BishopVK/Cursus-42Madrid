/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:09:05 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/28 11:37:06 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*str;
	int		char_value;
	int		i;
	
	if (argc == 2)
	{
		str = argv[1];
		i = 0;
		while (str[i])
		{
			char_value = str[i];
			if (str[i] >= 'a' && str[i] <= 'z')
				while (char_value > 96)
				{
					write(1, &str[i], 1);
					char_value--;
				}
			else if (str[i] >= 'A' && str[i] <= 'Z')
				while (char_value > 64)
				{
					write(1, &str[i], 1);
					char_value--;
				}
			else
				write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}