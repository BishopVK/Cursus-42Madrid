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

/* void ft_leaks(void)
{
	system("leaks -q ./pipex");
} */

void	execute(char **split_argv, char *full_path, char **env)
{
	//printf("Trying to run: %s\n", split_argv[0]); // Añadido para depurar
	if (full_path != NULL && access(full_path, X_OK) == 0)
	{
		execve(full_path, split_argv, env);
		// Si execve devuelve algo, aquí el código nunca se alcanzará a ejecutar.
		perror("execve failed");
		exit (1);
	}
	else
	{
		if (full_path == NULL)
			ft_dprintf(2, "The full path of the command was not found\n");
		else
			ft_dprintf(2, "The command is not accessible\n");
	}
}

void	child1(char **argv, int *p_fd, char **env)
{
	char	**split_path;
	char	**split_argv;
	char	*full_path;
	int		fd;

	//	0. Abrir infile o outfile
	fd = open_fd(argv[1], 0);
	dup2(fd, STDIN_FILENO);// Duplica fd en stdin (descriptor de archivo 0)
	close(fd); // Cierre el descriptor de archivo original
	close(p_fd[0]);
	dup2(p_fd[1], STDOUT_FILENO);
	close(p_fd[1]);
	//	1. Dividir el comando de los flags y/o argumentos
	split_argv = ft_split(argv[2], ' ');
	//	2. Obtener path
	split_path = get_path(env);
	//	3. Encuentra el comando en las rutas del PATH
	full_path = find_command_in_path(split_argv[0], split_path);
	free_split(split_path);
	//	4. Ejecutar
	execute(split_argv, full_path, env);
	free_split(split_argv);
}

void child2(char **argv, int *p_fd, char **env)
{
	char	**split_path;
	char	**split_argv;
	char	*full_path;
	int		fd;

	//	0. Abrir infile o outfile
	fd = open_fd(argv[4], 1);
	dup2(fd, STDOUT_FILENO);// Duplica fd en stdin (descriptor de archivo 0)
	close(fd); // Cierre el descriptor de archivo original
	close(p_fd[1]);
	dup2(p_fd[0], STDIN_FILENO);
	close(p_fd[0]);
	//	1. Dividir el comando de los flags y/o argumentos
	split_argv = ft_split(argv[3], ' ');
	//	2. Obtener path
	split_path = get_path(env);
	//	3. Encuentra el comando en las rutas del PATH
	full_path = find_command_in_path(split_argv[0], split_path);
	free_split(split_path);
	//	4. Ejecutar
	execute(split_argv, full_path, env);
	free_split(split_argv);
}

int	main(int argc, char **argv, char **env)
{
	int		p_fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	//atexit(ft_leaks);
	if (argc != 5) // CAMBIAR A 5
	{
		ft_dprintf(2, "Wrong use: %s infile cmd1 cmd2 outfile\n", argv[0]);
		return (-1);
	}
	if (pipe(p_fd) == -1)
		exit(-1);
	pid1 = fork();
	if (pid1 == -1)
		exit(-1);
	if (pid1 == 0) // Este es el primer proceso hijo
	{
		//printf("Soy el primer proceso hijo\n");
		child1(argv, p_fd, env);
		exit(0);
	}
	else // Proceso padre
	{
		pid2 = fork();
		if (pid2 == -1)
			exit(-1);
		if (pid2 == 0) // Este es el segundo proceso hijo
		{
			//printf("Soy el segundo proceso hijo\n");
			child2(argv, p_fd, env);
			exit(0);
		}
		else if (pid2 > 0) // Proceso padre
		{
			//printf("Esperando a los procesos hijos...\n");
			close(p_fd[0]);
			close(p_fd[1]);
			waitpid(pid1, &status, 0);
			waitpid(pid2, &status, 0);
			//printf("Procesos hijos terminados\n");
		}
	}
	return (0);
}
