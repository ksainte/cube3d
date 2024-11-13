/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:07:24 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/10 15:31:15 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
/*#include<strings.h>
int	main(void)
{
	char str[50] = "GeeksForGeeks is for programming geeks.";
	printf("\nBefore bzero(): %s\n", str);

	//bzero(str,0);
	ft_bzero(str,0);
	printf("After bzero(): %s", str);
	return (0);
}*/