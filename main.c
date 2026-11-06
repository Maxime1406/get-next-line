/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardeau <mbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 15:48:30 by mbardeau          #+#    #+#             */
/*   Updated: 2026/11/05 15:48:30 by mbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line = NULL;

	fd = open("test_GNL.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Erreur lors de l'ouverture du fichier");
		return (1);
	}
	while (!ft_strchr(line, '\0'))
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
