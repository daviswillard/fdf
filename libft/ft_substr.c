/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:04:07 by dwillard          #+#    #+#             */
/*   Updated: 2021/04/17 15:40:46 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*substr;
	int					index;
	unsigned int		length;

	length = ft_strlen(s);
	index = 0;
	substr = malloc(sizeof(*substr) * (len) + 1);
	if (substr == NULL)
		return (NULL);
	while (s[start] && len > 0 && start < length)
	{
		substr[index++] = s[start++];
		len--;
	}
	substr[index] = 0;
	return (substr);
}
