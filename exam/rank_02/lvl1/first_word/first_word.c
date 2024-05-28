/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:03:40 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/28 10:16:42 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*string;
	int		i = 0;

	if (argc == 2)
	{
		string = argv[1];
		while (string[i] >= 9 && string[i] <= 32)
			i++;
		while (string[i] > 32 && string[i] <= 127)
		{
			write(1, &string[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}