/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_playable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:03:25 by ks19              #+#    #+#             */
/*   Updated: 2024/11/22 11:03:27 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

bool	ft_has_valid_path(t_map *map, int y, int x)
{
    int width;
    int height;

    height = map->row;
    width = -1;
    if (y >= 0 && y < height)
        width = ft_strlen(map->tmp[y]);
    if (x == -1 || x >= width)
        return (false);
    if (y == -1 || y >= height)
        return (false);
    if ((map->tmp[y][x] >= 9 && map->tmp[y][x] <= 13) || map->tmp[y][x] == 32)
        return (false);
    if (map->tmp[y][x] == '2' || map->tmp[y][x] == '1')
        return (true);
    map->tmp[y][x] = '2';
    if (!ft_has_valid_path(map, y - 1, x))
        return (false);
    if (!ft_has_valid_path(map, y + 1, x))
        return (false);
    if (!ft_has_valid_path(map, y, x + 1))
        return (false);
    if (!ft_has_valid_path(map, y, x - 1))
        return (false);
    return (true);
}

void	ft_find_start_pos(t_map *map)
{
	int	x;
	int	y;
    int j;
    const char array[4] = "NSEW";

	y = 0;
	while (map->tab[y])
	{
		x = 0;
		while (map->tab[y][x])
		{
            j = 0;
            while (array[j])
            {
                if (map->tab[y][x] == array[j])
                {
                    map->s_x = x;
                    map->s_y = y;
                }
                j++;
            }
			x++;
		}
		y++;
	}
}

int ft_copy_to_data(t_map *map, t_data *data)
{
    int i;
    
    data->s_x = map->s_x;
    data->s_y = map->s_y;
    data->row = map->row;
	data->tab = ft_calloc(map->row + 1, sizeof(char *));
	if (!data->tab)
		return (0);
    i = -1;
	while (map->tab[++i])
		data->tab[i] = ft_strdup(map->tab[i]);
	data->tab[i] = NULL;
    i = -1;
    while (++i < 3)
        data->F[i] = map->F[i];
    i = -1;
    while (++i < 3)
        data->C[i] = map->C[i];
    data->NO = ft_strdup(map->NO);
    data->SO = ft_strdup(map->SO);
    data->WE = ft_strdup(map->WE);
    data->EA = ft_strdup(map->EA);
    return (1);
} 

int	ft_map_playable(t_map *map, t_data *data)
{
    if (!ft_fill_tab(map))
        return (ft_map_error(0));
    ft_find_start_pos(map);
    if (!ft_copy_table(map))
        return (ft_map_error(0));
    if (!ft_has_valid_path(map, map->s_y, map->s_x) && ft_free_table(map->tmp))
        return (ft_map_error(6));
    ft_free_table(map->tmp);
    if (!ft_copy_to_data(map, data))
        return(ft_map_error(0));
    write(1, "The player has a playable map!\n",32);
    return (ft_free(map));
}