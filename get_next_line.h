#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1000
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);

#endif
