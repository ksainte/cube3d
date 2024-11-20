/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:14:55 by ks19              #+#    #+#             */
/*   Updated: 2024/11/20 17:05:27 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

void	ft_valid_map(t_map *map)
{
	if (!(ft_is_rectangular(map) && ft_has_walls(map) && ft_char_is_legit(map)))
	{
		ft_printf("\nMap has invalid format:\n");
		ft_print_table(map->tab);
		free_table(map->tab);
		ft_error();
	}
	map->has_all_cltb = map->counter_cltb;
	ft_init_tmp(map);
	ft_has_valid_path(map, map->starting_x, map->starting_y);
	if (!(map->has_exit == 1 && map->has_all_cltb == 0))
	{
		ft_printf("\nMap has valid format but invalid path:\n");
		ft_print_table(map->tab);
		free_table(map->tab);
		free_table(map->tmp);
		ft_error();
	}
	else
	{
		ft_printf("\nMap has valid format and valid path:\n");
		ft_print_table(map->tab);
		free_table(map->tmp);
	}
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
	// ft_is_map_valid(&map);
    ft_print_table(map.tab);
    free_table(map.tab);
    ft_free(&map);
    return (1);
}