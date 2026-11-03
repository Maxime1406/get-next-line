/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardeau <mbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 10:36:54 by mbardeau          #+#    #+#             */
/*   Updated: 2026/11/02 10:36:54 by mbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static char		*ft_extract_line(char *stash)
{
	char	*line;
	int		i;
	int		len;

	i = 0;
	if (!stash || stash[i] == '\0')
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		len++;
	if (stash[i] == '\n')
		len++;
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = stash[i];
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char	*line;
	size_t	read_bytes;
	int		i;

	read_bytes = read(fd, stash, BUFFER_SIZE);
	if (read_bytes > 0)
	{
		i = 0;
		line = ft_extract_line(stash);
		while (line[i])
		{
			write(1, &line[i], 1);
			i++;
		}
		return (line);
	}
	return (NULL);
}