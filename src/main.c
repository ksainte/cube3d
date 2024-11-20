/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:14:55 by ks19              #+#    #+#             */
/*   Updated: 2024/11/20 19:58:01 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"


char	**ft_copy_table(t_map *map)
{
	int	x;
    char **table;

	x = 0;
	table = ft_calloc(map->row + 1, sizeof(char *));
	if (!table)
		return (0);
	while (map->tab[x])
	{
		table[x] = ft_strdup(map->tab[x]);
		x++;
	}
	table[x] = NULL;
    return (table);
}

void	ft_has_valid_path(char **tab, int x, int y, char c)
{

	if (tab[x][y] == '0' || tab[x][y] == c)
	{
		tab[x][y] = '2';
		ft_has_valid_path(tab, x - 1, y, c);
		ft_has_valid_path(tab, x + 1, y, c);
		ft_has_valid_path(tab, x, y - 1, c);
		ft_has_valid_path(tab, x, y + 1, c);
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
    char **tab_copy;
    char c;
    
    ft_find_start_pos(map);
	tab_copy = ft_copy_table(map);
    if (!tab_copy)
        return (ft_map_error(0));
    c = map->tab[map->starting_x][map->starting_y];
	ft_has_valid_path(tab_copy, map->starting_x, map->starting_y, c);
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