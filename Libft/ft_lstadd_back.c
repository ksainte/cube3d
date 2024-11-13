/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:59:26 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/26 17:00:01 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Parameters lst: The address of a pointer to the first link of
a list.
new: The address of a pointer to the node to be
added to the list.

Description : Adds the node ’new’ at the end of the list.*/
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	head = *lst;
	while (head != NULL && head->next != NULL)
	{
		head = head->next;
	}
	if (head != NULL)
		head->next = new;
	else
		*lst = new;
}
