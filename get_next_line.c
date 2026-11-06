/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardeau <mbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 15:48:22 by mbardeau          #+#    #+#             */
/*   Updated: 2026/11/05 15:48:22 by mbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_and_stash(int fd, char *stash)
{
	char		*tmp_buff;
	size_t		read_bytes;
	char		*tmp_stash;

	tmp_buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp_buff)
		return (NULL);
	while(!ft_strchr(stash, '\n'))
	{
		read_bytes = read(fd, tmp_buff, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		tmp_buff[read_bytes] = '\0';
		if (!stash)
			stash = ft_strdup(tmp_buff);
		else
		{
			tmp_stash = ft_strjoin(stash, tmp_buff);
			free(stash);
			stash = tmp_stash;
		}
	}
	free(tmp_buff);
	return (stash);
}

static char	*ft_extract_line(char *stash)
{
	char	*line;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!stash || stash[len] == '\0')
		return (NULL);
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_clean_stash(char *stash)
{
	char	*new_stash;
	int		i;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i + 1] == '\0')
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_substr(stash, i, ft_strlen(stash) - i);
	free(stash);
	stash = new_stash;
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_extract_line(stash);
	stash = ft_clean_stash(stash);
	return (line);
}
