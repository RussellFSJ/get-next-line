/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 22:10:43 by rfoo              #+#    #+#             */
/*   Updated: 2026/01/24 07:03:39 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memcpy(void *dest, const void *src, size_t n);
static size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	strlen1;
	size_t	strlen2;
	char	*str;

	strlen1 = ft_strlen(s1);
	strlen2 = ft_strlen(s2);
	str = malloc(strlen1 + strlen2 + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, strlen1);
	ft_memcpy(str + strlen1, s2, strlen2);
	str[strlen1 + strlen2] = '\0';
	return (str);
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char *)dest;
	p2 = (unsigned char *)src;
	while (i < n)
	{
		p1[i] = p2[i];
		i++;
	}
	return (dest);
}

static size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
	{
		length++;
	}
	return (length);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
char	*get_line(const char *s)
{
	int		i;
	char	*line;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	line = malloc(i + s[i] == '\n' + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, s, i);
	if (s[i++] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}
