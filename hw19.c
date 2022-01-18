#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main(){
	mkfifo("p1", 0644);
	mkfifo("p2", 0644);
	int fdwrite = open("p1", O_WRONLY, 0644);
	int fdread = open("p2", O_RDONLY, 0644);

	while (1 == 1){
		char * input = calloc(1000, 1);
		printf("input: \n");
		fgets(input, 1000, stdin);
		write(fdwrite, input, strlen(input));
		read(fdread, input, 1000);
		printf("read and reversed: %s\n", input);
		free(input);
	}
	return 0;
}