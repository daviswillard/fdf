#include "../fdf.h"

static void	map_x(int *x_axis, char *line)
{
	char	*lin;
	int		isd;

	lin = line;
	isd = ft_isdigit(*lin);
	while (*lin != '\0')
	{
		if (isd)
		{
			while (*lin != ' ' || *lin != '\0')
				lin++;
			(*x_axis)++;
		}
		while (!ft_isdigit(*lin) && *lin != '\0')
			lin++;
		isd = ft_isdigit(*lin);
	}
}

static char	*read_line(int *x_axis, int *y_axis, int fd)
{
	char	*line;
	char	*buf;
	char	*temp;
	int		control;

	buf = ft_strdup("");
	control = get_next_line(fd, &line);
	map_x(x_axis, line);
	while (control)
	{
		temp = buf;
		buf = ft_strjoin(buf, line);
		if (!buf || control < 0)
			exit(-2);
		(*y_axis)++;
		free(temp);
		temp = NULL;
		control = get_next_line(fd, &line);
	}
	temp = buf;
	buf = ft_strjoin(buf, line);
	free(temp);
	(*y_axis)++;
	if (buf)
		return (buf);
	exit(-2);
}

int	**read_map(char **argv)
{
	int		**ret;
	int		x_axis;
	int		y_axis;
	int		fd;
	char	*line;

	x_axis = 0;
	y_axis = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(-1);
	line = read_line(&x_axis, &y_axis, fd);
	close(fd);
	return (**ret);
}
