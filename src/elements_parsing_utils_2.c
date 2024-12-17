/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_parsing_utils_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:11:58 by ks19              #+#    #+#             */
/*   Updated: 2024/12/17 01:01:45 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

char	*ft_remove_spaces(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != 7)
		{
			str[count] = str[i];
			count++;
		}
		i++;
	}
	str[count] = '\0';
	return (str);
}

char	*ft_handle_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			str[i] = 7;
		i++;
	}
	str = ft_remove_spaces(str);
	return (str);
}

void	ft_atoi_valid_range(char *str, int index, t_map *map, int range)
{
	char	*dup;
	int		nb;

	dup = ft_strdup(str);
	dup[range] = '\0';
	nb = ft_atoi(dup);
	if (index == 4)
		map->f[map->rgb] = nb;
	else
		map->c[map->rgb] = nb;
	free(dup);
}

int	ft_fill_color(char *str, t_map *map, int index)
{
	int	i;

	i = 0;
	map->rgb = 0;
	str++;
	str = ft_handle_spaces(str);
	while (str[i])
	{
		if (str[i] == 44)
		{
			ft_atoi_valid_range(str, index, map, i);
			str = str + i + 1;
			i = -1;
			map->rgb = map->rgb + 1;
		}
		i++;
	}
	ft_atoi_valid_range(str, index, map, i);
	return (1);
}

int	ft_fill_texture(char *str, int index, t_map *map)
{
	char	*dup;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	str = str + 2;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	dup = ft_strdup(str);
	if (index == 0)
		map->no = dup;
	else if (index == 1)
		map->so = dup;
	else if (index == 2)
		map->we = dup;
	else if (index == 3)
		map->ea = dup;
	return (1);
}
