/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:46:15 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/11 18:03:02 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr++;
	}
	if (*ptr == (char)c)
		return (ptr);
	return (NULL);
}

//#include <string.h>
/*int main()
{
	char s[] = "Rs1abc1efg";

	char c = '\0';
	char *str;

	//str = strchr(s, c);
	str = ft_strchr(s, c);

    printf("%s",str);

	return (0);
}*/
