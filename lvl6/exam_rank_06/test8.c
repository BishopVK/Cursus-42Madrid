/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 22:52:03 by danjimen          #+#    #+#             */
/*   Updated: 2025/08/04 23:20:00 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

typedef struct s_client {
	int		id;
	char	msg[100000];
} t_client;

t_client	clients[2048];
fd_set		active_set, read_set, write_set;
int			max_fd = 0;
int			next_id = 0;
char		send_buf[120000];
char		recv_buf[120000];

void	write_error(char *msg)
{
	if (msg)
		write(2, msg, strlen(msg));
	else
		write(2, "Fatal error", strlen("Fatal error"));
	write(2, "\n", 1);
	exit (1);
}

int	setup_server(char *port)
{
	int server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd < 0)
		write_error(NULL);

	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = 0x0100007F; //127.0.0.1
	int port_nbr = atoi(port);
	servaddr.sin_port = (port_nbr >> 8) | (port_nbr << 8);

	if ((bind(server_fd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) < 0)
		write_error(NULL);

	if (listen(server_fd, 100) < 0)
		write_error(NULL);

	return (server_fd);
}

void	broadcast(int except_fd)
{
	for (int fd = 0; fd <= max_fd; fd++)
	{
		if (FD_ISSET(fd, &write_set) && fd != except_fd)
			if (send(fd, send_buf, strlen(send_buf), 0) < 0)
				write_error(NULL);
	}
}

void	add_client(int server_fd)
{
	struct sockaddr_in cli;
	socklen_t len = sizeof(cli);
	int client_fd = accept(server_fd, (struct sockaddr *)&cli, &len);
	if (client_fd < 0)
		return ;
	
	if (client_fd > max_fd)
		max_fd = client_fd;
	clients[client_fd].id = next_id++;
	FD_SET(client_fd, &active_set);

	sprintf(send_buf, "server: client %d just arrived\n", clients[client_fd].id);
	broadcast(client_fd);
}

void	remove_client(int client_fd)
{
	sprintf(send_buf, "server: client %d just left\n", clients[client_fd].id);
	broadcast(client_fd);
	FD_CLR(client_fd, &active_set);
	close(client_fd);
	bzero(clients[client_fd].msg, strlen(clients[client_fd].msg));
}

void	handle_message(int client_fd)
{
	int	bytes = recv(client_fd, recv_buf, sizeof(recv_buf), 0);
	if (bytes <= 0)
	{
		remove_client(client_fd);
		return ;
	}

	for (int i = 0, j = strlen(clients[client_fd].msg); i < bytes; i++, j++)
	{
		clients[client_fd].msg[j] = recv_buf[i];
		if (clients[client_fd].msg[j] == '\n')
		{
			clients[client_fd].msg[j] = '\0';
			sprintf(send_buf, "client %d: %s\n", clients[client_fd].id, clients[client_fd].msg);
			broadcast(client_fd);
			bzero(clients[client_fd].msg, strlen(clients[client_fd].msg));
			j = -1;
		}
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		write_error("Wrong number of arguments");
	
	int server_fd = setup_server(argv[1]);
	FD_ZERO(&active_set);
	FD_SET(server_fd, &active_set);
	max_fd = server_fd;
	bzero(clients, sizeof(clients));

	while (1)
	{
		read_set = write_set = active_set;
		if (select(max_fd + 1, &read_set, &write_set, NULL, NULL) < 0)
			continue;

		for (int fd = 0; fd <= max_fd; fd++)
		{
			if (!FD_ISSET(fd, &read_set))
				continue;
			if (fd == server_fd)
				add_client(server_fd);
			else
				handle_message(fd);
		}
	}
	return (0);
}