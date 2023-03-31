#include <stdio.h>
#include <unistd.h>

int main() {
	int atob[2];
	int btoa[2];

	pipe(atob);
	pipe(btoa);

	int pid = fork();
	if (pid == 0) {
		// A
		dup2(atob[1], 1);
		dup2(btoa[0], 0);
		close(atob[0]); close(atob[1]);
		close(btoa[0]); close(btoa[1]);
		execlp("./A", "A", NULL);
	}
	// B
	dup2(atob[0], 0);
	dup2(btoa[1], 1);
	close(atob[0]); close(atob[1]);
	close(btoa[0]); close(btoa[1]);
	execlp("./B", "B", NULL);
}