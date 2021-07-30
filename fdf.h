#ifndef FDF_H
# define FDF_H

# define PI 3.14159

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line.h"

typedef struct	s_fdf
{
	int		dim_x;
	int		dim_y;
	int		cell_x;
	int		cell_y;
	float	x;
	float	y;
	float	z;
}				param;

int		**read_map(char **argv, param **grid);

void		matrix_works(int **matrix, int y);

#endif
