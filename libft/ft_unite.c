/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unite.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:21:44 by dwillard          #+#    #+#             */
/*   Updated: 2021/10/22 21:21:46 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Function receives array of strings **split, allocates memory on heap and
 * returns string, that is created by joining all strings from split and
 * divides them by symbol div. In short, this is reverse ft_split*/

static char	*combine(char *ret, char *divv, char **split)
{
	char	*temp;

	temp = ret;
	if (!temp)
		return (NULL);
	ret = ft_strjoin(ret, divv);
	free(temp);
	temp = ret;
	if (!temp)
		return (NULL);
	ret = ft_strjoin(ret, *(split + 1));
	free(temp);
	return (ret);
}

char	*ft_unite(char **split, char div)
{
	char	*ret;
	char	*divv;

	if (!split || !*split)
		return (NULL);
	divv = ft_calloc(2, 1);
	if (!divv)
		return (NULL);
	divv[0] = div;
	ret = ft_strdup(*split);
	while (*(split + 1))
	{
		ret = combine(ret, divv, split);
		if (!ret)
			return (NULL);
		split++;
	}
	free(divv);
	return (ret);
}
