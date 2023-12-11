#include "../get_next_line.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
	/*---- Declarations ---*/
	char *line;

	int fd = open("test.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);

	(void)fd2; // I'll get to you later.
	if (argc > 1)
	{
		/*----- Mandatory -----*/
		
		if (*argv[1] == 'm')
		{
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
	}
	printf("Use valid arguments.\nValid Arguments:\nm: Mandatory\nb: Bonus");
	return(EXIT_FAILURE);
}
