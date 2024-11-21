/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:14:55 by ks19              #+#    #+#             */
/*   Updated: 2024/11/21 17:08:12 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"


int	ft_copy_table(t_map *map)
{
	int	x;

	x = 0;
	map->tmp = ft_calloc(map->row + 1, sizeof(char *));
	if (!map->tmp)
		return (0);
	while (map->tab[x])
	{
		map->tmp[x] = ft_strdup(map->tab[x]);
		x++;
	}
	map->tmp[x] = NULL;
    return (1);
}

bool	ft_has_valid_path(t_map *map, int y, int x)
{
    int width;
    int height;

    height = map->row;
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
    int	x;
    
    data->s_x = map->s_x;
    data->s_y = map->s_y;
    data->row = map->row;
    data->F[3] = map->F[3];
    data->C[3] = map->C[3];
    data->NO = ft_strdup(map->NO);
    data->SO = ft_strdup(map->SO);
    data->WE = ft_strdup(map->WE);
    data->EA = ft_strdup(map->EA);
	data->tab = ft_calloc(map->row + 1, sizeof(char *));
	if (!data->tab)
		return (0);
    x = 0;
	while (data->tab[x])
	{
		data->tab[x] = ft_strdup(map->tab[x]);
		x++;
	}
	data->tab[x] = NULL;
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
        return(ft_map_error(7));
    write(1, "The player has a playable map!\n",32);
    return (1);
}

int main(int argc, char **argv)
{
	t_map   map;
    t_data data;

    if(!(map.path = ft_check_args(argc, argv[1])))
        return (0);
    if((!ft_parse_valid(&map) || !ft_map_playable(&map, &data)) && ft_free(&map))
        return (0);
    ft_free(&map);
    return (1);
}