/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:14:55 by ks19              #+#    #+#             */
/*   Updated: 2024/11/20 15:03:40 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"


int main(int argc, char **argv)
{
	t_map   map;
    // t_data data;

    if(!(map.path = ft_check_args(argc, argv[1])))
        return (0);
    if((!ft_elements_to_parse(&map) || !ft_map_to_parse(&map)) && ft_free(&map))
        return (0);
    // ft_print(&map);
    printf("%d\n", map.row);
    // if (!ft_reopen_fd(&map) && !ft_fill_tab(&map) && ft_free(&map))
    //     return (0);
    ft_free(&map);
    return (1);
}