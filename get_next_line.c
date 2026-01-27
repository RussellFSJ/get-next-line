/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 22:10:45 by rfoo              #+#    #+#             */
/*   Updated: 2026/01/27 20:22:55 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*s;
	char 		buffer[BUFFER_SIZE + 1];
	int			bytes_read;
	
	if (fd == -1)
		return (NULL);
	while (!ft_strchr(s, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		buffer[bytes_read] = '\0';
		s = ft_strjoin(s, buffer);
	}
	return (get_line(s));
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

