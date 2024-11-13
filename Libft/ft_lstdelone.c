/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:00:32 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/26 17:01:18 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Parameters lst: The node to free.
del: The address of the function used to delete
the content.
Return value None
External functs. free
Description Takes as a parameter a node and frees the memory of
the node’s content using the function ’del’ given
as a parameter and free the node. The memory of
’next’ must not be freed*/
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!(lst != NULL))
		return ;
	if (del != NULL && lst->content != NULL)
		del(lst->content);
	free(lst);
}
