/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:56:16 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/26 16:56:45 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Parameters lst: The address of a pointer to the first link of
a list.
new: The address of a pointer to the node to be
added to the list.

Description : Adds the node ’new’ at the beginning of the list*/
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
