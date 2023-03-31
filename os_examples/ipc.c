// The following C code demonstrates the use of the pipe() function in creating a pipe. Here's a breakdown of what it does:	
//     It includes two header files, unistd.h and stdio.h, which provide access to the pipe() function and standard input/output functions respectively.
//     The main() function is defined, which returns an integer value.
//     An array of two integers is declared, which will be used to store the two file descriptors returned by the pipe() function.
//     The pipe() function is called, which creates a pipe. The two file descriptors are stored in the array p.
//     The fork() function is called, which creates a copy of the current process. The parent process and child process then continue executing independently of each other.
//     The fork() function returns a value to indicate which process is currently executing. If the value is 0, then the current process is the child process. If the value is positive, then the current process is the parent process, and the value returned is the process ID (PID) of the child process.
//     If the value of pid is 0, then the current process is the child process, and the following actions are performed:
//         The dup2() function is called, which duplicates the file descriptor p[1] (the write end of the pipe) to the file descriptor 1 (standard output). This means that any data written to standard output will actually be written to the write end of the pipe.
//         The close() function is called twice, which closes the read end of the pipe (file descriptor p[0]) and the write end of the pipe (file descriptor p[1]).
//         The execlp() function is called, which executes the ps command. The ps command lists the currently running processes, and the -ef option causes it to list all processes. The ps command writes its output to standard output, which is actually the write end of the pipe.
//     If the value of pid is positive, then the current process is the parent process, and the following actions are performed:
//         The dup2() function is called, which duplicates the file descriptor p[0] (the read end of the pipe) to the file descriptor 0 (standard input). This means that any data read from standard input will actually be read from the read end of the pipe.
//         The close() function is called twice, which closes the read end of the pipe (file descriptor p[0]) and the write end of the pipe (file descriptor p[1]).
//         The execlp() function is called, which executes the grep command. The grep command searches for a specified string in a file, and the firefox option causes it to search for the string firefox. The grep command reads its input from standard input, which is actually the read end of the pipe.
//     The main() function returns 0 to indicate successful execution.
// In summary, the program creates a pipe, and then creates a child process using the fork() function. The child process executes the ps command, which writes its output to the write end of the pipe. The parent process executes the grep command, which reads its input from the read end of the pipe.

#include <unistd.h>
#include <stdio.h>

int main (int argc, char *argv[]) {
	int p[2];
	pipe (p);
	if (fork() == 0) {
		// child
		dup2 (p[1], 1);
		close (p[0]); close (p[1]);
		execlp ("ps", "ps", "-ef", NULL);
	} else {
		// father
		dup2 (p[0], 0);
		close (p[0]); close (p[1]);
		execlp ("grep", "grep", "firefox", NULL);
	}
}