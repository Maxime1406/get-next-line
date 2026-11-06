/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardeau <mbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 10:36:08 by mbardeau          #+#    #+#             */
/*   Updated: 2026/11/06 12:57:57 by mbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	len_str;
	int		i;

	i = 0;
	len_str = ft_strlen(s);
	dest = malloc(sizeof(char) * (len_str + 1));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char    *ft_strjoin(const char *s1, const char *s2)
{
    char    *dest;
    size_t  i;
    size_t  j;

    if (!s1 || !s2)
        return (NULL);
    dest = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (!dest)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        dest[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
    {
        dest[i + j] = s2[j];
        j++;
    }
    dest[i + j] = '\0';
    return (dest);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
	{
		dest = malloc(1 * sizeof(char));
		dest[0] = '\0';
		return (dest);
	}
	if (len > len_s - start)
		len = len_s - start;
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	return (dest);
}
