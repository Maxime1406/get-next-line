#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*============================================================================*/
/*                    	     INCLUDE STANDARDS LIBRARIES		              */
/*============================================================================*/

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>

/*============================================================================*/
/*                          	UTILITIES FUNCTION                            */
/*============================================================================*/

char	*get_next_line(int fd);

#endif