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

/* static char	**get_arguments(char *full_path, char **split_argv)
{
	char	**args;
	//(void)full_path;
	int		count;
	int		i;

	ft_printf("HOLA\n");
	count = 0;
	while (split_argv[count])
		count++;
	ft_printf("count = %d\n", count);

	args = (char **)malloc((count + 2) * sizeof(char *));
	if (args == NULL)
		return (NULL);
	args[0] = ft_strdup(full_path);
	i = 1;
	while (i <= count)
	{
		args[i] = ft_strdup(split_argv[i - 1]);
		i++;
	}
	ft_printf("AQUÍ HE LLEGADO\n");
	args[i] = NULL;
	ft_printf("ADIOS\n");

	return (args);
} */

/* static char	**get_arguments(char **split_argv)
{
	char	**args;
	int		count;
	int		i;

	ft_printf("HOLA\n");
	count = 0;
	while (split_argv[count])
		count++;
	ft_printf("count = %d\n", count);

	args = (char **)malloc((count + 2) * sizeof(char *));
	if (args == NULL)
		return (NULL);
	args[0] = ft_strdup(full_path);
	i = 1;
	while (i <= count)
	{
		args[i] = ft_strdup(split_argv[i - 1]);
		i++;
	}
	ft_printf("AQUÍ HE LLEGADO\n");
	args[i] = NULL;
	ft_printf("ADIOS\n");

	return (args);
} */

static char	*find_command_in_path(const char *command, char **path_list)
{
	int i = 0;
	char *full_path = NULL;

	while (path_list[i] != NULL)
	{
		char *path = path_list[i];
		int path_len = strlen(path);
		int command_len = strlen(command);
		full_path = malloc(path_len + command_len + 2); // +1 para el '/' y +1 para el '\0'
		if (full_path == NULL)
		{
			perror("malloc failed");
			exit(1);
		}
		strcpy(full_path, path);
		full_path[path_len] = '/';
		strcpy(full_path + path_len + 1, command);
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

/* static void	free_split(char **split)
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
 */
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

static void	child(char **argv, int *p_fd, char **env)
{
	//char *path;
	//char **comands;
	char	**split_path;
	char	**split_argv;
	char	*full_path;
	//char	**args;

	(void)p_fd;
	
	//	1. Dividir el comando de los flags y/o argumentos
	split_argv = ft_split(argv[2], ' ');
	int i = 0;
	while (split_argv[i])
	{
		printf("split_argv[%d] = %s\n", i, split_argv[i]);
		i++;
	}

	//	2. Obtener path
	split_path = get_path(env);
	//free_split(split_path); // Cuando ya no sea necesario

	//	3. Encuentra el comando en las rutas del PATH
	full_path = find_command_in_path(split_argv[0], split_path);
	ft_printf("full_path = %s\n", full_path);

	//	4. Obtener argumentos
	/* args = get_arguments(split_argv);
	i = 0;
	while (args[i])
	{
		printf("args[%d] = %s\n", i, args[i]);
		i++;
	} */

	//	5. Hacer dups	//	EJECUTAR
	//execve(path, arguments, env);
	printf("Intentando ejecutar: %s\n", split_argv[0]); // Añadido para depurar
	/* if (execve(full_path, split_argv, NULL) == -1) {
		perror("execve");
	} */
	if (full_path != NULL && access(full_path, X_OK) == 0)
	{
		execve(full_path, split_argv, NULL);
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

/* static void	parent(char **argv)
{
	int	infile_fd;
	
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
} */

int	main(int argc, char **argv, char **env)
{
	int		p_fd[2];
	pid_t	pid;
	int		status;
	int	infile_fd;
	
	//	0. Abrir infile o outfile
	infile_fd = open(argv[1], O_RDONLY);
	//(infile_fd < 0) && (perror("open"), exit(0));
	if (infile_fd < 0)
	{
		perror("open");
		exit (0);
	}
	dup2(infile_fd, STDIN_FILENO); // Duplica infile_fd en stdin (descriptor de archivo 0)
	close(infile_fd); // Cierre el descriptor de archivo original

	//atexit(ft_leaks);
	(void)env;
	if (argc != 3) // CAMBIAR A 5
	{
		ft_dprintf(2, "Wrong amount of args: %s infile cmd1 cmd2 outfile\n", argv[0]);
		return (-1);
	}
	if (pipe(p_fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0) // Proceso hijo
	{
		printf("Soy el proceso hijo\n");
		child(argv, p_fd, env);
		exit(0);
	}
	else if (pid > 0) // Proceso padre
	{
		printf("Esperando al proceso hijo...\n");
		//parent(argv);
		waitpid(pid, &status, 0);
		//wait(&status);
		printf("Proceso hijo terminado\n");
	}

	return (0);
}
