#include "../fdf.h"

int	main(int argc, char **argv)
{
	int		**matrix;
	int		y;
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!")
	if (argc != 2)
		return (-1);
	matrix = read_map(argv, &y);
	term(matrix, mlx, mlx_win, y);
	mlx_loop(mlx);
	return (0);
}
