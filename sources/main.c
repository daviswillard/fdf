#include "../fdf.h"

static void	param_init(param **grid)
{
	
}

int	main(int argc, char **argv)
{
	int		**matrix;
	int		y;
	param 	*grid;

	if (argc != 2)
		return (-1);
	matrix = read_map(argv, &grid);
	matrix_works(matrix, y);
	return (0);
}
