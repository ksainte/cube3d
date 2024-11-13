/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:16:23 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/12 15:55:58 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*dst;

	i = 0;
	while (s1[i])
		i++;
	len = i;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
/*int main()
{
    //char s1[] = "ok";
	char *s1 = NULL;

	printf("%s",ft_strdup(s1));
	return (0);
//int *ptr = (int*) malloc(100 * sizeof(int));
//Since the size of int is 4 bytes, this statement 
//will allocate 400 bytes of memory. 
}*/