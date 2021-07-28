/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:41:54 by dwillard          #+#    #+#             */
/*   Updated: 2021/04/24 19:09:01 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char					*ret;
	size_t						ind;

	ret = s;
	ind = 0;
	if (c > 255)
		c %= 256;
	while (ind < n)
	{
		if (ret[ind] == c)
			return ((unsigned char *)(ret + ind));
		ind++;
	}
	return (NULL);
}
