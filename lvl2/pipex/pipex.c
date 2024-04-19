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
		i++;
	}
	free(split);
}

static char	*find_command_in_path(const char *command, char **path_list)
{
	int		i;
	char	*full_path;

	i = 0;
	full_path = NULL;
	while (path_list[i] != NULL)
	{
		full_path = malloc(ft_strlen(path_list[i]) + ft_strlen(command) + 2); // +1 para el '/' y +1 para el '\0'
		if (full_path == NULL)
		{
			perror("malloc failed");
			exit(1);
		}
		ft_strcpy(full_path, path_list[i]);
		full_path[ft_strlen(path_list[i])] = '/';
		ft_strcpy(full_path + ft_strlen(path_list[i]) + 1, command);
		if (access(full_path, X_OK) == 0) // Comprueba si el archivo es ejecutable
		{
			ft_printf("El proceso \"%s\" es ejecutable\n", command);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	return (NULL); // No se encontró el comando en ninguna de las rutas del PATH
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
			break ;
		}
		i++;
	}
	// Separar path por ':'
	split_path = ft_split(path, ':');
	return (split_path);
}

static void	execute(char **split_argv, char *full_path, char **env)
{
	printf("Intentando ejecutar: %s\n", split_argv[0]); // Añadido para depurar
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
			printf("La ruta completa del comando no fue encontrada\n");
		else
			printf("El comando no es accesible\n");
	}
}

static char	**child(char **argv, int *p_fd, char **env)
{
	char	**split_path;
	char	**split_argv;
	char	*full_path;

	(void)p_fd;
	//	1. Dividir el comando de los flags y/o argumentos
	split_argv = ft_split(argv[2], ' ');
	//	2. Obtener path
	split_path = get_path(env);
	//	3. Encuentra el comando en las rutas del PATH
	full_path = find_command_in_path(split_argv[0], split_path);
	free_split(split_path);
	//	4. EJECUTAR
	execute(split_argv, full_path, env);
	return (split_argv);
}

static void	parent(char **argv)
{
	int	infile_fd;

	//	0. Abrir infile o outfile
	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd < 0)
	{
		perror("open");
		exit (0);
	}
	dup2(infile_fd, STDIN_FILENO);// Duplica infile_fd en stdin (descriptor de archivo 0)
	close(infile_fd); // Cierre el descriptor de archivo original
}

int	main(int argc, char **argv, char **env)
{
	int		p_fd[2];
	pid_t	pid;
	int		status;
	char	**split_argv;

	split_argv = NULL;
	//atexit(ft_leaks);
	parent(argv);
	if (argc != 3) // CAMBIAR A 5
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
		//wait(&status);
		//printf("Proceso hijo terminado\n");
	}
	return (0);
}
