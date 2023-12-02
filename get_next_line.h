#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>   // For read
# include <fcntl.h>    // For testing
# include <stdio.h>    // For EOF
# include <stdlib.h>   // For malloc, free, size_t
# include <stdbool.h>  // Cuz real men use true/false

/*-----const.defs-----*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (42)
# endif // !BUFFER_SIZE

/*--------main--------*/

// Takes in a file-descriptor and fetches
// data from it line-by-line, call-by-call,
// respectively.
//
// RETURN VALUES:
// - The next line starting from the file-descriptor's
// current read-offset
// (offset starts from `0`, beggining of file).
//
// - NULL if the file-descriptor's offset is at EOF
// or on error/failure.
// @param fd: The file-descriptor in question.
char	*get_next_line(int fd);

/*--------Misc.--------*/

char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *str);
char	*ft_strcpy(char *dst, const char *src);
size_t	ft_strlen(const char *str);

#endif // !GET_NEXT_LINE_H
