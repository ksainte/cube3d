/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:33:48 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/10 17:05:34 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst2;
	char	*src2;
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	dst2 = (char *)dst;
	src2 = (char *)src;
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst2);
}

/*int	main(void)
{	
	#include<string.h>
	char dst[2];
	char src[2] = "ok";

	
	//printf("%s",memcpy(NULL,src,2));
	printf("%s",ft_memcpy(NULL,src,0));
	return (0);
}*/
