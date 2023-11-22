/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:00:59 by ebinjama          #+#    #+#             */
/*   Updated: 2023/11/22 13:44:51 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *sonic, int c)
{
	char	*s;

	s = (char *)sonic;
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*store;
	char	*self;

	store = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!store)
		return (NULL);
	self = store;
	if (s1)
		while (*s1)
			*store++ = *s1++;
	if (s2)
		while (*s2)
			*store++ = *s2++;
	*store = 0;
	return (self);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(src);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
