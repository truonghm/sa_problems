#include <unistd.h>
#include <stdio.h>
int main() {
printf("Main before fork()\n");
int pid = fork();
if (pid == 0) 
	printf("I am child after fork()\n");
else 
	printf("I am parent after fork(), child is %d\n", pid);
return 0;
}

// This C code demonstrates the use of the fork() function in creating a child process. Here's a breakdown of what it does:

//     It includes two header files, unistd.h and stdio.h, which provide access to the fork() function and standard input/output functions respectively.

//     The main() function is defined, which returns an integer value.

//     The string "Main before fork()" is printed to the console using the printf() function.

//     The fork() function is called, which creates a copy of the current process. The parent process and child process then continue executing independently of each other.

//     The fork() function returns a value to indicate which process is currently executing. If the value is 0, then the current process is the child process. If the value is positive, then the current process is the parent process, and the value returned is the process ID (PID) of the child process.

//     If the value of pid is 0, then the current process is the child process, and the string "I am child after fork()" is printed to the console.

//     If the value of pid is positive, then the current process is the parent process, and the string "I am parent after fork(), child is %d" is printed to the console, where %d is replaced with the value of pid.

//     The main() function returns 0 to indicate successful execution.

// In summary, the program creates a child process using the fork() function, and each process prints a message to the console to indicate whether it is the parent or child process.