/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 16:52:28 by dwillard          #+#    #+#             */
/*   Updated: 2021/08/07 16:52:31 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	shift(t_param **grid, int **matrix)
{
	if ((*grid)->dim_x % 2)
		(*grid)->cur_x = (*grid)->dim_x / 2 + 1;
	else
		(*grid)->cur_x = (*grid)->dim_x / 2;
	if ((*grid)->dim_y % 2)
		(*grid)->cur_y = (*grid)->dim_y / 2 + 1;
	else
		(*grid)->cur_y = (*grid)->dim_y / 2;
	assign_coord(grid, 0, matrix);
	(*grid)->shx = (*grid)->win_x / 2 - (*grid)->x * (*grid)->cell_x;
	(*grid)->shy = (*grid)->win_y / 2 - ((*grid)->y + (*grid)->z)
		* (*grid)->cell_y;
}

void	basis(t_param **grid)
{
	float	tx;
	float	ty;
	float	tx1;
	float	ty1;
	float	phi;

	phi = (*grid)->phi;
	tx = (*grid)->x;
	ty = (*grid)->y;
	tx1 = (*grid)->x1;
	ty1 = (*grid)->y1;
	if ((*grid)->dz == 0)
		(*grid)->dz = 1;
	(*grid)->z *= ((*grid)->dz1 / (*grid)->dz);
	(*grid)->z1 *= ((*grid)->dz1 / (*grid)->dz);
	(*grid)->x = tx * cos(phi) + ty * sin(phi);
	(*grid)->y = -tx * sin(phi) + ty * cos(phi) - (*grid)->z;
	(*grid)->x1 = tx1 * cos(phi) + ty1 * sin(phi);
	(*grid)->y1 = -tx1 * sin(phi) + ty1 * cos(phi) - (*grid)->z1;
}

char	*ft_strjoin_fdf(char *s1, char *s2)
{
	int		cntr1;
	int		cntr2;
	int		cntr;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	cntr = -1;
	cntr1 = 0;
	cntr2 = 0;
	while (s1[cntr1])
		cntr1++;
	while (s2[cntr2])
		cntr2++;
	ret = malloc(sizeof(*ret) * (cntr1 + cntr2 + 2));
	if (ret == NULL)
		return (NULL);
	while (++cntr < cntr1)
		ret[cntr] = s1[cntr];
	ret[cntr + cntr2 + 1] = '\0';
	ret[cntr + cntr2] = '\n';
	while (--cntr2 >= 0)
		ret[cntr + cntr2] = s2[cntr2];
	return (ret);
}
