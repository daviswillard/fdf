/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:24:22 by dwillard          #+#    #+#             */
/*   Updated: 2021/04/24 17:51:40 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	ind;
	size_t	n;

	ind = 0;
	len = ft_strlen(dst);
	if (len < dstsize)
		n = len;
	else
		n = dstsize;
	if (dstsize - n == 0)
		return (ft_strlen (src) + n);
	while (*dst)
		dst++;
	while (src[ind] != '\0' && ind + n < dstsize - 1)
	{
		if (dstsize - n > 0)
		{
			*dst++ = src[ind];
			ind++;
		}
	}
	*dst = '\0';
	return (n + ft_strlen(src));
}
