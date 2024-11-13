/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:02:54 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/26 17:03:47 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Parameters lst: The address of a pointer to a node.
f: The address of the function used to iterate on
the list.
Return value None
External functs. None
Description Iterates the list ’lst’ and applies the function
’f’ on the content of each node.*/
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!(lst != NULL || (*f) != NULL))
		return ;
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
/*int main()
{
    void	print_list(void *content);
    t_list *head = malloc(sizeof(t_list));
    head->content = (void*)1;
    head->next = malloc(sizeof(t_list));
    head->next->content = (void*)5464;
    head->next->next = NULL;

    print_list(head->content);
    void (*f)(void*) = &print_list;
    ft_lstiter(head, f);
    return 0;
}
void	print_list(void *content)
{
    printf("%d\n", (int)content);
}*/