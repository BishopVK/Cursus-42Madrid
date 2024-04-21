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

char	**child(char **argv, int *p_fd, char **env)
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
	return (split_argv);
}

char	**parent(char **argv, int *p_fd, char **env)
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
	return (split_argv);
}

int	main(int argc, char **argv, char **env)
{
	int		p_fd[2];
	pid_t	pid;
	int		status;
	char	**split_argv;

	split_argv = NULL;
	//atexit(ft_leaks);
	if (argc != 5) // CAMBIAR A 5
	{
		ft_dprintf(2, "Wrong use: %s infile cmd1 cmd2 outfile\n", argv[0]);
		return (-1);
	}
	if (pipe(p_fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0) // Proceso hijo
	{
		//printf("Soy el proceso hijo\n");
		split_argv = child(argv, p_fd, env);
		free_split(split_argv);
		exit(0);
	}
	else if (pid > 0) // Proceso padre
	{
		//printf("Esperando al proceso hijo...\n");
		//parent(argv);
		waitpid(pid, &status, 0);
		split_argv = parent(argv, p_fd, env);
		free_split(split_argv);
		//wait(&status);
		//printf("Proceso hijo terminado\n");
	}
	return (0);
}
