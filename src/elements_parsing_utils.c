/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_parsing_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:58:34 by ks19              #+#    #+#             */
/*   Updated: 2024/12/11 16:57:06 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

int	ft_element_is_valid(char *str, t_map *map)
{
	int			value;
	const char	*prefix[6] = {"NO", "SO", "WE", "EA", "F", "C"};
	int			i;

	value = -1;
	i = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (value != 0 && i < 4)
	{
		value = ft_strncmp(prefix[i], str, 2);
		i++;
	}
	while (value != 0 && i < 6)
	{
		value = ft_strncmp(prefix[i], str, 1);
		i++;
	}
	i--;
	if (value == 0 && i != 4 && i != 5 && ft_open_path(str))
		return (i);
	else if (value == 0 && ft_valid_color(str) && ft_fill_color(str, map, i))
		return (i);
	return (-1);
}

int	ft_check_array(int array[6], int elements)
{
	int	i;
	int	j;
	int	duplicates;

	i = 0;
	duplicates = 0;
	if (elements == 1)
		return (1);
	while (i < 6)
	{
		j = 0;
		while (j < elements)
		{
			if (i == array[j])
				duplicates++;
			if (duplicates == 2)
				return (0);
			j++;
		}
		i++;
		duplicates = 0;
	}
	return (1);
}

int	ft_line_is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 9 || str[i] > 13) && str[i] != 32)
			return (0);
		i++;
	}
	return (1);
}

int	ft_textures_and_colors(t_map *map, int elements)
{
	int	array[6];

	while (++elements < 6)
		array[elements] = 0;
	elements = 0;
	while (map->line != NULL)
	{
		free(map->line);
		map->line = get_next_line(map->fd);
		if (map->line && elements == 6 && !ft_line_is_space(map->line))
			break ;
		if (map->line && !ft_line_is_space(map->line))
		{
			array[elements] = ft_element_is_valid(map->line, map);
			if (array[elements] == -1)
				return (-2);
			map->index = array[elements];
			elements++;
			if (!ft_check_array(array, elements))
				return (-3);
			if (map->index != 4 && map->index != 5)
				ft_fill_texture(map->line, map->index, map);
		}
	}
	return (elements);
}

int	ft_parse_valid(t_map *map)
{
	int		value;
	int		elements;
	char	*str;

	str = NULL;
	elements = -1;
	ft_init_textures_to_null(map);
	map->fd = open(map->path, O_RDONLY);
	if (map->fd == -1)
		return (ft_map_error(1));
	map->line = (char *)malloc(sizeof(char *));
	if (!map->line)
		return (ft_map_error(0));
	value = ft_textures_and_colors(map, elements);
	if (value == -2 && ft_free_line(map))
		str = "Error\nInvalid element or can't open path!\n";
	else if (value == -3 && ft_free_line(map))
		str = "Error\nThere are duplicates in the elements!\n";
	else if (value < 6)
		str = "Error\nThere are less than 6 elements!\n";
	if (!str)
		return (ft_map_to_parse(map));
	ft_custom_error(str);
	return (0);
}
