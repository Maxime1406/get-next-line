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

static char *ft_update_stash(char *stash, char *buf)
{
    char    *tmp_buff;

    if (!stash)
    {
        tmp_buff = ft_strdup(buf);
        return (tmp_buff);
    }
    tmp_buff = ft_strjoin(stash, buf);
    free(stash);
    return (tmp_buff);
}

static char *ft_read_and_stash(int fd, char *stash)
{
    char    *buf;
    int     bytes_read;

    buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buf)
        return (NULL);
    bytes_read = 1;
    while (bytes_read > 0)
    {
        bytes_read = read(fd, buf, BUFFER_SIZE);
        if (bytes_read <= 0)
            break ;
        buf[bytes_read] = '\0';
        stash = ft_update_stash(stash, buf);
        if (ft_strchr(buf, '\n'))
            break ;
    }
    free(buf);
    if (bytes_read < 0 || (bytes_read == 0 && (!stash || stash[0] == '\0')))
    {
        free(stash);
        stash = NULL;
    }
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
	if (!stash[i] || stash[i + 1] == '\0')
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_substr(stash, i + 1, ft_strlen(stash) - i);
	free(stash);
	return (new_stash);
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
