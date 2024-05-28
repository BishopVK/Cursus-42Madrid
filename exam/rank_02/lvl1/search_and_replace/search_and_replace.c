/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:36:46 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/28 12:59:58 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	int	i;
	char	*str;
	char	char_src;
	char	char_dst;

	if (argc == 4)
	{
		i = 1;
		if (ft_strlen(argv[2]) != 1 || ft_strlen(argv[3]) != 1)
		{
			write(1, "\n", 1);
			exit(0);
		}

		i = 0;
		str = argv[1];
		char_src = argv[2][0];
		char_dst = argv[3][0];
		while (str[i])
		{
			if (str[i] == char_src)
				write(1, &char_dst, 1);
			else
				write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
