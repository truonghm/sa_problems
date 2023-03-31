// We want to implement a C program that implements the same behavior as the following shell
// command:
// ps -ef | grep firefox | wc -l
// Your program has to create 3 processes that respectively execute the ps, grep and wc binaries that
// are accessible from your path variable. The standard input and output of these processes are
// interconnected with pipes to implement the requested communication flow.
// Here is a list of the Unix functions that you should use in your program:
// int fork();
// int execlp(char *file, char *arg, ...);
// void perror(const char *s);
// int pipe(int pipefd[2]);
// int dup2(int oldfd, int newfd);
// int close(int fd);

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

int main (int argc, char *argv[]) {
	int p1[2];
	int p2[2];
	pipe (p1);
	pipe (p2);
	if (fork() == 0) {
		// child
		dup2 (p1[1], 1);
		close (p1[0]); close (p1[1]);
		execlp ("ps", "ps", "-ef", NULL);
	} else {
		// father
		dup2 (p1[0], 0);
		close (p1[0]); close (p1[1]);
		if (fork() == 0) {
			// child
			dup2 (p2[1], 1);
			close (p2[0]); close (p2[1]);
			execlp ("grep", "grep", "firefox", NULL);
		} else {
			// father
			dup2 (p2[0], 0);
			close (p2[0]); close (p2[1]);
			execlp ("wc", "wc", "-l", NULL);
		}
	}
}