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

char	*move_cache(char *cache, char *newptr) 
{
	char	*newcache;

	if (cache == NULL || newptr == NULL)
		return (free(cache), NULL);
	newcache = ft_strdup(newptr + 1);
	free(cache);
	cache = NULL;
	return (newcache);
}

char	*extract_line(char *cache, char *newptr)
{
	size_t	linelen;
	char	*line;

	if (cache == NULL)
		return (NULL);
	if (newptr != NULL)
	{
		linelen = (newptr - cache) + 1;
		line = ft_substr(cache, 0, linelen);
		return (line);
	}
	else
	{
		line = ft_strdup(cache);
		return (line);
	}
}

char	*safe_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}

static char	*get_cache(int fd, char *cache)
{
	char	*buffer;
	int		byteread;

	buffer = malloc((BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (free(cache), cache = NULL, NULL);
	byteread = 0;
	while ((cache == NULL || !ft_strchr(cache, '\n')))
	{
		byteread = read(fd, buffer, BUFFER_SIZE);
		if (byteread <= 0)
			break ;
		buffer[byteread] = '\0';
		if (cache == NULL)
			cache = ft_strdup("");
		cache = ft_strjoin(cache, buffer);
	}
	safe_free(&buffer);
	if (byteread == -1)
		return (free(buffer), free(cache), NULL);
	if (cache == NULL || cache[0] == '\0')
		return (safe_free(&cache));
	return (cache);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*cache;
	char		*newptr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cache = get_cache(fd, cache);
	if (!cache)
		return (NULL);
	newptr = ft_strchr(cache, '\n');
	line = extract_line(cache, newptr);
	if (!line)
		return (free(cache), cache = NULL, NULL);
	cache = move_cache(cache, newptr);
	return (line);
}
