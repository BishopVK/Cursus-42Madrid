/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeFork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:51:35 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/11 12:51:35 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../printf/ft_printf.h"

int main(void)
{
	int		fd[2];
	pid_t	pidC;
	char	buf[10];
	int		num;

	if (pipe(fd) == -1)
		return (-1);
	pidC = fork();

	if (pidC == -1)
	{
		close(fd[0]);
		close(fd[1]);
		exit(-1);
	}
	else if (pidC == 0) // Hijo
	{
		close(fd[0]);
		//ft_dprintf(fd[1], "abcde");
		write(fd[1], "abcde", 6);
		close(fd[1]);
		exit(0);
	}
	else // Padre
	{
		close(fd[1]);
		num = read(fd[0], buf, sizeof(buf));
		buf[num] = '\0';
		printf("Padre lee %d bytes: %s \n", num, buf);
		close(fd[0]);
	}
	return (0);
}

/* int main(void)
{
	int		fd[2];
	pid_t	pidC;
	char	buf[10];
	int		num;

	if (pipe(fd) == -1)
		return (-1);
	pidC = fork();

	switch (pidC)
	{
		case 0: // Hijo
			close(fd[0]);
			write(fd[1], "abcde", 6);
			close(fd[1]);
			exit(0);
			break;
		case -1:
			close(fd[0]);
			close(fd[1]);
			exit(-1);
			break;
		default: // Padre
			close(fd[1]);
			num = read(fd[0], buf, sizeof(buf));
			buf[num] = '\0';
			printf("Padre lee %d bytes: %s \n", num, buf);
			close(fd[0]);
			break;
	}
	return 0;
} */
