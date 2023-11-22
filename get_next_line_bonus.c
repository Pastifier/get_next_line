/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:09:02 by ebinjama          #+#    #+#             */
/*   Updated: 2023/11/22 13:57:54 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	read_to_buf(int fd, char **buf)
{
	int	bytes_read;

	bytes_read = read(fd, buf[fd], BUFFER_SIZE);
	buf[bytes_read] = '\0';
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	buf[256][BUFFER_SIZE + 1];
	char		*line;
	char		*line_temp;
	char		*new_line_in_buff;

	line = NULL;
	new_line_in_buff = ft_strchr(buf[fd], '\n');
	while (!new_line_in_buff)
	{
		if (*buf[fd])
		{
			line_temp = line;
			line = ft_strjoin(line, buf[fd]);
			free(line_temp);
		}
		if (!read_to_buf(fd, buf[fd]))
			return (line);
		new_line_in_buff = ft_strchr(buf[fd], '\n');
	}
	line_temp = line;
	buf[fd][new_line_in_buff - buf[fd]] = '\0';
	line = ft_strjoin(line, buf[fd]);
	free(line_temp);
	ft_strcpy(buf, new_line_in_buff + 1);
	return (line);
}
