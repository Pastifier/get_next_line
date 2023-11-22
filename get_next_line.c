/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:09:02 by ebinjama          #+#    #+#             */
/*   Updated: 2023/11/22 13:17:16 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_to_buf(int fd, char *buf)
{
	int	bytes_read;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	buf[bytes_read] = '\0';
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*line_temp;
	char		*new_line_in_buff;

	line = NULL;
	new_line_in_buff = ft_strchr(buf, '\n');
	while (!new_line_in_buff)
	{
		if (buf[0] != '\0')
		{
			line_temp = line;
			line = ft_strjoin(line, buf);
			free(line_temp);
		}
		if (!read_to_buf(fd, buf))
			return (line);
		new_line_in_buff = ft_strchr(buf, '\n');
	}
	line_temp = line;
	buf[new_line_in_buff - buf] = '\0';
	line = ft_strjoin(line, buf);
	free(line_temp);
	ft_strcpy(buf, new_line_in_buff + 1);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
	}
	return (0);
}
