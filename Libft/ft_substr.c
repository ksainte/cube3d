/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:13:49 by ksainte           #+#    #+#             */
/*   Updated: 2024/05/27 09:42:40 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*check(char *s2)
{
	s2 = malloc(sizeof(char));
	if (s2 == NULL)
		return (NULL);
	s2[0] = '\0';
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s2;

	if (!s)
		return (NULL);
	s2 = NULL;
	if (ft_strlen(s) < start)
		return (check(s2));
	else
	{
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		s2 = (char *)malloc(sizeof(char) * (len + 1));
		if (s2 == NULL)
			return (NULL);
		i = start;
		while (i < start + len && s[i] != '\0')
		{
			s2[i - start] = s[i];
			i++;
		}
		s2[i - start] = '\0';
		return (s2);
	}
}

// #include<stdio.h>
// int main()
// {
//     //char s[] = "hola";
// 	char s[] = "lorem ipsum dolor";
// 	char *str;	
// 	str = ft_substr(s,0,3);
// 	//str = ft_substr(s,0,10);
// 	printf("%s",str);
// 		system("leaks -q -fullContent $(ps -o pid= -p $PPID)");
// 	return (0);
// }