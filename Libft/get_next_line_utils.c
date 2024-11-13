/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:47:16 by ksainte           #+#    #+#             */
/*   Updated: 2024/11/12 14:22:03 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

int	ft_n_present(char *left_str, char c)
{
	int	i;

	i = 0;
	if (!left_str)
		return (0);
	while (left_str[i] != '\0')
	{
		if (left_str[i] == c)
			return (1);
		i++;
	}
	return (0);
}


