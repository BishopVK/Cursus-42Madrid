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

/* int	main(int argc, char **argv, char **env)
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
} */

/* int	main(int argc, char **argv)
{
	int fd_infile;
	int pipe_fd[2];
	
	if (argc != 5)
	{
		fprintf(stderr, "Uso: %s archivo1 comando1 comando2 archivo2\n", argv[0]);
		return 1;
	}

	// Abrir archivo1
	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile == -1)
	{
		perror("Error al abrir archivo1");
		return 1;
	}

	// Crear pipe
	if (pipe(pipe_fd) == -1)
	{
		perror("Error al crear el pipe");
		return 1;
	}

	// Crear primer proceso hijo
	pid_t pid1 = fork();
	if (pid1 == -1)
	{
		perror("Error al crear el primer proceso hijo");
		return 1;
	}
	else if (pid1 == 0)
	{
		// Código del primer hijo
	}
	else
	{
		// Código del padre
		// Crear segundo proceso hijo
		pid_t pid2 = fork();
		if (pid2 == -1)
		{
			perror("Error al crear el segundo proceso hijo");
			return 1;
		}
		else if (pid2 == 0)
		{
			// Código del segundo hijo
		}
		else
		{
			// Código del padre
		}
	}

	// Cerrar descriptores de archivo
	close(fd_infile);
	close(pipe_fd[0]);
	close(pipe_fd[1]);

	// Esperar a que ambos procesos hijos terminen
	wait(NULL);
	wait(NULL);

	return 0;
} */

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

/* void ft_leaks(void)
{
	system("leaks -q ./pipex");
} */

static void	free_split(char **split)
{
	int	i;

	if (split == NULL)
		return ; // No hay nada que liberar
	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		//printf("split[%d] = %s\n", i, split[i]);
		i++;
	}
	free(split);
}

static char	**get_path(char **env)
{
	int		i;
	char	*path;
	char	**split_path;

	i = 0;

	while (env[i] != NULL)
	{
		path = ft_strnstr(env[i], "PATH=", ft_strlen(env[i]));
		if (path != NULL)
		{
			path += 5;
			printf("path= %s\n", path);
			break ;
		}
		i++;
	}

	// Separar path por ':'
	split_path = ft_split(path, ':');
	i = 0;
	while (split_path[i])
	{
		printf("split_path[%d] = %s\n", i, split_path[i]);
		i++;
	}
	return (split_path);
}

void	child(char **argv, int *p_fd, char **env)
{
	//char *path;
	//char **comands;
	int		infile_fd;
	char	**split_path;
	char	**split_argv;

	(void)p_fd;
	
	//	0. Dividir el comando de los flags y/o argumentos
	split_argv = ft_split(argv[2], ' ');
	int i = 0;
	while (split_argv[i])
	{
		printf("split_argv[%d] = %s\n", i, split_argv[i]);
		i++;
	}

	//	1. Abrir infile o outfile
	infile_fd = open(argv[1], O_RDONLY);
	//(infile_fd < 0) && (perror("open"), exit(0));
	if (infile_fd < 0)
	{
		perror("open");
		exit (0);
	}
	dup2(infile_fd, STDIN_FILENO); // Duplica infile_fd en stdin (descriptor de archivo 0)
	close(infile_fd); // Cierre el descriptor de archivo original

	//	2. Obtener path
	split_path = get_path(env);
	free_split(split_path);

	//	3. Obtener argumentos
	//arguments = get_arguments();

	//	4. Hacer dups	
	//execve(path, arguments, env);
}

int	main(int argc, char **argv, char **env)
{
	int		p_fd[2];
	pid_t	pid;

	//atexit(ft_leaks);
	(void)env;
	if (argc != 5)
	{
		ft_dprintf(2, "Wrong amount of args: %s infile cmd1 cmd2 outfile\n", argv[0]);
		return (-1);
	}
	if (pipe(p_fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (!pid)
		child(argv, p_fd, env);
	//else
		//parent(argv, p_fd, env);

	return (0);
}
