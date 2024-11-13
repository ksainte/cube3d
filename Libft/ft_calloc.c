/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:16:06 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/12 15:55:46 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	size_t	i;
	size_t	range;

	range = count * size;
	if (size != 0 && range / size != count)
		return (NULL);
	mem = (char *)malloc(range);
	if (mem == NULL)
		return (NULL);
	i = 0;
	while (i < range)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
/*#include <stdio.h>
int	main(void)
{
    size_t count = 0;
    size_t size = 2;
    char *str;

    str = ft_calloc(count,size);
    //str = calloc(count,size);
    printf("%s\n",str);
    return (0);
*ptr = (cast-type*)calloc(n, element-size);
ptr = (float*) calloc(25, sizeof(float));
here, n is the no. of elements and element-size is the size of each element.
This statement allocates contiguous space in memory 
for 25 elements each with the size of the float.
}*/