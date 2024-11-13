/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:15:50 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/12 11:15:51 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	char	*s;
	int		i;
	int		signe;
	int		nb;

	s = (char *)str;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	signe = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			signe *= -1;
		s++;
	}
	i = 0;
	nb = 0;
	while (s[i] <= '9' && s[i] >= '0')
	{
		nb = nb * 10;
		nb = nb + (s[i] - 48);
		i++;
	}
	return (nb * signe);
}
/*#include <string.h>
int	main(int argc,char *argv[])
{
    char *str;

    //str = argv[1];
    str = "-2147483649"; 
    //printf("%d",ft_atoi(str));
    printf("%d",atoi(str));
    return (0);
}*/