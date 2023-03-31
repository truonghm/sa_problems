#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signal_num) {
	printf("Signal %d => ", signal_num);
	switch (signal_num) {
	case SIGTSTP:
		printf("pause\n");
		break;
	case SIGINT:
	case SIGTERM:
		printf("End of program\n");
		exit(0);
		break;
	}
}
