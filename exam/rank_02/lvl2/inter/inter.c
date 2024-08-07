/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:18:11 by danjimen          #+#    #+#             */
/*   Updated: 2024/05/29 19:14:05 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_inter(char *str1, char *str2)
{
	char	result[1024];
	int		i;
	int		j;
	int		k;
	int		flag;

	i = 0;
	while (str1[i])
	{
		j = 0;
		while (str2[j])
		{
			if (str1[i] == str2[j])
			{
				k = 0;
				flag = 0;
				while (result[k])
				{
					if (result[k] == str1[i])
						flag++;
					k++;
				}
				if (flag == 0)
				{
					result[k] = str1[i];
					write(1, &result[k], 1);
				}
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (!argv[1] || !argv[2])
			return (1);
		ft_inter(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}
