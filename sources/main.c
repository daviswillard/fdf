/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:47:06 by dwillard          #+#    #+#             */
/*   Updated: 2021/08/03 16:47:08 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	helper(t_param **grid, int **matrix)
{
	(*grid)->y = (*grid)->cur_y;
	(*grid)->y1 = (*grid)->cur_y;
	(*grid)->x = (*grid)->cur_x;
	(*grid)->x1 = (*grid)->cur_x;
	(*grid)->z = matrix[(*grid)->cur_y][(*grid)->cur_x];
	(*grid)->z1 = matrix[(*grid)->cur_y][(*grid)->cur_x];
}

void	assign_coord(t_param **grid, int call, int **matrix)
{
	helper(grid, matrix);
	if (call == 1)
	{
		(*grid)->x1 = (*grid)->cur_x + 1;
		(*grid)->z1 = matrix[(*grid)->cur_y][(*grid)->cur_x + 1];
	}
	if (call == 2)
	{
		(*grid)->y1 = (*grid)->cur_y + 1;
		(*grid)->z1 = matrix[(*grid)->cur_y + 1][(*grid)->cur_x];
	}
	basis(grid);
}

void	read_matrix(t_param **grid, int **matrix, t_data *img)
{
	shift(grid, matrix);
	(*grid)->cur_y = 0;
	while ((*grid)->cur_y < (*grid)->dim_y - 1)
	{
		(*grid)->cur_x = 0;
		(*grid)->y = (*grid)->cur_y;
		while ((*grid)->cur_x < (*grid)->dim_x - 1)
		{
			assign_coord(grid, 1, matrix);
			drawing_lines(*grid, img);
			assign_coord(grid, 2, matrix);
			drawing_lines(*grid, img);
			(*grid)->cur_x++;
			assign_coord(grid, 2, matrix);
			drawing_lines(*grid, img);
		}
		(*grid)->cur_y++;
	}
}

static void	param_init(t_param **grid)
{
	*grid = malloc(sizeof(t_param));
	if (!*grid)
		exit(errno);
	(*grid)->dim_x = 0;
	(*grid)->dim_y = 0;
	(*grid)->cur_x = 0;
	(*grid)->cur_y = 0;
	(*grid)->cell_x = 0;
	(*grid)->cell_y = 0;
	(*grid)->sshx = 0;
	(*grid)->sshy = 0;
	(*grid)->trspd = 1;
	(*grid)->x = 0;
	(*grid)->y = 0;
	(*grid)->z = 0;
	(*grid)->x1 = 0;
	(*grid)->y1 = 0;
	(*grid)->z1 = 0;
	(*grid)->ang = PI / 4;
}

int	main(int argc, char **argv)
{
	t_param	*grid;

	if (argc != 2)
	{
		ft_putstr_fd("wrong number of arguments\n", 1);
		return (-1);
	}
	param_init(&grid);
	grid->matrix = read_map(argv, &grid);
	grid->mlx = mlx_init();
	matrix_works(&grid, grid->matrix);
	grid->mlx_win = mlx_new_window(grid->mlx, grid->win_x, grid->win_y, "FdF");
	grid->img.img = mlx_new_image(grid->mlx, grid->win_x, grid->win_y);
	grid->img.addr = mlx_get_data_addr(grid->img.img,
			&grid->img.bits_per_pixel, &grid->img.line_length,
			&grid->img.endian);
	read_matrix(&grid, grid->matrix, &grid->img);
	mlx_put_image_to_window(grid->mlx, grid->mlx_win, grid->img.img, 0, 0);
	mlx_hook(grid->mlx_win, KEYPRESS, 0, key_hook, grid);
	mlx_loop(grid->mlx);
	return (0);
}
