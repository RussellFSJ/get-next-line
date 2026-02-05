/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russ1337 <russ1337@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 22:10:45 by rfoo              #+#    #+#             */
/*   Updated: 2026/02/06 05:16:35 by russ1337         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*handle_read_fail(char *stash);
static char	*process_line(const char *s);
static char	*update_stash(char* stash);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 0;
	while (!stash || !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (handle_read_fail(stash));
		if (bytes_read == 0)
			break;
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	if (!stash || *stash == '\0')
		return (NULL);
	line = process_line(stash);
	stash = update_stash(stash);
	return (line);
}

static char	*handle_read_fail(char *stash)
{
	if (stash)
	{
		free(stash);
		stash = NULL;
	}
	return (NULL);
}

static char	*process_line(const char *s)
{
	int		i;
	char	*line;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, s, i);
	line[i] = '\0';
	return (line);
}

static char	*update_stash(char* stash)
{
	int		i;
	size_t	length;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	length = ft_strlen(stash + i);
	new_stash = malloc(length + 1);
	if (!new_stash)
		return (NULL);
	ft_memcpy(new_stash, stash + i, length);
	new_stash[length] = '\0';
	free(stash);
	return (new_stash);
}
