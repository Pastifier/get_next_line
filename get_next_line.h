/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:46:35 by ebinjama          #+#    #+#             */
/*   Updated: 2023/11/22 12:25:06 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h> // For EOF, minor debugging.
# include <unistd.h>// For read.
# include <fcntl.h> // For open().
# include <limits.h>// For size macros (don't know if I'll even use them tbh).
# include <stdlib.h>// For testing purposes.

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif // !BUFFER_SIZE

// Main boi
char	*get_next_line(int fd);

// Misc.
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, const char *src);
#endif // !GET_NEXT_LINE_H