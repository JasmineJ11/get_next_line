
#ifndef GET_NEXT_LINT_H
# define GET_NEXT_LINT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *destination, const void *source, size_t num);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*extractLine(char *cache, char *newPtr);
char	*moveCache(char *cache, char *newPtr);
char	*get_next_line(int fd);

#endif