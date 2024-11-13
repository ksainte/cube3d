/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:15:23 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/12 11:15:24 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)str1[i] == (unsigned char)str2[i])
			i++;
		else
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	}
	return (0);
}
/*#include <string.h>
int	main(void)
{
    char s1[] = "azerty";
    char s2[] = "azertya";

    //printf("%d",memcmp(s1,s2,10));
    printf("%d",ft_memcmp(s1,s2,3));
    return (0);
}*/