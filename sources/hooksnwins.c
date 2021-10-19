/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooksnwins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:51:31 by dwillard          #+#    #+#             */
/*   Updated: 2021/10/19 15:51:33 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void arrow_press(int keycode, t_param *grid)
{
	if (keycode == KEY_UP)
		grid->shy -= grid->win_y * grid->dim_y * 0.05;
	else if (keycode == KEY_DOWN)
		grid->shy += grid->win_y * grid->dim_y * 0.05;
	else if (keycode == KEY_LEFT)
		grid->shx -= grid->win_x * grid->dim_x * 0.05;
	else if (keycode == KEY_RIGHT)
		grid->shx += grid->win_x * grid->dim_x * 0.05;
}

int	key_hook(int keycode, t_param *grid)
{
	(void)grid;
	if (keycode == KEY_ESCAPE)
		exit(0);
	else if (keycode == KEY_PAD_ADD)
	{
		grid->cell_x *= 1.05;
		grid->cell_y *= 1.05;
	}
	else if (keycode == KEY_PAD_SUB)
	{
		grid->cell_x *= 0.95;
		grid->cell_y *= 0.95;
	}
	else if (keycode >= 123 && keycode <= 126)
		arrow_press(keycode, grid);
	mlx_destroy_image(grid->mlx, grid->img.img);
	grid->img.img = mlx_new_image(grid->mlx, grid->win_x, grid->win_y);
	read_matrix(&grid, grid->matrix, &grid->img);
	mlx_put_image_to_window(grid->mlx, grid->mlx_win, grid->img.img, 0, 0);
	return (0);
}
