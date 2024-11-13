/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:57:40 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/26 16:58:16 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Parameters lst: The beginning of the list.
Return value The length of the list
Description : Counts the number of nodes in a list*/
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*int main() 
{
	t_list *head = malloc(sizeof(t_list));
	head->content = (void*)1;
	head->next = malloc(sizeof(t_list));
	head->next->content = (void*)2;
	head->next->next = NULL;
	
	int size = ft_lstsize(head);
	printf("%d\n", size);
	//free(head->next);
	//free(head);
	return 0;
}*/
