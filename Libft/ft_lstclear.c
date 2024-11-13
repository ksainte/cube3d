/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:01:35 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/26 17:02:26 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Parameters lst: The address of a pointer to a node.
del: The address of the function used to delete
the content of the node.
Return value None
External functs. free
Description : Deletes and frees the given node and every
successor of that node, using the function ’del’
and	free(3).
Finally, the pointer to the list must be set to
NULL.*/
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*n;
	t_list	*head;

	if (!(lst != NULL && del != NULL))
		return ;
	head = *lst;
	*lst = NULL;
	while (head != NULL)
	{
		n = head->next;
		(*del)(head->content);
		free(head);
		head = n;
	}
}
