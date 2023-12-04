#include "get_next_line.h"
#include <stddef.h>

size_t	ft_strlen(const char *initial)
{
	const char	*final;

	if (!initial)
		return (0);
	final = initial;
	while (*final)
		++final;
	return (final - initial);
}

// Doesn't account for needle being the null-terminator
// cuz it's not needed anyway.
char	*ft_strchr(const char *haystack, int needle)
{
	if (!haystack)
		return (NULL);
	while (*haystack)
	{
		if (*haystack == needle)
			return ((char *)haystack);
		++haystack;
	}
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*self;
	char	*dummy;
	bool	is_nl;

	if (!s1 && !s2)
		return (NULL);
	is_nl = ('\n' == *(ft_strchr(s2, '\n')));
	self = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + is_nl + 1));
	if (!self)
		return (NULL);
	dummy = self;
	if (s1)
		while (*s1)
			*dummy++ = *s1++;
	if (s2)
		while (*s2)
			*dummy++ = *s2++;
	*++dummy = 0;
	return (self);
}

char	*ft_strdup(const char *str)
{
	char	*self;
	char	*dummy;

	if (!str)
		return (NULL);
	self = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!self)
		return (NULL);
	dummy = self;
	while (*str)
		*dummy++ = *str++;
	*dummy = 0;
	return (self);
}

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	if (!dst || !src)
		return (NULL);
	while (*src && n--)
		*dst++ = *src++;
	*dst = 0;
	return (dst);
}
