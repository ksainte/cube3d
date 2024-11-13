/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:10:36 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/12 11:10:38 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)ptr + i);
		i++;
	}
	return (NULL);
}

/*#include <string.h>
int	main(void)
{
    char s[] = "http://www.tutorialspoint.com";
    char *str;
    int c = ':';

    //int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
    //printf("%p", (char *)ft_memchr(tab, -1, 7));
    //printf("%p", (char *)memchr(tab, -1, 7));
    //printf("%p",memchr(str,'\002', 45));
    str = ft_memchr(NULL,c,4);
   //str = memchr(NULL,c,5);
    printf("%s",str);

    //size_t is the Number of character to be searched for.
}*/