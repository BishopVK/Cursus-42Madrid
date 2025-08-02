/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:47:48 by danjimen          #+#    #+#             */
/*   Updated: 2025/08/03 00:20:20 by danjimen         ###   ########.fr       */
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
		write(1, msg, strlen(msg));
	else
		write(1, "Fatal error", strlen("Fatal error"));
	write(1, "\n", 1);
	exit (1);
}

int	setup_server(char *port)
{
	int	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd < 0)
		write_error(NULL);

	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr)); 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = 0x0100007F; //127.0.0.1
	int	port_nbr = atoi(port);
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