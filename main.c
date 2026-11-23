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

int main(int argc, char **argv)
{
    int     fd;
    char    *line;
    char    *filename;

    if (argc > 1)
        filename = argv[1];
    else
        filename = "test_GNL.txt";

    fd = open(filename, O_RDONLY);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return (0);
}

