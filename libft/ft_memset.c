/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:21:22 by dwillard          #+#    #+#             */
/*   Updated: 2021/04/22 18:20:54 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	ch;
	unsigned char	*ret;
	size_t			ind;

	ind = 0;
	ch = c;
	ret = b;
	while (ind < len)
	{
		ret[ind] = ch;
		ind++;
	}
	return (b);
}
