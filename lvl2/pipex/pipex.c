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
	int		fd_infile;
	pid_t	pid;
	int		status;

	(void)env;

	if (argc != 5)
		return (-1);

	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile == -1)
	{
		perror("");
		return (-1);
	}

	pid = fork();

	if (pid < 0)
	{
		// Error al crear el proceso hijo
		fprintf(stderr, "Error al crear el proceso hijo\n");
		return 1;
	}
	else if (pid == 0)
	{
		// Este es el proceso hijo
		printf("Hola, soy el proceso hijo (PID: %d)\n", getpid());
	}
	else
	{
		// Este es el proceso padre
		//wait(&status);
		waitpid(pid, &status, 0);
		printf("Hola, soy el proceso padre (PID: %d)\n", getpid());
	}

	close(fd_infile);
	return (0);
}

/* int	main(int argc, char **argv, char **env)
{
	(void)env;
	int fd_infile;
	char buffer[1024];
	ssize_t bytes_read;

	if (argc != 5)
		return (-1);

	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile == -1)
	{
		perror("");
		return (-1);
	}

	while ((bytes_read = read(fd_infile, buffer, 1024)) > 0)
	{
		if (write(STDOUT_FILENO, buffer, bytes_read) != bytes_read)
		{
			perror("write");
			exit(EXIT_FAILURE);
		}
	}

	if (bytes_read == -1)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}

	close(fd_infile);
	return (0);
} */

/* int	main(int argc, char **argv, char **env)
{
	int	pipe_fd[2];
	pid_t	pidC;
	(void)env;

	if (argc != 3) //Cambiar el 3 por un 5
		return (-1);
	
	if (pipe(pipe_fd) == -1)
		exit (-1);
	pidC = fork();
	return (0);
} */

/* int	main(int argc, char **argv, char **env)
{
	//int	pipe_fd[2];
	//pid_t	pid;
	int	i;
	
	i = 0;
	if (argc < 2 || argc > 5)
		return (-1);
	else
	{
		while (argc)
		{
			ft_printf("argv[%d] = %s\n", i, argv[i]);
			argc--;
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
