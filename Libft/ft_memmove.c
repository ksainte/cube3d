/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:48:00 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/11 09:22:40 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src2;
	char	*dst2;

	if (!dst && !src)
		return (dst);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	src2 = (char *)src;
	dst2 = (char *)dst;
	while (len--)
	{
		dst2[len] = src2[len];
	}
	return (dst2);
}

/*int	main(void)
{
	#include <string.h>
	char	*dst;
	char	*src;

	//char dst[5];
	src = "Learningisfun";
	dst = src;
	//printf("Original string :%s\n ", src);
	//memmove(dst, src, 3);
	//ft_memmove(NULL, NULL, 3);
	memmove(NULL, NULL, 3);
	printf("memmove overlap : %s\n ", dst);
	return (0);
}*/
