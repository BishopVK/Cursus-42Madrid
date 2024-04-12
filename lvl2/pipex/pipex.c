/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:11:02 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/10 13:11:02 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int	pipe_fd[2];
	pid_t	pidC;

	if (argc != 5)
		return (-1);
	
	if (pipe(pipe_fd) == -1)
		exit (-1);
	pidC = fork();
	return (0);
}

/* int	main(int argc, char **argv, char **env)
{
	//int	pipe_fd[2];
	//pid_t	pid;
	int	i;
	
	i = 1;
	if (argc < 2 || argc > 5)
		return (-1);
	else
	{
		while (argv[i])
		{
			ft_printf("argv[%d] = %s\n", i, argv[i]);
			i++;
		}
	}
	i = 0;
	while (env[i])
	{
		ft_printf("env[%d] = %s\n", i, env[i]);
		i++;
	}
	return (0);
} */
