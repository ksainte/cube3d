/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:54:41 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/26 16:55:47 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Parameters content: The content to create the node with.
Return value The new node
Description: Allocates (with malloc(3)) and returns a new node.
The member variable ’content’ is initialized with
the value of the parameter ’content’. 
The variable ’next’ is initialized to NULL.

https://www.learn-c.org/en/Linked_lists*/
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elmt;

	new_elmt = malloc(sizeof(t_list));
	if (new_elmt == NULL)
		return (NULL);
	new_elmt->next = NULL;
	new_elmt->content = content;
	return (new_elmt);
}

/*#include <stdio.h>
int	main(void)
{
    int data = 42;

    t_list *new_node = ft_lstnew(&data);
    printf("New node created successfully with content: %d\n",
		*(int *)(new_node->content));
    //free(new_node);

    return (0);
}*/