/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:45:44 by dwillard          #+#    #+#             */
/*   Updated: 2021/04/24 17:28:03 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				ind;
	const unsigned char	*ss1;
	const unsigned char	*ss2;

	ss1 = s1;
	ss2 = s2;
	ind = 0;
	while (ind < n)
	{
		if (ss1[ind] != ss2[ind])
			return ((int)(ss1[ind] - ss2[ind]));
		ind++;
	}
	return (0);
}
