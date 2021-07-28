/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:48:39 by dwillard          #+#    #+#             */
/*   Updated: 2021/04/18 16:04:28 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	left(int end, int size, char const *s1, char const *set)
{
	int		sol;
	int		ind;
	int		bgn;

	bgn = 0;
	while (bgn < end)
	{
		ind = 0;
		sol = 0;
		while (ind < size)
		{
			if (s1[bgn] == set[ind])
				sol++;
			ind++;
		}
		if (!sol)
			return (bgn);
		bgn++;
	}
	return (bgn);
}

static int	right(int bgn, int size, char const *s1, char const *set)
{
	int		sol;
	int		ind;
	int		end;

	end = ft_strlen(s1);
	while (end > bgn)
	{
		ind = 0;
		sol = 0;
		while (ind <= size)
		{
			if (s1[end] == set[ind])
				sol++;
			ind++;
		}
		if (!sol)
			return (end);
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		bgn;
	int		end;
	int		size;

	end = ft_strlen(s1);
	size = ft_strlen(set);
	bgn = left(end, size, s1, set);
	end = right(bgn, size, s1, set);
	ret = ft_substr(s1, bgn, (end - bgn + 1));
	return (ret);
}
