/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:02:15 by dwillard          #+#    #+#             */
/*   Updated: 2021/04/24 17:26:20 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		ind;
	char		*ret;
	const char	*ssrc;

	ret = dst;
	ssrc = src;
	if (ret == ssrc)
		return (dst);
	ind = 0;
	while (ind < n)
	{
		ret[ind] = ssrc[ind];
		ind++;
	}
	return (dst);
}
