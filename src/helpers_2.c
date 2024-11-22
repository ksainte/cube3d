/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:52:00 by ks19              #+#    #+#             */
/*   Updated: 2024/11/22 10:59:35 by ks19             ###   ########.fr       */
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

int ft_free_data(t_data *data)
{
    ft_free_table(data->tab);
    free(data->NO);
    free(data->SO);
    free(data->EA);
    free(data->WE);
    return (1);
}

void ft_print_data(t_data *data)
{
    int i = -1;
    while(++i < 3)
        printf("F %d\n", data->F[i]);
    i = -1;
    while(++i < 3)
        printf("C %d\n", data->C[i]);
    printf("NO %s\n", data->NO);
    printf("SO %s\n", data->SO);
    printf("EA %s\n", data->EA);
    printf("WE %s\n", data->WE);
    printf("row is %d\n", data->row);
    printf("s->y is %d\n", data->s_y);
    printf("s->x is %d\n", data->s_x);
    printf("-----------------\n");
    ft_print_table(data->tab);
}

int	ft_calloc_tab(t_map *map)
{
	int	    i;
    int     len;

	i = 0;
	map->tab = calloc(map->row + 1, sizeof(char *));
	if (!map->tab)
		return (0);
	while (i < map->row)
	{
		len = ft_strlen(map->line);
        if (map->line[len - 1] == '\n')
            map->line[len - 1] = '\0';
		map->tab[i] = ft_strdup(map->line);
        free(map->line);
    	i++;
        map->line = get_next_line(map->fd);
	}
    free(map->line);
	map->tab[i] = NULL;
    return (1);
}

int	ft_fill_tab(t_map *map)
{
	int	    elements;

    elements = 0;
    if (!ft_reopen_fd(map))
        return (0); 
    map->line = (char *)malloc(sizeof(char *));
	if (!map->line)
        return (0);
	while (map->line != NULL)
	{
		free(map->line);
		map->line = get_next_line(map->fd);
        if (map->line && elements == 6 && !ft_line_is_space(map->line))
            break;
        if (map->line && !ft_line_is_space(map->line))
            elements++;
	}
    if (!ft_calloc_tab(map) && ft_free_line(map))
        return(0);
    return (1);
}