/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:41:09 by dwillard          #+#    #+#             */
/*   Updated: 2021/04/22 19:47:11 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	int		ind;

	ind = 0;
	ret = malloc(sizeof(*ret) * ft_strlen(s1) + 1);
	if (ret == NULL)
		return (NULL);
	while (*s1)
		ret[ind++] = *s1++;
	ret[ind] = 0;
	return (ret);
}
