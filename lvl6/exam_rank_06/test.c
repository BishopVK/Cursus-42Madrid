/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen,isainz-r,serferna <webserv@stu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:08:14 by danjimen,is       #+#    #+#             */
/*   Updated: 2025/07/29 23:09:46 by danjimen,is      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

typedef struct s_client {
	int     id;
	char    msg[100000];
}   t_client;

t_client    clients[2048];
fd_set      active_set, read_set, write_set;
int         max_fd = 0;
int         next_id = 0;
char        send_buf[120000];
char        recv_buf[120000];

void err(char *msg)
{
	if (msg)
		write(2, msg, strlen(msg));
	else
		write(2, "Fatal error", 11);
	write(2, "\n", 1);
	exit(1);
}

void send_all(int except_fd)
{
	for (int fd = 0; fd <= max_fd; fd++)
	{
		if (FD_ISSET(fd, &write_set) && fd != except_fd)
			if (send(fd, send_buf, strlen(send_buf), 0) < 0)
				err(NULL);
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		err("Wrong number of arguments");

	int server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd < 0)
		err(NULL);

	struct sockaddr_in servaddr;
	socklen_t addrlen = sizeof(servaddr);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
	servaddr.sin_port = htons(atoi(av[1]));

	if (bind(server_fd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
		err(NULL);
	if (listen(server_fd, 100) < 0)
		err(NULL);

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

			if (fd == server_fd) // Nueva conexión
			{
				int client_fd = accept(server_fd, (struct sockaddr *)&servaddr, &addrlen);
				if (client_fd < 0)
					continue;

				if (client_fd > max_fd)
					max_fd = client_fd;

				clients[client_fd].id = next_id++;
				FD_SET(client_fd, &active_set);

				sprintf(send_buf, "server: client %d just arrived\n", clients[client_fd].id);
				send_all(client_fd);
				break;
			}
			else // Mensaje de cliente existente
			{
				int bytes = recv(fd, recv_buf, sizeof(recv_buf), 0);
				if (bytes <= 0)
				{
					sprintf(send_buf, "server: client %d just left\n", clients[fd].id);
					send_all(fd);
					FD_CLR(fd, &active_set);
					close(fd);
					bzero(clients[fd].msg, strlen(clients[fd].msg));
					break;
				}
				else
				{
					for (int i = 0, j = strlen(clients[fd].msg); i < bytes; i++, j++)
					{
						clients[fd].msg[j] = recv_buf[i];
						if (clients[fd].msg[j] == '\n')
						{
							clients[fd].msg[j] = '\0';
							sprintf(send_buf, "client %d: %s\n", clients[fd].id, clients[fd].msg);
							send_all(fd);
							bzero(clients[fd].msg, strlen(clients[fd].msg));
							j = -1;
						}
					}
				}
			}
		}
	}
	return (0);
}