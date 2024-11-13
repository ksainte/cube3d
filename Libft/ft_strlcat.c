/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte19@student.s19>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:30:49 by ksainte           #+#    #+#             */
/*   Updated: 2024/04/03 23:20:18 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dest_len)
		return (dstsize + src_len);
	i = 0;
	while (src[i] && i < dstsize - dest_len - 1)
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}
/*#include<string.h>
int	main(void)
{
	char dest[] = "ok";
	char src[] = "toi";
	//printf("%lu",ft_strlcat(dest,src,5));
	printf("%lu",strlcat(NULL,src,1));
	return (0);
	//where dstsize is the length of newly created dest
	//max 5,hence if <5 will overflow when appeding
}*/