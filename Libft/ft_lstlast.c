/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:58:32 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/26 16:59:06 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Parameters lst: The beginning of the list.
Return value Last node of the list
External functs. None
Description Returns the last node of the list.*/
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	if (lst->next == NULL)
		return (lst);
	else
	{
		while (lst->next != NULL)
			lst = lst->next;
		return (lst);
	}
}
/*int main()
{
    t_list *head = malloc(sizeof(t_list));
    head->content = (void*)1;
    head->next = malloc(sizeof(t_list));
    head->next->content = (void*)5464;
    head->next->next = NULL;

    t_list *last_node = ft_lstlast(head);

    printf("%d\n", (int)last_node->content);
}*/