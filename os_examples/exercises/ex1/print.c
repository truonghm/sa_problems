#include <stdio.h>
#include <unistd.h>

int main() {
	
	char buff[1024];
	int nb;

	while (1) {
		nb = read(0, buff, 1024);
		if (nb == 0) return 0;
		buff[nb] = 0;
		printf("print : %s \n", buff);
	}
}