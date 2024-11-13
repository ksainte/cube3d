/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:15:49 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/13 10:15:50 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	if (s == NULL)
		return ((void) NULL);
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void	f(unsigned int i, char *c)
// {
// 	(void)i;
// 	*c = *c + 1;
// }
/*int main()
{
    //char str[] = "abc";
	char *str = NULL;
    ft_striteri(str, *f);
    printf("After: %s\n", str);
    return (0);
}*/
