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

static void	read_matrix(t_param **grid, int **matrix)
{
	while ((*grid)->cur_y < (*grid)->dim_y)
	{
		(*grid)->cur_x = 0;
		while ((*grid)->cur_x < (*grid)->dim_x)
		{
			if ((*grid)->cur_x < (*grid)->dim_x - 1)
			{
				drawing_lines(*grid);
			}
			if ((*grid)->cur_y < (*grid)->dim_y - 1)
			{
				drawing_lines(*grid);
			}
		}
	}
}

static void	param_init(t_param **grid)
{
	*grid = malloc(sizeof(t_param));
	if (!*grid)
		exit(-1);
	(*grid)->dim_x = 0;
	(*grid)->dim_y = 0;
	(*grid)->cur_x = 0;
	(*grid)->cur_y = 0;
	(*grid)->cell_x = 0;
	(*grid)->cell_y = 0;
	(*grid)->x = 0;
	(*grid)->y = 0;
	(*grid)->z = 0;
	(*grid)->x1 = 0;
	(*grid)->y1 = 0;
}

int	main(int argc, char **argv)
{
	int		**matrix;
	t_param	*grid;

	if (argc != 2)
		return (-1);
	param_init(&grid);
	matrix = read_map(argv, &grid);
	grid->mlx = mlx_init();
	matrix_works(&grid);
	grid->mlx_win = mlx_new_window(grid->mlx, grid->win_x, grid->win_y, "FdF");
	read_matrix(&grid, matrix);
	return (0);
}
