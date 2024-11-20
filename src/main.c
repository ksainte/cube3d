/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:14:55 by ks19              #+#    #+#             */
/*   Updated: 2024/11/20 21:43:09 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"


void	ft_copy_table(t_map *map)
{
	int	x;

	x = 0;
	map->tmp = ft_calloc(map->row + 1, sizeof(char *));
	if (!map->tmp)
		return ;
	while (map->tab[x])
	{
		map->tmp[x] = ft_strdup(map->tab[x]);
		x++;
	}
	map->tmp[x] = NULL;
}

void	ft_has_valid_path(t_map *map, int x, int y)
{
	if (map->tmp[x][y] == '0' || map->tmp[x][y] == map->tmp[map->starting_x][map->starting_y])
	{
        map->walls++;
		map->tmp[x][y] = '2';
		// ft_has_valid_path(map, x - 1, y);
		ft_has_valid_path(map, x + 1, y);
		// ft_has_valid_path(map, x, y - 1);
		// ft_has_valid_path(map, x, y + 1);
	}
}

void	ft_find_start_pos(t_map *map)
{
	int	x;
	int	y;
    int j;
    const char array[4] = "NSEW";

	x = 0;
	while (map->tab[x])
	{
		y = 0;
		while (map->tab[x][y])
		{
            j = 0;
            while (array[j])
            {
                if (map->tab[x][y] == array[j])
                {
                    map->starting_x = x;
                    map->starting_y = y;
                }
                j++;
            }
			y++;
		}
		x++;
	}
}

int	ft_is_map_valid(t_map *map)
{
    
    ft_find_start_pos(map);
    ft_copy_table(map);
    // if (!tab_copy)
    //     return (ft_map_error(0));
    // c = map->tab[map->starting_x][map->starting_y];
    map->walls = 0;
	ft_has_valid_path(map, map->starting_x, map->starting_y);
    //de base 4
    //a chaque bon element +2
    ft_print_table(map->tmp);
    printf("-----------------\n");
    ft_print_table(map->tab);
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
    if (!ft_fill_tab_from_fd(&map) && ft_free(&map))
        return (0);
    ft_is_map_valid(&map);
    // ft_print_table(map.tab);
    free_table(map.tab);
    // free_table(map.tmp);
    ft_free(&map);
    return (1);
}