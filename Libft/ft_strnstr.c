/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:15:38 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/12 11:15:40 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str;
	char	*to_find;
	size_t	i;
	size_t	j;

	str = (char *)haystack;
	to_find = (char *)needle;
	if (!haystack && len == 0)
		return (NULL);
	if (*to_find == '\0')
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == needle[j] && str[i + j] && i + j < len)
		{
			j++;
			if (needle[j] == '\0')
				return (str + i);
		}
		i++;
	}
	return (NULL);
}
/*#include<string.h>
int	main(void)
{
    char haystack[] = "lorem ipsum dolor sit amet";
    char needle[] = "dolor";
    char *str;

    str = ft_strnstr(haystack,needle,15);
    //str = strnstr(haystack,needle,15);

    printf("%s",str);
    return (0);
}*/