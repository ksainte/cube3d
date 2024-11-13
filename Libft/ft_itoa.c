/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:14:58 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/13 10:14:59 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_int(int num)
{
	int	i;

	i = 0;
	if (num < 0)
	{
		i++;
		num = -num;
	}
	if (num < 10)
		i++;
	while (num >= 10)
	{
		num = num / 10;
		i++;
		if (num < 10)
			i++;
	}
	return (i);
}

static char	*res(void)
{
	char	*result;

	result = (char *)malloc(12 * sizeof(char));
	if (!result)
		return (NULL);
	result[11] = '\0';
	ft_memcpy(result, "-2147483648", 11);
	return (result);
}

char	*ft_itoa(int n)
{
	int		nb;
	int		len;
	char	*result;

	if (n == -2147483648)
		return (res());
	len = ft_len_int(n);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	nb = n;
	result[len] = '\0';
	if (nb < 0)
		nb = -nb;
	while (len > 0)
	{
		result[len - 1] = (nb % 10) + 48;
		nb = nb / 10;
		if (n < 0)
			result[0] = '-';
		len--;
	}
	return (result);
}
/*int main(int argc,char *argv[])
{
    int n;
    char *str;

    n = atoi(argv[1]);
    //n = -1056599095;
    str =  ft_itoa(n);
    printf("%s",str);
    return (0);
}*/
