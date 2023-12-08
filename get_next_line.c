#include "get_next_line.h"
#include <stddef.h>
#include <unistd.h>

static char	*read_till_done(int fd, char *trail);

static char	*extract_line(char **from, char *trail);

// TODO:
// create a buffer for all your memory shenanigans.
// free that buffer.
// idk what else to say other than that you're handsome.
char	*get_next_line(int fd)
{
	char		*line;
	char		*hold;
	static char	trail[BUFFER_SIZE + 1U];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	trail[BUFFER_SIZE] = 0;
	hold = read_till_done(fd, trail);
	if (!hold)
		return (NULL);
	line = extract_line(&hold, trail);
	free(hold);
	return (line);
}

char	*read_till_done(int fd, char *trail)
{
	char	*self;
	char	*temp;
	char	buff[BUFFER_SIZE + 1U];
	t_boolint	done;

	self = NULL;
	self = ft_strdup(trail);
	buff[BUFFER_SIZE] = 0;
	while (self && !ft_strchr(self, '\n'))
	{
		done = (t_boolint){.value = read(fd, buff, BUFFER_SIZE),
					.errno = done.value <= 0};
		buff[done.value] = 0;
		if (done.errno)
			return (free(self), NULL);
		temp = self;
		self = ft_strjoin(self, buff);
		free(temp);
	}
	return (self);
}

// TODO:
// decide how you want to deal with extracting the line
// (the trick you have in mind is using nl_address as a "bool").
//
// burn Norminette.
char	*extract_line(char **from, char *trails)
{
	char	*into;
	char	*nl_address;
	size_t	len;

	nl_address = ft_strchr(*from, '\n');
	if (nl_address)
		len = (size_t)(nl_address - *from + 1);
	else
		len = ft_strlen(*from);
	into = malloc(sizeof(char) * (len + 1));
	if (!into)
		return (NULL);
	into[len] = 0;
	while (len--)
		into[len] = (*from)[len];
	if (nl_address && *(nl_address + 1))
		ft_strncpy(trails, nl_address + 1, BUFFER_SIZE);
	return (into);
}
