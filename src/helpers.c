/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:15:20 by ks19              #+#    #+#             */
/*   Updated: 2024/11/20 16:41:01 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

void ft_init_textures_to_null(t_map *map)
{
    map->index = -1;
    map->NO = NULL;
    map->SO = NULL;
    map->EA = NULL;
    map->WE = NULL;
}
void ft_print_elements(t_map *map)
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