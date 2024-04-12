#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
	pid_t	pid;

	pid = fork();
	if (pid == 0) {
		sleep(3);
		printf("Hola desde el hijo\n");
		exit(1);
	}

	printf("Hola desde el padre!\n");
	return (0);
}