/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen,isainz-r,serferna <webserv@stu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:08:44 by danjimen,is       #+#    #+#             */
/*   Updated: 2025/07/29 23:30:56 by danjimen,is      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

typedef struct s_client
{
    int     id;//specific id client
    char    msg[100000];//buffer to store received messages
}   t_client;

//global variable declaration
t_client    clients[2048];//can store 2048 client struct
fd_set      read_set, write_set, current;//stock fd wich receive a "message", to write (send()) and current = all actif fd.
int         maxfd = 0;//maxfd = the biggest actif fd, update each time a new client is connected
int	gid = 0;//gid is a variable with what we attribute a unique id for each client (clients[cientfd].id = gid++;)
char        send_buffer[120000], recv_buffer[120000];//communication buffers

void    err(char  *msg)
{
    if (msg)
        write(2, msg, strlen(msg));
    else
        write(2, "Fatal error", 11);
    write(2, "\n", 1);
    exit(1);
}

//send a message to all clients
void    send_to_all(int except)
{
    for (int fd = 0; fd <= maxfd; fd++)
    {
        if  (FD_ISSET(fd, &write_set) && fd != except)//check if fd is in write_set
            if (send(fd, send_buffer, strlen(send_buffer), 0) == -1)//send the message to the fd
                err(NULL);
    }
}

int     main(int ac, char **av)
{
    if (ac != 2)
        err("Wrong number of arguments");

    struct sockaddr_in  serveraddr;//store IP and port for the server socket
    socklen_t len = sizeof(struct sockaddr_in);/*socklen_t is a special int create to store
	a sockaddr_in struct lenght, len is needed for accept() or recvfrom() becaus it's modify the lenght*/
    int serverfd = socket(AF_INET, SOCK_STREAM, 0);//create a socket (fd) for the server with IPV4 and TCP
    if (serverfd == -1) err(NULL);
    maxfd = serverfd;//update maxfd

    FD_ZERO(&current);//initialise the fd_set current to zero
    FD_SET(serverfd, &current);//add serverfd to the fd_set current
    bzero(clients, sizeof(clients));//initialize clients to zero
    bzero(&serveraddr, sizeof(serveraddr));//initialize serveraddr to zero

    serveraddr.sin_family = AF_INET;//family address is IPV4
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);//accept all IP
    serveraddr.sin_port = htons(atoi(av[1]));//convert the port number in network format (bit)

//attach the serversocket to his IP and port with bind()
//listen() convert serversocket in a listen state for 100 connexions max
    if (bind(serverfd, (const struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1 || listen(serverfd, 100) == -1)
        err(NULL);
//principal loop
    while (1)
    {
        read_set = write_set = current;//we add all actif fd in read and write_set because select will delete no ready fd from this two set
        if (select(maxfd + 1, &read_set, &write_set, 0, 0) == -1) continue;//update each set (remove fd of fd_set if not ready to), return number of fd ready

        for (int fd = 0; fd <= maxfd; fd++)
        {
            if (FD_ISSET(fd, &read_set))//if fd is in read_set, it means that it receive a "message"
            {
                if (fd == serverfd)//if it's the server, it means a new connexion
                {
                    int clientfd = accept(serverfd, (struct sockaddr *)&serveraddr, &len);

                    if (clientfd == -1) continue;
                    if (clientfd > maxfd) maxfd = clientfd;
                    clients[clientfd].id = gid++;
                    FD_SET(clientfd, &current);
                    sprintf(send_buffer, "server: client %d just arrived\n", clients[clientfd].id);
                    send_to_all(clientfd);
                    break;
                }
                else
                {
                    int ret = recv(fd, recv_buffer, sizeof(recv_buffer), 0);
                    if (ret <= 0)
                    {
                        sprintf(send_buffer, "server: client %d just left\n", clients[fd].id);
                        send_to_all(fd);
                        FD_CLR(fd, &current);
                        close(fd);
                        bzero(clients[fd].msg, strlen(clients[fd].msg));
                        break;
                    }
                    else
                    {
                        for (int i = 0, j = strlen(clients[fd].msg); i < ret; i++, j++)
                        {
                            clients[fd].msg[j] = recv_buffer[i];
                            if (clients[fd].msg[j] == '\n')
                            {
                                clients[fd].msg[j] = '\0';
                                sprintf(send_buffer, "client %d: %s\n", clients[fd].id, clients[fd].msg);
                                send_to_all(fd);
                                bzero(clients[fd].msg, strlen(clients[fd].msg));
                                j = -1;
                            }
                        }
                    }
                }
            }
        }
    }
    return (0);
}