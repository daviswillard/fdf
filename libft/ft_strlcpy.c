/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:39:30 by dwillard          #+#    #+#             */
/*   Updated: 2021/04/24 17:49:13 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	ind;
	size_t	len;

	ind = 0;
	len = ft_strlen(src);
	if (!src)
		return (len);
	while (ind < dstsize)
	{
		dst[ind] = src[ind];
		if (!src[ind])
			return (len);
		if (ind == dstsize - 1)
		{
			dst[ind] = '\0';
			return (len);
		}
		ind++;
	}
	return (len);
}
