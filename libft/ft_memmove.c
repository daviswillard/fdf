/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:23:21 by dwillard          #+#    #+#             */
/*   Updated: 2021/04/24 18:51:37 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ret;
	const char	*ssrc;

	ret = dst;
	ssrc = src;
	if (ret == ssrc)
		return (dst);
	if (ret > ssrc)
	{
		ret = ret + (len - 1);
		ssrc = ssrc + (len - 1);
		while (len-- > 0)
			*ret-- = *ssrc--;
		return (dst);
	}
	while (len-- > 0)
		*ret++ = *ssrc++;
	return (dst);
}
