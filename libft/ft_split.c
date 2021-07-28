/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:51:21 by dwillard          #+#    #+#             */
/*   Updated: 2021/04/20 16:51:23 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_counter(char const *s, char c);
static int	ft_length(char const *s, char c, int index);
static char	*word_filler(char const *s, char c, int index);

static void	freedom(char ***ret, char *s, char c)
{
	int	count;

	count = 0;
	while (count < word_counter(s, c))
	{
		free(*ret[count]);
		*ret[count++] = NULL;
	}
	free(*ret);
	*ret = NULL;
}

static int	word_counter(char const *s, char c)
{
	int	count;
	int	ind;

	ind = 0;
	count = 0;
	while (s[ind])
	{
		while (s[ind] == c)
			ind++;
		if (s[ind] != c && s[ind])
		{
			while (s[ind] != c && s[ind])
				ind++;
			count++;
		}
	}
	return (count);
}

static int	ft_length(char const *s, char c, int index)
{
	int	count;

	count = 0;
	while (s[index + count] && s[index + count] != c)
		count++;
	return (count);
}

static char	*word_filler(char const *s, char c, int index)
{
	int		ind;
	char	*word;

	ind = 0;
	word = malloc(sizeof(*word) * (ft_length(s, c, index) + 1));
	if (word == NULL)
		return (NULL);
	while (ind < ft_length(s, c, index))
	{
		word[ind] = s[index + ind];
		ind++;
	}
	word[ind] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	int		ind;
	char	**ret;

	count = 0;
	ind = 0;
	ret = malloc(sizeof(*ret) * (word_counter(s, c) + 1));
	if (ret == NULL || !s)
		return (NULL);
	while (s[ind])
	{
		while (s[ind] == c)
			ind++;
		if (s[ind] != c && s[ind])
		{
			ret[count++] = word_filler(s, c, ind);
			if (ret[count - 1] == NULL)
				freedom(&ret, (char *)s, c);
			if (!ret)
				return (NULL);
			ind += ft_length(s, c, ind);
		}
	}
	ret[count] = NULL;
	return (ret);
}
