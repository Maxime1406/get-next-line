#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test_GNL.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Erreur lors de l'ouverture du fichier");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}

	close(fd);
	return (0);
}