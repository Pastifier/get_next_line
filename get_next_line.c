#include "get_next_line.h"

static char	*extract_line(int fd, char **trail);

char	*get_next_line(int fd)
{
	char		*line;
	static char	trail[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (line);
}
