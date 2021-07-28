/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:29:59 by dwillard          #+#    #+#             */
/*   Updated: 2021/04/22 20:11:01 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(int n)
{
	int	temp;
	int	ret;

	ret = 0;
	temp = n;
	if (n < 0)
		ret++;
	if (!temp)
		return (1);
	while (temp)
	{
		temp = temp / 10;
		ret++;
	}
	return (ret);
}

static int	condition(int n)
{
	int	temp;

	temp = 0;
	if (n < 0)
		temp = 1;
	return (temp);
}

static int	mod_n(int n)
{
	int	ret;

	ret = n % 10;
	if (ret < 0)
		ret = -ret;
	return (ret);
}

char	*ft_itoa(int n)
{
	int		counter;
	int		temp;
	char	*ret;

	counter = ft_counter(n);
	ret = malloc(sizeof(*ret) * counter + 1);
	if (ret == NULL)
		return (NULL);
	temp = condition(n);
	ret[counter] = '\0';
	while (--counter >= 0)
	{
		if (temp && !counter)
		{
			ret[0] = '-';
			return (ret);
		}
		ret[counter] = '0' + mod_n(n);
		n /= 10;
	}
	return (ret);
}
