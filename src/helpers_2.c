/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:52:00 by ks19              #+#    #+#             */
/*   Updated: 2024/11/20 16:52:38 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

int	ft_fill_tab(t_map *map)
{
	int	    i;
    int     len;

	i = 0;
	map->tab = calloc(map->row + 1, sizeof(char *));
	if (!map->tab)
		return (ft_map_error(0));
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

int	ft_fill_tab_from_fd(t_map *map)
{
	int	    elements;

    elements = 0;
    if (!ft_reopen_fd(map))
        return (0); 
    map->line = (char *)malloc(sizeof(char *));
	if (!map->line)
        return (ft_map_error(0));
	while (map->line != NULL)
	{
		free(map->line);
		map->line = get_next_line(map->fd);
        if (map->line && elements == 6 && !ft_line_is_space(map->line))
            break;
        if (map->line && !ft_line_is_space(map->line))
            elements++;
	}
    if (!ft_fill_tab(map) && ft_free_line(map))
        return(0);
    return (1);
}
