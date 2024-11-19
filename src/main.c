/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:14:55 by ks19              #+#    #+#             */
/*   Updated: 2024/11/19 23:17:54 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

// int ft_reopen_fd(t_map *map)
// {
//     if (close(map->fd) == -1)
//     {
//         free(map->path);
//         ft_system_error();
//         return (0);
//     }
//     map->fd = open(map->path, O_RDONLY);
// 	if (map->fd == -1)
//     {
//         free(map->path);
//         ft_system_error();
//         return (0);
//     }
//     return (1);
// }

// int	ft_fill_tab(t_map *map)
// {
// 	int	    i;
    
// 	i = 0;
// 	map->tab = calloc(map->row + 1, sizeof(char *));
// 	if (!map->tab)
// 		return (ft_map_error(1));
// 	while (i < map->row)
// 	{
// 		map->tab[i] = get_next_line(map->fd);
// 		printf("%s", map->tab[i]);
// 		map->tab[i] = ft_strtrim(map->tab[i], "\n");
// 		i++;
// 	}
// 	map->tab[i] = NULL;
// }

void ft_print(t_map *map)
{
    int i = 0;
    while(i < 3)
    {
        printf("F %d\n", map->F[i]);
        i++;
    }
    i = 0;
    while(i < 3)
    {
        printf("C %d\n", map->C[i]);
        i++;
    }
    printf("NO %s\n", map->NO);
    printf("SO %s\n", map->SO);
    printf("EA %s\n", map->EA);
    printf("WE %s\n", map->WE);
}

int main(int argc, char **argv)
{
	t_map   map;

    if(!(map.path = ft_check_args(argc, argv[1])))
        return (0);
    if((!ft_elements_to_parse(&map) || !ft_map_to_parse(&map)) && ft_free(&map))
        return (0);
    // if (!ft_reopen_fd(&map) && !ft_fill_tab(&map) && ft_free(&map))
    //     return (0);
    ft_free(&map);
    return (1);
}