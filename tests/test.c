#include "../get_next_line.h"
#include <stdlib.h>

static void test_bonus(char *line, int fd, int fd2);

int main(int argc, char *argv[]) {
	/*---- Declarations ---*/
	char *line;

	int fd = open("test.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);

	if (argc == 2)
	{
		/*----- Mandatory -----*/
		if (*argv[1] == 'm') {
			printf("%s\n\n", "MANDATORY");
			while ((line = get_next_line(fd)))
			{
				printf("%s\n\n", "LINE(S) EXIST(S)");
				printf("(%s)\n", line);
				free(line);
			}
			printf("(%s)\n", get_next_line(fd));
			return (EXIT_SUCCESS);
		}

		/*---- Bonus ----*/
		if (*argv[1] == 'b') return (test_bonus(line, fd, fd2), EXIT_SUCCESS);
		
		/*--- Invalid Input ---*/
		else {
			printf("Use valid arguments.\nValid Arguments:\nm: Mandatory\nb: Bonus");
			return(EXIT_FAILURE);
		}
	}
	/*--- Invalid Input ---*/
	printf("Use valid arguments.\nValid Arguments:\nm: Mandatory\nb: Bonus");
	return(EXIT_FAILURE);
}

void test_bonus(char *line, int fd, int fd2) {
	/*--- Declarations ---*/
	int state = 1;
	int status[] = { 1, 1 };

	while (status[0] || status[1])
	{
		if (state == 1 && status[0]) {
			line = get_next_line(fd);
			if (!line)
				status[0] = 0;
			printf("(%s)\n", line);
			free(line);
			state = 2;
		}

		if (state == 2 && status[1]) {
			line = get_next_line(fd);
			if (!line)
				status[1] = 0;
			printf("(%s)\n", line);
			free(line);
			state = 1;
		}
	}
}
