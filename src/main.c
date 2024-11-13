/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:14:55 by ks19              #+#    #+#             */
/*   Updated: 2024/11/13 13:03:07 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

int ft_free(char *path, int fd)
{
    if (path)
        free(path);
    if (fd != -1)
        close(fd);
    return (1);
}

int	ft_map_error(int error, int fd, char *path)
{
	char	*str;

	if (error == 0 && ft_free(path, fd))
		str = "Error\nFailed Allocation!\n";
    if (error == 1)
    {
        perror("open");
        close(fd);
        free(path);
    }
    if (error == 2 && ft_free(path, fd))
        str = "Error\nWrong map format, remaining leftovers!\n";
    if (error == 3 && ft_free(path, fd))
        str = "Error\nEmpty map!\n";
	write(1, str, ft_strlen(str));
	return (0);
}

int	ft_check_map_left_over(t_map *map, char *path)
{
	while (map->line != 0)
	{
		free(map->line);
		map->line = get_next_line(map->fd);
		if (map->line && map->line[0] != '\n')
        {
        	free(map->line);
            return(ft_map_error(2, map->fd, path));        
        }
	}
    return (1);
}

int	ft_row_number(t_map *map, char *path)
{
	map->fd = open(path, O_RDONLY);
	if (map->fd == -1)
        return (ft_map_error(1, map->fd, path));
	map->line = (char *)malloc(sizeof(char *));
	if (!map->line)
        return (ft_map_error(0, map->fd, path));
	while (map->line != NULL)
	{
		if (map->line)
			free(map->line);
		map->line = get_next_line(map->fd);
		if (map->line == 0 || *map->line == '\n')
			break ;
		map->row++;
	}
	if (map->line != 0 && !ft_check_map_left_over(map, path))
		return (0);
	if (map->line == 0 && map->row == 0)
        return (ft_map_error(3, map->fd, path));
    return (1);
}

char *ft_check_args(int argc, char *str)
{
	char    *path;

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
	if(!(path = ft_strjoin("./maps/", str)))
        return (ft_map_error(0, -1, NULL));
	return (path);
}

int main(int argc, char **argv)
{
	t_map   map;
	char    *path;

    if(!(path = ft_check_args(argc, argv[1])))
        return (0);
    if(!(ft_row_number(&map, path)))
        return (0);
    return (1);
    
}