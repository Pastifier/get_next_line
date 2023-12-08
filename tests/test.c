#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	int fd = open("test.txt", O_RDONLY);
	char *line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	while ((line = get_next_line(fd)))
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
}
