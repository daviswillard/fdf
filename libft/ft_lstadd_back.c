/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:34:35 by dwillard          #+#    #+#             */
/*   Updated: 2021/04/27 17:35:13 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (!new || !lst)
	{
	}
	else if (!*lst)
		*lst = new;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}
