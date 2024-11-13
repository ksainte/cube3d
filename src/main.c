/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:14:55 by ks19              #+#    #+#             */
/*   Updated: 2024/11/13 18:29:46 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

void ft_system_error(void)
{
    write(2, strerror(errno), strlen(strerror(errno)));
    write(2, "\n", 1);
}

int ft_free(t_map *map)
{
    if (map->path)
        free(map->path);
    if (close(map->fd) == -1)
        ft_system_error();
    return (1);
}

int	ft_map_error(int error, t_map *map)
{
	char	*str;

    str = NULL;
	if (error == 0 && ft_free(map))
		str = "Error\nFailed Allocation!\n";
    if (error == 1)
    {
        ft_system_error();
        free(map->path);
        close(map->fd);
    }
    if (error == 2 && ft_free(map))
        str = "Error\nWrong map format, remaining leftovers!\n";
    if (error == 3 && ft_free(map))
        str = "Error\nEmpty map!\n";
    if (str)
        write(1, str, ft_strlen(str));
    return (0);
}

int	ft_check_map_left_over(t_map *map)
{
        printf("a");
	while (map->line != 0)
	{
        printf("a");
		free(map->line);
		map->line = get_next_line(map->fd);
		if (map->line && map->line[0] != '\n')
        {
        	free(map->line);
            return(ft_map_error(2, map));        
        }
	}
    return (1);
}

int	ft_row_number(t_map *map)
{
    map->row = 0;
	map->fd = open(map->path, O_RDONLY);
	if (map->fd == -1)
        return (ft_map_error(1, map));
	map->line = (char *)malloc(sizeof(char *));
	if (!map->line)
        return (ft_map_error(0, map));
	while (map->line != NULL)
	{
		if (map->line)
			free(map->line);
		map->line = get_next_line(map->fd);
        // printf("%s", map->line);
		if (map->line == 0 || *map->line == '\n')
			break ;
		map->row++;
	}
    printf("%d", map->row);
	if (map->line != 0 && !ft_check_map_left_over(map))
		return (0);
    printf("%d", map->row);
    if (map->line == 0 && map->row == 0)
        return (ft_map_error(3, map));
    return (1);
}

char *ft_check_args(int argc, char *str)
{
	char    *path;

    path = str;
	if (argc != 2 || str == NULL)
	{
		ft_printf("Error\nMust be only 2 Arguments: ./cube_3d <map>\n");
        return (NULL);
	}
	while (*str != '.' && *str != '\0')
		str++;
	if (ft_strncmp(".cub", str, 4) != 0 || ft_strlen(str) != 4)
	{
		ft_printf("Error\nExtension of the map file not valid : <map>.cub");
        return (NULL);
	}
	if(!(path = ft_strjoin("./maps/", path)))
    {
		ft_printf("Error\nPath allocation failed");
        return (NULL);
    }
	return (path);
}

int main(int argc, char **argv)
{
	t_map   map;

    if(!(map.path = ft_check_args(argc, argv[1])))
        return (0);
    if(!(ft_row_number(&map)))
        return (0);
    ft_free(&map);
    return (1);
    
}