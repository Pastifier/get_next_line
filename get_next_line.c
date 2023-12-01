#include "get_next_line.h"
#include <stddef.h>
#include <unistd.h>

static char	*read_to_self(int fd);

static char	*read_till_done(int fd, char **trail);

static char	*extract_line(char **from, char **trail);

char	*get_next_line(int fd)
{
	char		*line;
	static char	trail[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (line);
}

char	*read_till_done(int fd, char **trail)
{
	char	*self;
	char	*temp;
	char	buff[BUFFER_SIZE + 1];
	bool	done;

	self = ft_strdup(*trail);
	while (self && !ft_strchr(self, '\n'))
	{
		done = (read(fd, buff, BUFFER_SIZE) <= 0);
		buff[BUFFER_SIZE] = 0;
		if (done)
		{
			free(self);
			return (NULL);
		}
		temp = self;
		self = ft_strjoin(self, buff);
		free(temp);
	}
	return (self);
}

char	*extract_line(char **from, char **trails)
{
	char	*into;
	char	*nl_address;
	size_t	len;

	nl_address = ft_strchr(*from, '\n');
	if (nl_address)
		len = (size_t)(*from - nl_address + 1);
	else
		len = ft_strlen(*from);
	into = malloc(sizeof(char) * (len + 1));
	if (!into)
		return (NULL);
	return (into);
}
