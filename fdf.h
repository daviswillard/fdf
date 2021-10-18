/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 20:11:32 by dwillard          #+#    #+#             */
/*   Updated: 2021/08/10 20:11:35 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define PI 3.14159
# define BUFFER_SIZE 100

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include "keycode_mac.h"
# include "libft/libft.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fdf
{
	void	*mlx;
	void	*mlx_win;
	int		dim_x;
	int		dim_y;
	int		cur_x;
	int		cur_y;
	int		win_x;
	int		win_y;
	double	shy;
	double	shx;
	double	dz;
	double	dz1;
	double	x;
	double	x1;
	double	y;
	double	y1;
	double	z;
	double	z1;
	double	phi;
	double	cell_x;
	double	cell_y;
}				t_param;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

int		**read_map(char **argv, t_param **grid);

void	shift(t_param **grid, int **matrix);

void	matrix_works(t_param **grid, int **matrix);

void	drawing_lines(t_param *grid, t_data *img);

void	basis(t_param **grid);

char	*ft_strjoin_fdf(char *s1, char *s2);

void	assign_coord(t_param **grid, int call, int **matrix);

int		get_next_line(int fd, char **line);

int		key_hook(int keycode, t_param *grid);

#endif
