/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:10:57 by dwillard          #+#    #+#             */
/*   Updated: 2021/04/24 17:27:06 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		cc;
	size_t				ind;
	unsigned char		*ret;
	const unsigned char	*ssrc;

	ret = dst;
	ind = 0;
	cc = c;
	ssrc = src;
	while (ind < n)
	{
		ret[ind] = ssrc[ind];
		ind++;
		if (ssrc[ind - 1] == cc)
			return (dst + ind);
	}
	return (NULL);
}
