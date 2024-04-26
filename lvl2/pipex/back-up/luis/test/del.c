#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
	pid_t pid;
	int status = 0;

	pid = fork();
	if (pid == 0)
		exit(98);

	waitpid(pid, &status, 0);
	printf("==> %d\n", (status >> 8) & 0x000000FF);
}