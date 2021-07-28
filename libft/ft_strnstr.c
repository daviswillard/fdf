/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:20:37 by dwillard          #+#    #+#             */
/*   Updated: 2021/04/24 17:47:45 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	ind;
	size_t	count;

	count = 0;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (count < len && *haystack)
	{
		if (*haystack == *needle)
		{
			ind = 0;
			while (haystack[ind] && needle[ind] && haystack[ind] == needle[ind])
				ind++;
			if (count + ind > len)
				return (NULL);
			if (needle[ind] == '\0')
				return ((char *)haystack);
		}
		haystack++;
		count++;
	}
	if (*haystack == *needle)
		return (0);
	return (NULL);
}
