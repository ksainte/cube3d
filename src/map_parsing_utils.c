/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:48:23 by ks19              #+#    #+#             */
/*   Updated: 2024/12/11 16:59:47 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

int	ft_check_map_left_over(t_map *map)
{
	while (map->line)
	{
		free(map->line);
		map->line = get_next_line(map->fd);
		if (map->line && !ft_line_is_space(map->line))
		{
			free(map->line);
			return (0);
		}
	}
	return (1);
}

int	ft_char_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_has_valid_characters(char *str, int *spawn)
{
	int			i;
	int			j;
	int			match;
	const char	array[6] = "NSEW01";

	i = 0;
	match = 0;
	while (str[i])
	{
		j = 0;
		while (array[j])
		{
			if (str[i] == array[j] || ft_char_is_space(str[i]))
				match++;
			if (str[i] == array[j] && j < 4)
				*spawn = *spawn + 1;
			j++;
		}
		if (match == 0)
			return (0);
		match = 0;
		i++;
	}
	return (1);
}

int	ft_map_to_parse(t_map *map)
{
	int	spawn;

	spawn = 0;
	write(1, "First 6 elements are well parsed!\n", 35);
	map->row = 0;
	while (map->line != NULL)
	{
		if (!ft_has_valid_characters(map->line, &spawn) && ft_free_line(map))
			return (ft_map_error(4));
		map->row++;
		free(map->line);
		map->line = get_next_line(map->fd);
		if (map->line && ft_line_is_space(map->line))
			break ;
	}
	if (map->line == 0 && map->row == 0)
		return (ft_map_error(3));
	if (spawn != 1)
		return (ft_map_error(5));
	if (map->line != 0 && !ft_check_map_left_over(map))
		return (ft_map_error(2));
	write(1, "Map is well parsed!\n", 21);
	return (1);
}
