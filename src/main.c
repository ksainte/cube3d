/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:14:55 by ks19              #+#    #+#             */
/*   Updated: 2024/11/20 19:38:06 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"


// void	ft_init_tmp(t_map *map)
// {
// 	size_t	x;

// 	x = 0;
// 	map->tmp = ft_calloc(map->row + 1, sizeof(char *));
// 	if (!map->tmp)
// 		return ;
// 	while (map->tab[x])
// 	{
// 		map->tmp[x] = ft_strdup(map->tab[x]);
// 		x++;
// 	}
// 	map->tmp[x] = NULL;
// }

// void	ft_has_valid_path(t_map *map, int x, int y)
// {
// 	if (map->tmp[x][y] == 'E')
// 		map->has_exit = 1;
// 	if (map->tmp[x][y] == 'C')
// 		map->has_all_cltb--;
// 	if (map->tmp[x][y] == '0' || map->tmp[x][y] == 'C' || map->tmp[x][y] == 'P')
// 	{
// 		map->tmp[x][y] = '2';
// 		ft_has_valid_path(map, x - 1, y);
// 		ft_has_valid_path(map, x + 1, y);
// 		ft_has_valid_path(map, x, y - 1);
// 		ft_has_valid_path(map, x, y + 1);
// 	}
// }

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
    char **temp_table;
    
    ft_find_start_pos(map);
	// temp_table = ft_init_tmp(map);
	// ft_has_valid_path(map, map->starting_x, map->starting_y);
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
    ft_free(&map);
    return (1);
}