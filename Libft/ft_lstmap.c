/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:04:09 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/26 17:04:43 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Parameters lst: The address of a pointer to a node.
f: The address of the function used to iterate on
the list.
del: The address of the function used to delete
the content of a node if needed.
Return value The new list.
NULL if the allocation fails.
External functs. malloc, free
Description: Iterates the list ’lst’ and applies the function
’f’ on the content of each node. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed.*/

#include "libft.h"

static int	new_list_element(t_list **new_list, void *content,
		void (*del)(void *))
{
	t_list	*new_element;

	new_element = ft_lstnew(content);
	if (new_element == NULL)
	{
		if (del != NULL)
			del(content);
		return (0);
	}
	ft_lstadd_back(new_list, new_element);
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*head;

	head = lst;
	new_list = NULL;
	if (!(head != NULL && (*f) != NULL))
		return (0);
	while (head != NULL)
	{
		if (!(new_list_element(&new_list, (*f)(head->content), del)))
			ft_lstclear(&new_list, del);
		head = head->next;
	}
	return (new_list);
}
