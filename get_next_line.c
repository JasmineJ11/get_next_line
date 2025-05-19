/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiawli <jiawli@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:55:30 by jiawli            #+#    #+#             */
/*   Updated: 2025/05/14 15:55:33 by jiawli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*moveCache(char *cache, char *newPtr)
{
	char	*newCache;

	if (cache == NULL || newPtr == NULL)
		return (free(cache), NULL);
	newCache = ft_strdup(newPtr + 1);
	free(cache);
	cache = NULL;
	return (newCache);
}

char	*extractLine(char *cache, char *newPtr)
{
	size_t	lineLen;
	char	*line;

	if (cache == NULL)
		return (NULL);
	if (newPtr != NULL)
	{
		lineLen = (newPtr - cache) + 1;
		line = ft_substr(cache, 0, lineLen);
		return (line);
	}
	else
	{
		line = ft_strdup(cache);
		return (line);
	}
}

static char	*getCache(int fd, char *cache)
{
	char	*buffer;
	int		byteRead;
	char	*temp;

	buffer = malloc((BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (free(cache), cache = NULL, NULL);
	byteRead = 1;
	while ((cache == NULL || !ft_strchr(cache, '\n')) && (byteRead = read(fd,
				buffer, BUFFER_SIZE)) > 0)
	{
		buffer[byteRead] = '\0';
		if (cache == NULL)
			cache = ft_strdup("");
		temp = cache;
		cache = ft_strjoin(cache, buffer);
		free(temp);
	}
	free(buffer);
	if (byteRead == -1)
		return (free(buffer), free(cache), NULL);
	if (cache == NULL || cache[0] == '\0') 
		return (free(cache), NULL);
	return (cache);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*cache;
	char		*newPtr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cache = getCache(fd, cache);
	if (!cache)
		return (NULL);
	newPtr = ft_strchr(cache, '\n');
	line = extractLine(cache, newPtr);
	if (!line)
		return (free(cache), cache = NULL, NULL);
	cache = moveCache(cache, newPtr);
	return (line);
}

// # include <stdio.h>
// # include <fcntl.h>
// int	main(void)
// {
// 	int fd;
// 	char *nextLine;

// 	fd = open("data.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		return (1);
// 	}

// 	while (1)
// 	{
// 		nextLine = get_next_line(fd);

// 		if (nextLine == NULL)
// 			break ;

// 		printf("%s\n", nextLine);

// 		free(nextLine);

// 		nextLine = NULL;
// 	}
// 	close(fd);
// 	return (0);
// }