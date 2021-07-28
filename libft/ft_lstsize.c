/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 14:30:08 by dwillard          #+#    #+#             */
/*   Updated: 2021/04/27 14:30:11 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		counter;

	temp = lst;
	counter = 0;
	while (temp)
	{
		counter++;
		if (!temp->next)
			return (counter);
		temp = temp->next;
	}
	return (counter);
}
