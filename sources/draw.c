/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:46:27 by dwillard          #+#    #+#             */
/*   Updated: 2021/08/03 16:46:29 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static float	absol(float a)
{
	if (a >= 0)
		return (a);
	else
		return (-a);
}

static float	maxim(float a, float b)
{
	if (a > b || a == b)
		return (a);
	else
		return (b);
}

void	drawing_lines(t_param *grid)
{
	float	dx;
	float	dy;
	float	x;
	float	y;
	int		norm;

	grid->x1 *= grid->cell_x;
	grid->y1 *= grid->cell_y;
	x = grid->x * grid->cell_x;
	y = grid->y * grid->cell_y;
	dx = grid->x1 - x;
	dy = grid->y1 - y;
	norm = maxim(absol(dx), absol(dy));
	dx /= norm;
	dy /= norm;
	printf("\ndx:	%f, dy	%f\n", dx, dy);
	printf("\nx:	%f, y	%f\n", x, y);
	printf("\nx1:	%f, y1	%f\n\n\n\n", grid->x1, grid->y1);
	while ((int)x != (int)grid->x1 && (int)y != (int)grid->y1)
	{
		mlx_pixel_put(grid->mlx, grid->mlx_win, x + 50, y + 250, 0x00FFFFFF);
		printf("x:	%f, y:	%f\n", x, y);
		x += dx;
		y += dy;
	}
}

static void	get_z_dim(t_param **grid, int **matrix)
{
	int		i;
	int		j;
	int 	max;

	max = 0;
	j = 0;
	while (j < (*grid)->dim_y)
	{
		i = 0;
		while (i < (*grid)->dim_x)
		{
			if (max < absol(matrix[j][i]))
				max = absol(matrix[j][i]);
			i++;
		}
	j++;
	}

}

void	matrix_works(t_param **grid, int **matrix)
{
	if ((*grid)->dim_x <= 5)
		(*grid)->win_x = 250;
	else if ((*grid)->dim_x > 5 && (*grid)->dim_x < 20)
		(*grid)->win_x = (*grid)->dim_x * 50;
	else
		(*grid)->win_x = 1000;
	if ((*grid)->dim_x <= 5)
		(*grid)->win_y = 250;
	else if ((*grid)->dim_y > 5 && (*grid)->dim_y < 20)
		(*grid)->win_y = (*grid)->dim_y * 50;
	else
		(*grid)->win_y = 1000;
	if ((*grid)->win_y < 1000)
		(*grid)->cell_y = 20;
	else if ((*grid)->dim_y >= 50 && (*grid)->dim_y <= 200)
		(*grid)->cell_y = (*grid)->win_y / (*grid)->dim_y;
	else
		(*grid)->cell_y = 4;
	if ((*grid)->win_x < 1000)
		(*grid)->cell_x = 20;
	else if ((*grid)->dim_x >= 50 && (*grid)->dim_x <= 200)
		(*grid)->cell_x = (*grid)->win_x / (*grid)->dim_x;
	else
		(*grid)->cell_x = 4;
	get_z_dim(grid, matrix);
}
