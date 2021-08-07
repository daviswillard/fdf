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

void	basis(t_param **grid)
{
	float	tx;
	float	ty;
	float	tx1;
	float	ty1;

	tx = (*grid)->x;
	ty = (*grid)->y;
	tx1 = (*grid)->x1;
	ty1 = (*grid)->y1;
	(*grid)->x = (tx + ty) * sin(PI / 4);
	(*grid)->y = (-tx + ty) * sin(PI / 4) - (*grid)->z * 2;
	(*grid)->x1 = (tx1 + ty1) * sin(PI / 4);
	(*grid)->y1 = (-tx1 + ty1) * sin(PI / 4) - (*grid)->z1 * 2;
}
