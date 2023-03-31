// write a C program which utilize print.c and gendoc.c.
// this program create one process which executes the print binary.
// the program then executes the gendoc binary
// the output from gendoc is transmitted to the input of print


#include <unistd.h>
#include <stdio.h>

int main () {
	int p1[2];
	pipe (p1);
	int pid = fork();
	if (pid == 0) {
		// child
		dup2 (p1[0], 0);
		close (p1[1]); close (p1[0]);
		execlp ("./print", "print", NULL);
	} else {
		// father
		dup2 (p1[1], 1);
		close (p1[1]); close (p1[0]);
		execlp ("./gendoc", "gendoc", NULL);
	}
}
