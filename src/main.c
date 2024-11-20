/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:14:55 by ks19              #+#    #+#             */
/*   Updated: 2024/11/20 16:44:21 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

int ft_reopen_fd(t_map *map)
{
    if (close(map->fd) == -1)
        return (0);
    map->fd = open(map->path, O_RDONLY);
	if (map->fd == -1)
        return (ft_map_error(1));
    return (1);
}
int	ft_fill_tab(t_map *map, t_data *data)
{
	int	    i;
    int     len;

	i = 0;
	data->tab = calloc(map->row + 1, sizeof(char *));
	if (!data->tab)
		return (ft_map_error(0));
	while (i < map->row)
	{
		len = ft_strlen(map->line);
        if (map->line[len - 1] == '\n')
            map->line[len - 1] = '\0';
		data->tab[i] = ft_strdup(map->line);
        free(map->line);
    	i++;
        map->line = get_next_line(map->fd);
	}
    free(map->line);
	data->tab[i] = NULL;
    return (1);
}

int	ft_fill_data_from_map(t_map *map, t_data *data)
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
    if (!ft_fill_tab(map, data) && ft_free_line(map))
        return(0);
    return (1);
}

void	free_table(char **buffer)
{
	int	i;

	i = -1;
	while (buffer[++i] != NULL)
		free(buffer[i]);
	free(buffer);
}


void ft_print_map(t_data *data)
{
    int i = 0;
    while (data->tab[i])
    {
        printf("%s", data->tab[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
	t_map   map;
    t_data data;

    if(!(map.path = ft_check_args(argc, argv[1])))
        return (0);
    if((!ft_elements_to_parse(&map) || !ft_map_to_parse(&map)) && ft_free(&map))
        return (0);
    // ft_print(&map);
    printf("%d\n", map.row);
    if (!ft_fill_data_from_map(&map, &data) && ft_free(&map))
        return (0);
    ft_print_map(&data);
    free_table(data.tab);
    ft_free(&map);
    return (1);
}