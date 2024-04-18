/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 08:08:47 by danjimen          #+#    #+#             */
/*   Updated: 2024/04/18 13:44:27 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "../libft/libft.h"

/* int	main(int argc, char **argv, char **env)
{
	int i = 0;
	while (env[i])
	{
		printf("Env[%d] = %s\n", i, env[i]);
		i++;
	}
	return (0);
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
			return full_path;
		free(full_path);
		i++;
	}

	return NULL; // No se encontró el comando en ninguna de las rutas del PATH
}

int	main(int argc, char **argv, char **env)
{
	int		i;
	char	*path;

	i = 0;

	//Obtener PATH= de **env
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
	char	**split;
	split = ft_split(path, ':');
	i = 0;
	while (split[i])
	{
		printf("split[%d] = %s\n", i, split[i]);
		i++;
	}

	// Encuentra el comando en las rutas del PATH
	char	*command = "wc"; // Puedes cambiar esto según el comando que recibas
	char	*full_path = find_command_in_path(command, split);
	char	*args[] = {full_path, "-l", NULL};

	if (full_path != NULL)
	{
		printf("La ruta completa para el comando '%s' es: %s\n", command, full_path);
		// Aquí puedes usar full_path en execve
		free(full_path);
	}
	else
	{
		printf("No se encontró el comando '%s' en ninguna ruta del PATH\n", command);
	}

	// Liberar memoria
	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);

	// Redireccionar la entrada del archivo
	int infile_fd = open("txt.txt", O_RDONLY);
	if (infile_fd < 0)
	{
		perror("open");
		return (1);
	}
	dup2(infile_fd, STDIN_FILENO); // Duplica infile_fd en stdin (descriptor de archivo 0)
	close(infile_fd); // Cierre el descriptor de archivo original

	//Ejecutar
	printf("Intentando ejecutar: %s\n", args[0]); // Añadido para depurar
	if (full_path != NULL && access(args[0], X_OK) == 0)
	{
		execve(full_path, args, NULL);
		// Si execve devuelve algo, aquí el código nunca se alcanzará a ejecutar.
		perror("execve failed");
		return (1);
	}
	else
	{
		if (full_path == NULL)
			printf("La ruta completa del comando no fue encontrada\n");
		else
			printf("El comando no es accesible\n");
	}
	return (0);
}

/* int	main(int argc, char **argv, char **env)
{
	int		i;
	char	*path;
	char	*args[] = {"/bin/ls", "-l", NULL};

	// i = 0;

	// //Obtener PATH= de **env
	// while (env[i] != NULL)
	// {
	// 	path = ft_strnstr(env[i], "PATH=", ft_strlen(env[i]));
	// 	if (path != NULL)
	// 	{
	// 		printf("path= %s\n", path + 5);
	// 		break ;
	// 	}
	// 	i++;
	// }

	// // Separar path por ':'
	// i = 0;
	// char **split;
	// split = ft_split(path + 5, ':');

	// while (split[i])
	// {
	// 	printf("split[%d] = %s\n", i, split[i]);
	// 	i++;
	// }

	//Ejecutar
	execve("/bin/ls", args, NULL);
	// Si execve devuelve algo, aquí el código nunca se alcanzará a ejecutar.
	perror("execve failed");
	return (0);
} */

/* int	main(int argc, char **argv, char **env)
{
	int		i;
	char	*equal_sign_pos;

	i = 0;
	while (env[i] != NULL)
	{
		equal_sign_pos = strchr(env[i], '=');
		if (equal_sign_pos != NULL)
		{
			// Dividir la cadena en el nombre y el valor
			*equal_sign_pos = '\0'; // Terminar la cadena en el signo '='
			printf("Variable: %s, Valor: %s\n", env[i], equal_sign_pos + 1);
		}
		else
		{
			printf("Variable: %s\n", env[i]);
		}
		i++;
	}
	return (0);
} */
