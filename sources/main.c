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

static void	assign_coord(t_param **grid, int call, int **matrix)
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

static void	read_matrix(t_param **grid, int **matrix)
{
	while ((*grid)->cur_y < (*grid)->dim_y - 1)
	{
		(*grid)->cur_x = 0;
		(*grid)->y = (*grid)->cur_y;
		while ((*grid)->cur_x < (*grid)->dim_x - 1)
		{
			assign_coord(grid, 1, matrix);
			drawing_lines(*grid);
			assign_coord(grid, 2, matrix);
			drawing_lines(*grid);
			(*grid)->cur_x++;
			assign_coord(grid, 2, matrix);
			drawing_lines(*grid);
		}
		(*grid)->cur_y++;
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
	(*grid)->z1 = 0;
	(*grid)->phi = PI / 4;
}

int	main(int argc, char **argv)
{
	int		**matrix;
	t_param	*grid;
//	int		counter = 0;
//	int		counter1;


	if (argc != 2)
	{
		ft_putstr_fd("wrong number of arguments\n", 1);
		return (-1);
	}
	param_init(&grid);
	matrix = read_map(argv, &grid);
	grid->mlx = mlx_init();
	matrix_works(&grid, matrix);
	grid->mlx_win = mlx_new_window(grid->mlx, grid->win_x, grid->win_y, "FdF");
/*	while (counter < grid->dim_y)
	{
		counter1 = 0;
		while (counter1 < grid->dim_x)
		{
			printf("x, y, matrix(x, y):	%d, %d, %d\n", counter1, counter,
				   matrix[counter][counter1]);
			counter1++;
		}
		counter++;
	}*/
	read_matrix(&grid, matrix);
	mlx_loop(grid->mlx);
	return (0);
}
