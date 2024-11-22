/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:14:55 by ks19              #+#    #+#             */
/*   Updated: 2024/11/22 11:06:22 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

int main(int argc, char **argv)
{
	t_map   map;
    t_data data;

    if(!(map.path = ft_check_args(argc, argv[1])))
        return (0);
    if((!ft_parse_valid(&map) || !ft_map_playable(&map, &data)) && ft_free(&map))
        return (0);
    ft_free_data(&data);
    return (1);
}