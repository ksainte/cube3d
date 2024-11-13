/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:29:40 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/06 11:30:14 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
/*#include<string.h>
int	main(void)
{
	char dest[] = "ok";
	char src[] = "lorem ipsum dolor sit amet";
	printf("%lu",ft_strlcpy(dest,src,0));
    //printf("%lu",strlcpy(dest,src,0));
    //printf("%s",strncpy(dest,src,2));
	return (0);
}*/