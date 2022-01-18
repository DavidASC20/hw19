#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main(){
  int fdread = open("pipe1", O_RDONLY, 0644);
  int fdwrite = open("pipe2", O_WRONLY, 0644);
	while (1 == 1){
		char * input = calloc(1000, 1);
		int thing = read(fdread, input, 1000);
		char * reverse = calloc(1000, 1);
		int i;
		for (i = strlen(input) - 1; i >= 0; i--){
			if (*(input + i) != 10){
				strncat(reverse, input + i, 1);
			}
		}
		write(fdwrite, reverse, 1000);
		free(input);
		free(reverse);
	}

	return 0;
}