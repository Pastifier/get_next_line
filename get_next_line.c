/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:22:33 by ebinjama          #+#    #+#             */
/*   Updated: 2023/12/09 09:22:34 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <unistd.h>

char		*read_to_buff(int fd, char *self, ssize_t *fetch, char *trail);
static char	*read_till_done(int fd, char *trail);
static char	*extract_line(char **from, char *trail);
static void	*ft_memset(void *s, int c, size_t n);

// TODO:
// create a buffer for all your memory shenanigans.
// free that buffer.
// idk what else to say other than that you're handsome.
char	*get_next_line(int fd)
{
	char		*line;
	char		*hold;
	static char	trail[BUFFER_SIZE + 1];

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

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dummy;

	dummy = (unsigned char *)s;
	while (n--)
		dummy[n] = c;
	return (s);
}

char	*read_to_buff(int fd, char *self, ssize_t *fetch, char *trail)
{
	char	*buff;
	char	*temp;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (free(self), NULL);
	buff[BUFFER_SIZE] = 0;
	*fetch = 1;
	while (*fetch > 0 && !ft_strchr(self, '\n'))
	{
		*fetch = read(fd, buff, BUFFER_SIZE);
		if (*fetch == 0 && self && *self)
			return (free(buff), self);
		if (*fetch <= 0)
		{
			ft_memset(trail, 0, BUFFER_SIZE);
			return (free(buff), free(self), NULL);
		}
		buff[*fetch] = 0;
		temp = self;
		self = ft_strjoin(self, buff);
		free(temp);
	}
	return (free(buff), self);
}

char	*read_till_done(int fd, char *trail)
{
	char	*self;
	ssize_t	fetch;

	self = NULL;
	if (*trail)
		self = ft_strdup(trail);
	self = read_to_buff(fd, self, &fetch, trail);
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
	else
		ft_memset(trails, 0, BUFFER_SIZE);
	return (into);
}
