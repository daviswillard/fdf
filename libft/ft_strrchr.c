/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:15:01 by dwillard          #+#    #+#             */
/*   Updated: 2021/04/24 17:47:12 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		ind;
	char	ch;

	ch = c;
	ind = 0;
	while (*s)
	{
		s++;
		ind++;
	}
	while (ind)
	{
		if (*s-- == ch)
			return ((char *)(s + 1));
		ind--;
	}
	if (*s == ch)
		return ((char *)s);
	return (NULL);
}
