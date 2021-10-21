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


# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
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
	int		**matrix;
	double	shy;
	double	shx;
	double	sshy;
	double	sshx;
	double	trspd;
	double	dz;
	double	dz1;
	double	x;
	double	x1;
	double	y;
	double	y1;
	double	z;
	double	z1;
	double	ang;
	double	cell_x;
	double	cell_y;
	t_data	img;
}				t_param;

void	my_mlx_pixel_put(t_data *data, int x, int y, t_param *grid);

int		**read_map(char **argv, t_param **grid);

void	shift(t_param **grid, int **matrix);

void	matrix_works(t_param **grid, int **matrix);

void	read_matrix(t_param **grid, int **matrix, t_data *img);

void	drawing_lines(t_param *grid, t_data *img);

void	basis(t_param **grid);

char	*ft_strjoin_fdf(char *s1, char *s2);

void	assign_coord(t_param **grid, int call, int **matrix);

int		get_next_line(int fd, char **line);

int		key_hook(int keycode, t_param *grid);

#endif
