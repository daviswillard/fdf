/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:46:47 by dwillard          #+#    #+#             */
/*   Updated: 2021/08/03 16:46:48 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	map_x(int *x_axis, const char *line)
{
	int			temp;

	temp = 0;
	while (*line != '\0')
	{
		if (ft_isdigit(*line))
		{
			while (ft_isdigit(*line))
				line++;
			(temp)++;
		}
		if (*line == ',')
			while (*line != ' ' && *line != '\0' && *line != '\n')
				line++;
		while (!ft_isdigit(*line) && *line != '\0')
			line++;
	}
	if (*x_axis == 0)
		*x_axis = temp;
	else if (*x_axis != temp)
	{
		ft_putendl_fd("Found wrong line length. Exiting now.", 1);
		exit(0);
	}
}

static char	*read_line(int *x_axis, int *y_axis, int fd, char *buf)
{
	char	*line;
	char	*temp;
	int		control;

	control = get_next_line(fd, &line);
	while (control)
	{
		map_x(x_axis, line);
		temp = buf;
		buf = ft_strjoin_fdf(buf, line);
		if (!buf || control < 0)
			exit(errno);
		(*y_axis)++;
		free(temp);
		free(line);
		control = get_next_line(fd, &line);
	}
	temp = buf;
	buf = ft_strjoin_fdf(buf, line);
	free(temp);
	free(line);
	if (buf && control >= 0)
		return (buf);
	exit(errno);
}

static void	skip(char **line)
{
	while (**line == ' ' || **line == '\n')
		(*line)++;
	if (**line == '-')
		(*line)++;
	while (ft_isdigit(**line))
		(*line)++;
	if (**line == ',')
		while (**line != ' ' && **line != '\0')
			(*line)++;
}

static int	**assign_matrix(int x_axis, int y_axis, char *line)
{
	int		x_temp;
	int		y_temp;
	int		**ret;

	ret = malloc(sizeof(*ret) * (x_axis + y_axis) + 1);
	if (!ret)
		exit(errno);
	y_temp = 0;
	while (y_temp < y_axis)
	{
		x_temp = 0;
		ret[y_temp] = malloc(sizeof(**ret) * x_axis);
		if (!ret[y_temp])
			exit(errno);
		while (x_temp < x_axis)
		{
			ret[y_temp][x_temp] = ft_atoi(line);
			x_temp++;
			skip(&line);
		}
		y_temp++;
	}
	ret[y_temp] = NULL;
	return (ret);
}

int	**read_map(char **argv, t_param **grid)
{
	int			**ret;
	int			x_axis;
	int			y_axis;
	int			fd;
	char		*line;

	x_axis = 0;
	y_axis = 0;
	fd = open(argv[1], O_RDONLY);
	line = ft_strdup("");
	if (!line || fd < 0)
		exit(errno);
	line = read_line(&x_axis, &y_axis, fd, line);
	close(fd);
	if (ft_strlen(line) && !y_axis)
		y_axis++;
	ret = assign_matrix(x_axis, y_axis, line);
	free(line);
	(*grid)->dim_x = x_axis;
	(*grid)->dim_y = y_axis;
	return (ret);
}
