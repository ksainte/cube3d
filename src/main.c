/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:14:55 by ks19              #+#    #+#             */
/*   Updated: 2024/11/21 14:55:47 by ks19             ###   ########.fr       */
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

int	ft_is_map_valid(t_map *map)
{
    if (!ft_fill_tab(map))
        return (ft_map_error(0));
    ft_find_start_pos(map);
    if (!ft_copy_table(map))
        return (ft_map_error(0));
    if (!ft_has_valid_path(map, map->s_y, map->s_x) && ft_free_table(map->tmp))
        return (ft_map_error(6));
    ft_print_table(map->tmp);
    printf("-----------------\n");
    ft_print_table(map->tab);
    write(1, "Map has correct Path!\n",23);
    ft_free_table(map->tmp);
    return (1);
}

int main(int argc, char **argv)
{
	t_map   map;
    // t_data data;

    if(!(map.path = ft_check_args(argc, argv[1])))
        return (0);
    if((!ft_elements_to_parse(&map) || !ft_map_to_parse(&map)) && ft_free(&map))
        return (0);
    if (!ft_is_map_valid(&map) && ft_free(&map))
        return (0);
    ft_free_table(map.tab);
    ft_free(&map);
    return (1);
}