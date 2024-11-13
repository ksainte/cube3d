/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:00:40 by ksainte           #+#    #+#             */
/*   Updated: 2023/04/10 12:36:51 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	i;
	int	j;

	i = ft_isalpha(c);
	j = ft_isdigit(c);
	if (i == 1 || j == 1)
		return (1);
	return (0);
}
/*
int	main(void)
{
	int i = 65;
	printf("%d",ft_isalnum(i));
	return (0);
}*/