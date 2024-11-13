/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:48:41 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/11 16:47:00 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*#include <string.h>
int	main(void)
{
	unsigned int n;

	char bob[] = "saaut";
	char jan[] = "sabt";
	printf("%d\n",ft_strncmp(bob,jan,3));
	//printf("%d", strncmp(bob,jan,3));
	return (0);
}*/
