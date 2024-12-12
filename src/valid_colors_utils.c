/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_colors_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:40:45 by ks19              #+#    #+#             */
/*   Updated: 2024/12/11 17:00:21 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

int	ft_valid_number_range(char *str, int range)
{
	int		nb;
	char	*dup;

	nb = 0;
	dup = ft_strdup(str);
	if (!dup)
		return (0);
	dup[range] = '\0';
	nb = ft_atoi(dup);
	if (nb >= 0 && nb <= 255)
	{
		free(dup);
		return (1);
	}
	free(dup);
	return (0);
}

int	ft_check_until_comma_or_null(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != 44)
	{
		if (str[i] != 32 && (str[i] < 9 || str[i] > 13))
			return (-1);
		i++;
	}
	return (i);
}

int	ft_valid_characters(char *str, int range, int *len, int *rgb)
{
	int	i;

	i = 0;
	while (str[i] && i < range)
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	*len = ft_check_until_comma_or_null(str + i);
	if (*len == -1)
		return (0);
	if (!ft_valid_number_range(str, range))
		return (0);
	*rgb = *rgb + 1;
	if (*rgb > 3 || (*rgb == 3 && str[i + *len] == 44))
		return (0);
	if (str[i + *len] == 44)
		*len = *len + 1;
	return (1);
}

int	ft_valid_color_range(char *str, int *rgb)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != 44 && str[i] != 32 && (str[i] < 9 || str[i] > 13))
			i++;
		else
		{
			if (!ft_valid_characters(str, i, &len, rgb))
				return (0);
			str = str + i + len;
			i = 0;
			len = 0;
			while (str && ((*str >= 9 && *str <= 13) || *str == 32))
				str++;
		}
	}
	return (1);
}

int	ft_valid_color(char *str)
{
	int	rgb;

	rgb = 0;
	str = str + 1;
	if ((*str < 9 || *str > 13) && *str != 32)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (!ft_valid_color_range(str, &rgb) || rgb != 3)
		return (0);
	return (1);
}
