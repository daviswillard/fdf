#ifndef FDF_H
# define FDF_H

# define PI 3.14159

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line.h"

typedef struct s_fdf
{
	int		dim_x;
	int		dim_y;
	int		cur_x;
	int		cur_y;
	int		cell_x;
	int		cell_y;
	int		win_x;
	int		win_y;
	float	x;
	float	x1;
	float	y;
	float	y1;
	int		z;
	void	*mlx;
	void	*mlx_win;
}				t_param;

int		**read_map(char **argv, t_param **grid);

void	matrix_works(t_param **grid);

void	drawing_lines(t_param *grid);

#endif
