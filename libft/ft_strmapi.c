/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 20:47:11 by dwillard          #+#    #+#             */
/*   Updated: 2021/04/21 12:28:32 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		ind;

	ind = 0;
	while (s[ind])
		ind++;
	if (s == NULL || f == NULL)
		return (NULL);
	str = malloc(sizeof(*s) * ind + 1);
	ind = 0;
	if (str == NULL)
		return (NULL);
	while (s[ind])
	{
		str[ind] = f(ind, s[ind]);
		ind++;
	}
	str[ind] = 0;
	return (str);
}
