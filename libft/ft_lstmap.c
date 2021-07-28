/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:02:27 by dwillard          #+#    #+#             */
/*   Updated: 2021/04/27 17:03:33 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new_list;
	t_list	*temp_new;

	temp = lst;
	new_list = ft_lstnew(f(temp->content));
	temp_new = new_list;
	while (temp != NULL)
	{
		if (temp->next != NULL)
		{
			temp_new->next = ft_lstnew(f(temp->next->content));
			if (!temp_new->next)
			{
				ft_lstclear(&new_list, del);
				return (NULL);
			}
		}
		else
			temp_new->next = NULL;
		temp = temp->next;
		temp_new = temp_new->next;
	}
	return (new_list);
}
