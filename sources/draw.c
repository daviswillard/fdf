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
	while ((int)x != (int)grid->x1 && (int)y != (int)grid->y1)
	{
		mlx_pixel_put(grid->mlx, grid->mlx_win, x + grid->shx,
			y * 0.5 + grid->shy, 0xFFFFFF);
		x += dx;
		y += dy;
	}
}

static void	get_z_dim(t_param **grid, int **matrix)
{
	int		i;
	int		j;

	(*grid)->dz = 0;
	j = 0;
	while (j < (*grid)->dim_y)
	{
		i = 0;
		while (i < (*grid)->dim_x)
		{
			if ((*grid)->dz < absol(matrix[j][i]))
				(*grid)->dz = absol(matrix[j][i]);
			i++;
		}
		j++;
	}
	if ((*grid)->dz > (*grid)->dim_y + (*grid)->dim_x)
	{
		(*grid)->dz1 = (*grid)->dim_y + (*grid)->dim_x;
		(*grid)->win_y *= 2;
		if ((*grid)->win_y > 1250)
			(*grid)->win_y = 1250;
	}
	else
		(*grid)->dz1 = (*grid)->dz;
}

void	matrix_works(t_param **grid, int **matrix)
{
	if ((*grid)->dim_x <= 5)
		(*grid)->win_x = 250;
	else if ((*grid)->dim_x > 5 && (*grid)->dim_x < 25)
		(*grid)->win_x = (*grid)->dim_x * 50;
	else
		(*grid)->win_x = 1250;
	if ((*grid)->dim_y <= 5)
		(*grid)->win_y = 250;
	else if ((*grid)->dim_y > 5 && (*grid)->dim_y < 25)
		(*grid)->win_y = (*grid)->dim_y * 50;
	else
		(*grid)->win_y = 1250;
	if ((*grid)->dim_y < 50)
		(*grid)->cell_y = 25;
	else if ((*grid)->dim_y >= 50 && (*grid)->dim_y <= 310)
		(*grid)->cell_y = (*grid)->win_y / (*grid)->dim_y;
	else
		(*grid)->cell_y = 3;
	if ((*grid)->dim_x < 50)
		(*grid)->cell_x = 25;
	else if ((*grid)->dim_x >= 50 && (*grid)->dim_x <= 310)
		(*grid)->cell_x = (*grid)->win_x / (*grid)->dim_x;
	else
		(*grid)->cell_x = 3;
	get_z_dim(grid, matrix);
}
