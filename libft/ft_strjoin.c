/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:43:49 by dwillard          #+#    #+#             */
/*   Updated: 2021/04/17 16:37:19 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		cntr1;
	int		cntr2;
	int		cntr;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	cntr = -1;
	cntr1 = 0;
	cntr2 = 0;
	while (s1[cntr1])
		cntr1++;
	while (s2[cntr2])
		cntr2++;
	ret = malloc(sizeof(*ret) * (cntr1 + cntr2 + 1));
	if (ret == NULL)
		return (NULL);
	while (++cntr < cntr1)
		ret[cntr] = s1[cntr];
	ret[cntr + cntr2] = '\0';
	while (--cntr2 >= 0)
		ret[cntr + cntr2] = s2[cntr2];
	return (ret);
}
