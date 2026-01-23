/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 22:10:45 by rfoo              #+#    #+#             */
/*   Updated: 2026/01/24 06:39:27 by rfoo             ###   ########.fr       */
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
	return ("");
}