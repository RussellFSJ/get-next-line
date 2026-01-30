/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 22:10:45 by rfoo              #+#    #+#             */
/*   Updated: 2026/01/30 21:41:01 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		buffer[BUFFER_SIZE + 1];
	size_t		bytes_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 0;
	while(!ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	line = process_line(stash);
	stash = update_stash(stash);
	return (line);
}

char	*process_line(const char *s)
{
	int		i;
	char	*line;

	i = 0;
	
	
}

char	*process_line(const char *s)
{
	int		i;
	char	*line;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	line = malloc(i + (s[i] == '\n') + 1);
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

char	*update_stash(char* stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	if (ft_strlen(stash) == 0)
	{
		free(stash);
		return (NULL);
	}
	i++;
	new_stash = malloc(ft_strlen(stash + i) + 1);
	if (!new_stash)
		return (NULL);
	j = 0;
	while(stash[i])
	{
		new_stash[j++] = stash[i++];
	}
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}
