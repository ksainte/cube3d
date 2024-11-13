/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:46:33 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/11 16:46:35 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	ptr = (char *)s;
	i = 0;
	while (ptr[i])
		i++;
	while (i > -1)
	{
		if (ptr[i] == (char)c)
			return (ptr + i);
		i--;
	}
	return (NULL);
}
/*#include <string.h>
int	main(void)
{
    char s[] = "Rs1abc1efg";

	char c = 'z';
	char *str;

	str = strrchr(s, c);
    //str = ft_strrchr(s, c);

    printf("%s",str);
	if (c == '\0')
		return (ptr + i);
	return (0);
}*/
