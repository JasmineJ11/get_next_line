/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiawli <jiawli@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:00:13 by jiawli            #+#    #+#             */
/*   Updated: 2025/05/19 14:00:25 by jiawli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dest;
	size_t	i;

	len = 0;
	i = 0;
	while (s[len])
	{
		len++;
	}
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*dest;

	s_len = 0;
	if (s == NULL)
		return (NULL);
	while (s[s_len])
	{
		s_len++;
	}
	if (start > s_len)
		len = 0;
	if (len > s_len - start)
		len = s_len - start;
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s + (size_t)start, len);
	dest[len] = '\0';
	return (dest);
}

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			i;

	dest = (unsigned char *)destination;
	src = (unsigned char *)source;
	i = 0;
	while (i < num)
	{
		dest[i] = src[i];
		i++;
	}
	return (destination);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*dest;

	s1_len = 0;
	s2_len = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[s1_len])
		s1_len++;
	while (s2[s2_len])
		s2_len++;
	dest = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (dest != NULL)
	{
		ft_memcpy(dest, s1, s1_len);
		ft_memcpy(dest + s1_len, s2, s2_len);
		dest[s1_len + s2_len] = '\0';
	}
	free(s1);
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	chr;
	size_t			i;

	str = (unsigned char *)s;
	chr = (unsigned char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == chr)
		{
			return ((char *)str + i);
		}
		i++;
	}
	if (chr == '\0')
	{
		return ((char *)str + i);
	}
	return (NULL);
}
