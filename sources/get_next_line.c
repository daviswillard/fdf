#include "../fdf.h"

static int	condition_zero(char **line, int fd, char **buf)
{
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	*buf = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!*buf || read(fd, buf, 0))
	{
		free(*buf);
		return (-1);
	}
	return (0);
}

static int	buffer_works(char **line, char **tail, char *buf)
{
	char	*temp;

	if (tail)
	{
		*tail = ft_strchr(buf, '\n');
		*(*tail)++ = '\0';
		*tail = ft_strdup(*tail);
		if (!*tail)
			return (-1);
	}
	temp = *line;
	*line = ft_strjoin(*line, buf);
	if (!*line)
		return (-1);
	free(temp);
	if (tail)
		free(buf);
	return (1);
}

static int	check_tail(char **line, char **tail, char **buf)
{
	char		*tempest;
	char		*temp;

	if (*tail)
	{
		tempest = ft_strchr(*tail, '\n');
		if (tempest)
		{
			*tempest++ = '\0';
			*line = ft_strdup(*tail);
			temp = *tail;
			*tail = ft_strdup(tempest);
			free(temp);
			free(*buf);
			return (1);
		}
		*line = ft_strdup(*tail);
		free(*tail);
		*tail = NULL;
	}
	else
		*line = ft_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char		*tail[4096];
	char			*buf;
	size_t			bytes;

	if (condition_zero(line, fd, &buf))
		return (-1);
	if (check_tail(line, &tail[fd], &buf))
		return (1);
	bytes = read(fd, buf, BUFFER_SIZE);
	while (bytes > 0)
	{
		buf[bytes] = '\0';
		if (ft_strchr(buf, '\n') != NULL)
			return (buffer_works(line, &tail[fd], buf));
		if (buffer_works(line, NULL, buf) == -1)
			return (-1);
		bytes = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (bytes < 0)
		return (-1);
	return (0);
}
