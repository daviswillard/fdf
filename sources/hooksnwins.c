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

static void	arrow_press(int keycode, t_param *grid)
{
	if (keycode == KEY_UP)
		grid->sshy += 10 * grid->trspd;
	else if (keycode == KEY_DOWN)
		grid->sshy -= 10 * grid->trspd;
	else if (keycode == KEY_LEFT)
		grid->sshx += 10 * grid->trspd;
	else if (keycode == KEY_RIGHT)
		grid->sshx -= 10 * grid->trspd;
	else if (keycode == KEY_S)
		grid->trspd += 0.5;
	else if (keycode == KEY_A && grid->trspd > 0.5)
		grid->trspd -= 0.5;
}

static void	zoom(t_param *grid, int keycode)
{
	if (keycode == KEY_PAD_ADD)
	{
		grid->cell_x *= 1.05;
		grid->cell_y *= 1.05;
	}
	else if (keycode == KEY_PAD_SUB)
	{
		grid->cell_x *= 0.95;
		grid->cell_y *= 0.95;
	}
}

int	key_hook(int keycode, t_param *grid)
{
	static t_param	*reset = NULL;

	if (!reset)
		copy_param(grid, &reset);
	if (keycode == KEY_ESCAPE)
		exit(0);
	else if (keycode == KEY_PAD_ADD || keycode == KEY_PAD_SUB)
		zoom(grid, keycode);
	else if ((keycode >= 123 && keycode <= 126) || keycode == KEY_S
		|| keycode == KEY_A)
		arrow_press(keycode, grid);
	else if (keycode == KEY_R)
		copy_param(reset, &grid);
	mlx_destroy_image(grid->mlx, grid->img.img);
	grid->img.img = mlx_new_image(grid->mlx, grid->win_x, grid->win_y);
	read_matrix(&grid, grid->matrix, &grid->img);
	mlx_put_image_to_window(grid->mlx, grid->mlx_win, grid->img.img, 0, 0);
	return (0);
}
