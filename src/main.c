/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:14:55 by ks19              #+#    #+#             */
/*   Updated: 2024/11/19 12:36:20 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

void ft_system_error(void)
{
    write(2, strerror(errno), strlen(strerror(errno)));
    write(2, "\n", 1);
}

char *ft_custom_error(char *str)
{
    if (str)
        write(2, str, ft_strlen(str));
    return (NULL);
}

int ft_free(t_map *map)
{
    free(map->path);
    if (map->fd != -1 && close(map->fd) == -1)
        ft_system_error();
    return (1);
}

int	ft_map_error(int error)
{
	char	*str;

    str = NULL;
	if (error == 0)
		str = "Error\nFailed Allocation!\n";
    else if (error == 1)
        ft_system_error();
    else if (error == 2)
        str = "Error\nWrong map format, remaining leftovers!\n";
    else if (error == 3)
        str = "Error\nEmpty map!\n";
    else if (error == 4)
        str = "Error\nThe map contains wrong characters!\n";
    ft_custom_error(str);
    return (0);
}


char *ft_check_args(int argc, char *str)
{
	char    *path;

    path = str;
	if (argc != 2)
	{
        str = "Error\nMust be only 2 Arguments: ./cube_3d <map>\n";
        return (ft_custom_error(str));
	}
	while (*str != '.' && *str != '\0')
		str++;
	if (ft_strncmp(".cub", str, 4) != 0 || ft_strlen(str) != 4)
	{
        str = "Error\nExtension of the map file not valid : <map>.cub\n";
        return (ft_custom_error(str));
	}
	if(!(path = ft_strjoin("./maps/", path)))
    {
        str = "Error\nPath allocation failed\n";
        return (ft_custom_error(str));
    }
	return (path);
}

int ft_has_valid_suffix(char *str)
{
    int i;
    
    i = 1;
    while (str[i] != '.' && str[i])
		i++;
	if (ft_strncmp(".xpm", str + i, 4) != 0 || ft_strlen(str + i) != 4)
	{
		write(2, "Error\nExtension of the texture not valid : <>.xpm\n", 51);
        return (0);
	}
    return (1);
}

int ft_open_path(char *str)
{
    int fd;
    size_t len;
    
    fd = -1;
    str = str + 2;
    if ((*str < 9 || *str > 13) && *str != 32)
        return (0);
    while ((*str >= 9 && *str <= 13) || *str == 32)
        str++;
    len = ft_strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
    if (!ft_has_valid_suffix(str))
        return (0);
    fd = open(str, O_RDONLY);
	if (fd == -1 || close(fd) == -1)
    {
        ft_system_error();
        return (0);
    }
    return (1);
}

int ft_valid_number_range(char *str, int range)
{
    int nb;
    char *dup;

    nb = 0;
    dup = ft_strdup(str);
    if (!dup)
        return (0);
    dup[range] = '\0';
    nb = ft_atoi(dup);
    if (nb >= 0 && nb <= 255)
    {
        free(dup);
        return (1);
    }
    free(dup);
    return (0);    
}

int ft_check_until_comma_or_null(char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] != 44)
    {
        if (str[i] != 32 && (str[i] < 9 || str[i] > 13))
            return (-1);
        i++;
    }
    return (i);
}

int ft_valid_characters(char *str, int range, int *len, int *rgb)
{
    int i;

    i = 0;
    while (str[i] && i < range)
    {
        if (str[i] < 48 || str[i] > 57)
            return (0);
        i++;
    }
    *len = ft_check_until_comma_or_null(str + i);
    if (*len == -1)
        return (0);
    if (!ft_valid_number_range(str, range))
        return (0);
    *rgb = *rgb + 1;
    if (*rgb > 3 || (*rgb == 3 && str[i + *len] == 44))
        return (0);
    if (str[i + *len] == 44)
        *len = *len + 1;
    return (1);
}

int ft_valid_color_range(char *str, int *rgb)
{
    int i;
    int len;
    
    len = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] != 44 && str[i] != 32 && (str[i] < 9 || str[i] > 13))
            i++;
        else
        {
            if(!ft_valid_characters(str, i, &len, rgb))
                return (0);
            str = str + i + len;
            i = 0;
            len = 0;
            while (str && ((*str >= 9 && *str <= 13) || *str == 32))
                str++;
        }
    }
    return (1);
}

int ft_valid_color(char *str)
{
    int rgb;
    
    rgb = 0;
    str = str + 1;
    if ((*str < 9 || *str > 13) && *str != 32)
        return (0);
    while ((*str >= 9 && *str <= 13) || *str == 32)
        str++;
    if (!ft_valid_color_range(str, &rgb) || rgb != 3)
        return (0);
    return (1);
}


int ft_element_is_valid(char *str)
{
    int value;
    const char *prefix[6] = {"NO", "SO", "WE", "EA", "F", "C"};
    int i;

    value = -1;
    i = 0;
    while ((*str >= 9 && *str <= 13) || *str == 32)
        str++;
    while (value != 0 && i < 4)
    {
        value = ft_strncmp(prefix[i], str, 2);
        i++;
    }
    while (value != 0 && i < 6)
    {
        value = ft_strncmp(prefix[i], str, 1);
        i++;
    }
    i--;
    if (value == 0 && i != 4 && i != 5 && ft_open_path(str))
        return (i);
    else if (value == 0 && ft_valid_color(str))
        return (i);
    return (-1);
}

int ft_check_array(int array[6])
{
    int i;
    int j;
    int duplicates;

    i = 0;
    duplicates = 0;
    while (i < 6)
    {
        j = 0;
        while (j < 6)
        {
            if (i == array[j])
                duplicates++;
            if (duplicates == 2)
                return (0);
            j++;
        }
        i++;
        duplicates = 0;
    }
    return (1);
}

int ft_free_line(t_map *map)
{
    free(map->line);
    return (1);
}

int ft_line_is_space(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if ((str[i] < 9 || str[i] > 13) && str[i] != 32)
            return (0);
        i++;
    }
    return (1);
}

int ft_textures_and_colors(t_map *map, int elements)
{
    int array[6];

    while (++elements < 6)
        array[elements] = 0;
    elements = 0;
	while (map->line != NULL)
	{
		free(map->line);
		map->line = get_next_line(map->fd);
        if (map->line && elements == 6 && !ft_line_is_space(map->line))
            break;
        if (map->line && !ft_line_is_space(map->line))
        {
            array[elements] = ft_element_is_valid(map->line);
            if (array[elements] == -1)
                return (-2);
            elements++;
        }
	}
    if (elements < 6)
        return (-4);
    else if (!ft_check_array(array))
        return (-3);
    return (1);
}

int ft_elements_to_parse(t_map *map)
{
    int value;
    int elements;
    char *str;

    str = NULL;
    elements = -1;
    map->fd = open(map->path, O_RDONLY);
	if (map->fd == -1)
        return (ft_map_error(1));
	map->line = (char *)malloc(sizeof(char *));
	if (!map->line)
        return (ft_map_error(0));
    value = ft_textures_and_colors(map, elements);
    if (value == -2 && ft_free_line(map))
        str = "Invalid element or can't open path!\n";
    else if (value == -3 && ft_free_line(map))
        str = "There are duplicates in the elements!\n";
    else if (value == -4)
        str = "There are less than 6 elements!\n";
    if (!str)
        return (1);
    ft_custom_error(str);
    return (0);
}

int	ft_check_map_left_over(t_map *map)
{
	while (map->line)
	{
		free(map->line);
		map->line = get_next_line(map->fd);
		if (map->line && !ft_line_is_space(map->line))
        {
        	free(map->line);
            return(0);        
        }
	}
    return (1);
}

int ft_char_is_space(char c)
{
    if ((c >= 9 && c <= 13) || c == 32)
        return (1);
    return (0);
}

int ft_has_valid_characters(char *str)
{
    int i;
    int j;
    int match;
    const char array[6] = "NSEW01";

    i = 0;
    match = 0;
    while (str[i])
    {
        j = 0;
        while (array[j])
        {
            if (str[i] == array[j] || ft_char_is_space(str[i]))
                match++;
            j++;
        }
        if (match == 0)
            return (0);
        match = 0;
        i++;  
    }
    return (1);
}

int	ft_map_to_parse(t_map *map)//on est sur la map!
{
    write(1, "First 6 elements are well parsed!\n", 35);
    map->row = 0;
	while (map->line != NULL)
	{
        if (!ft_has_valid_characters(map->line) && ft_free_line(map))
            return (ft_map_error(4));
        map->row++;
		free(map->line);
		map->line = get_next_line(map->fd);
		if (map->line && *map->line == '\n')
			break ;
	}
	if (map->line != 0 && !ft_check_map_left_over(map))
		return(ft_map_error(2));
    if (map->line == 0 && map->row == 0)
        return (ft_map_error(3));
    write(1, "Map is well parsed!\n", 21);
    return (1);
}

int main(int argc, char **argv)
{
	t_map   map;

    if(!(map.path = ft_check_args(argc, argv[1])))
        return (0);
    if((!ft_elements_to_parse(&map) || !ft_map_to_parse(&map)) && ft_free(&map))
        return (0);
    ft_free(&map);
    return (1);
}