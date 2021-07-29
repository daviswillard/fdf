#ifndef FDF_H
# define FDF_H

# define PI 3.14159

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line.h"

int		**read_map(char **argv, int *y_axis);

void	term(int **matrix, void *mlx, void *mlx_win, int y);

#endif
