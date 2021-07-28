/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 18:02:55 by dwillard          #+#    #+#             */
/*   Updated: 2021/04/21 13:38:16 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	spacer(char input)
{
	if (input == '\n')
		return ('\n');
	if (input == '\t')
		return ('\t');
	if (input == '\v')
		return ('\v');
	if (input == '\r')
		return ('\r');
	if (input == ' ')
		return (' ');
	if (input == '\f')
		return ('\f');
	return (' ');
}

int	ft_atoi(const char *str)
{
	int	ind;
	int	sgn;
	int	value;

	sgn = 1;
	ind = 0;
	value = 0;
	while (spacer(str[ind]) == str[ind])
		ind++;
	if (str[ind] == '-' || str[ind] == '+')
	{
		if (str[ind] == '-')
			sgn = -1;
		ind++;
	}
	while (str[ind] >= 48 && str[ind] <= 57)
	{
		value *= 10;
		value += (str[ind] - 48);
		ind++;
	}
	if (sgn == -1)
		value = -value;
	return (value);
}
