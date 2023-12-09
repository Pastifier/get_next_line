#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	int fd = open("test.txt", O_RDONLY);
	/*--- READ ---*/
	//static char buff[BUFFER_SIZE + 1];
	//buff[BUFFER_SIZE] = 0;
	//int fetch = read(fd, buff, BUFFER_SIZE);
	//(void)buff; //(void)fetch;
	//printf("ONE:\n\nContained: (%s)\n\nread_val: (%d)\n\n", buff, fetch);
	//fetch = read(fd, buff, BUFFER_SIZE);
	//printf("TWO:\n\nContained: (%s)\n\nread_val: (%d)\n\n", buff, fetch);
	
	/*--- GNL ---*/
	char *line;
	while ((line = get_next_line(fd)))
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%p\n", line);
	free(line);
	
	/*--- BUFFER_SIZE ---*/
	//printf("%d\n", BUFFER_SIZE);
	close(fd);
}
