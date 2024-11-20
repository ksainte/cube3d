/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:48:23 by ks19              #+#    #+#             */
/*   Updated: 2024/11/20 15:01:08 by ks19             ###   ########.fr       */
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
            return(0);        
        }
	}
    return (1);
}

int ft_char_is_space(char c)
{
    if ((c >= 9 && c <= 13) || c == 32)
        return (1);
    return (0);
}

int ft_has_valid_characters(char *str)
{
    int i;
    int j;
    int match;
    const char array[6] = "NSEW01";

    i = 0;
    match = 0;
    while (str[i])
    {
        j = 0;
        while (array[j])
        {
            if (str[i] == array[j] || ft_char_is_space(str[i]))
                match++;
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
    write(1, "First 6 elements are well parsed!\n", 35);
    map->row = 0;
	while (map->line != NULL)
	{
        if (!ft_has_valid_characters(map->line) && ft_free_line(map))
            return (ft_map_error(4));
        map->row++;
		free(map->line);
		map->line = get_next_line(map->fd);
		if (map->line && ft_line_is_space(map->line))
			break ;
	}
	if (map->line != 0 && !ft_check_map_left_over(map))
		return(ft_map_error(2));
    if (map->line == 0 && map->row == 0)
        return (ft_map_error(3));
    write(1, "Map is well parsed!\n", 21);
    return (1);
}