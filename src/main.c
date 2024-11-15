/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:14:55 by ks19              #+#    #+#             */
/*   Updated: 2024/11/15 19:03:51 by ks19             ###   ########.fr       */
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

int	ft_map_error(int error, t_map *map)
{
	char	*str;

    str = NULL;
	if (error == 0 && ft_free(map))
		str = "Error\nFailed Allocation!\n";
    else if (error == 1 && ft_free(map))
        ft_system_error();
    else if (error == 2 && ft_free(map))
        str = "Error\nWrong map format, remaining leftovers!\n";
    else if (error == 3 && ft_free(map))
        str = "Error\nEmpty map!\n";
    ft_custom_error(str);
    return (0);
}

int	ft_check_map_left_over(t_map *map)
{
	while (map->line)
	{
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
	map->line = (char *)malloc(sizeof(char *));
	if (!map->line)
        return (ft_map_error(0, map));
	while (map->line != NULL)
	{
		if (map->line)
			free(map->line);
		map->line = get_next_line(map->fd);
		if (map->line == 0 || *map->line == '\n')
			break ;
		map->row++;
	}
	if (map->line != 0 && !ft_check_map_left_over(map))
		return (0);
    if (map->line == 0 && map->row == 0)
        return (ft_map_error(3, map));
    return (1);
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

int ft_open_path(char *str)
{
    int fd;
    
    str = str + 2;
    if ((*str < 9 || *str > 13) && *str != 32)
        return (0);
    while ((*str >= 9 && *str <= 13) || *str == 32)
        str++;
    printf("%s\n", str);
    str = ft_strjoin(getcwd(NULL, 0), str);
    printf("%s\n", str);
    fd = open(str, O_RDONLY);
	if (fd == -1)
    {
        printf("%s\n", getcwd(NULL, 0));
        ft_system_error();
        return (0);
    }
    close (fd);
    return (1);
}

// char *remove_spaces(char *str)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (str[i])
// 	{
// 		if (str[i] != 7)
// 		{
// 			str[count] = str[i];
// 			count++;
// 		}
// 		i++;
// 	}
// 	str[count] = '\0';
//     return (str);
// }

// char *ft_handle_spaces(char *str)
// {
//     int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
//             str[i] = 7;
// 		i++;
// 	}
//     str = remove_spaces(str);
//     return (str);
// }



int ft_valid_number_range(char *str, int range)
{
    int nb;

    nb = 0;
    str[range] = '\0';
    nb = ft_atoi(str);
    if (nb >= 0 && nb <= 255)
        return (1);
    return (0);    
    
}

int ft_check_until_comma_or_null(char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] != 44)//on s arrete sur NULL ou une virgule
    {
        if (str[i] != 32 && (str[i] < 9 || str[i] > 13))//autre chose que des espaces!
            return (-1);
        i++;
    }
    return (i);
}

int ft_valid_characters(char *str, int range, int *len, int *rgb)
{
    int i;

    i = 0;
    while (str[i] && i < range)//len est un espace ou une virgule!
    {
        if (str[i] < 48 || str[i] > 57)//que des chiffres!
            return (0);
        i++;//un espace ou une virgule
    }
    *len = ft_check_until_comma_or_null(str + i);//on est sur espace ou virgule
    if (*len == -1)
        return (0);//*len est sur apres virgule ou NULL
    if (!ft_valid_number_range(str, range) && *rgb++)
        return (0);
    if (*rgb > 3 || (*rgb == 3 && str[*len] == 44))
        return (0);
    if (str[*len] == 44)
        *len = *len + 1;
    return (1);
}

int ft_valid_color_range(char *str)
{
    int rgb;
    int i;
    int len;
    
    rgb = 0;
    len = 0;
    i = 0;//on s arrete soit sur une virgule, un null, ou un espace!
    while (str[i])
    {
        //on est pas sur virgule ou espace! je suis caractere!
        if (str[i] != 44 && str[i] != 32 && (str[i] < 9 || str[i] > 13))
            i++;
        else//i est d office sur espace ou virgule!
        {
            if(!ft_valid_characters(str, i, &len, &rgb))
                return (0);
            str = str + len;//on est soit sur post virgule, soit sur NULL
            i = 0;
            len = 0;
            while (str && ((*str >= 9 && *str <= 13) || *str == 32))
                str++;
        }
    }
    return (rgb);
}

int ft_valid_color(char *str)
{
    str = str + 1;
    if ((*str < 9 || *str > 13) && *str != 32)//autre chose qu un espace!
        return (0);
    while ((*str >= 9 && *str <= 13) || *str == 32)//skip les espaces
        str++;
    // printf("%s\n", str);
    // str = ft_handle_spaces(str);
    printf("%s\n", str);//on arrive sur un char!
    if (ft_valid_color_range(str) != 3)
        return (0);
    return (1);
}


int ft_element_is_valid(char *str)
{
    int value;
    const char *prefix[6] = {"NO", "SO", "WE", "EA", "F", "C"};
    int i;

	// // prefix = (char **)malloc(sizeof(char *) * 6);
    // prefix[0] = "NO";
    // prefix[1] = "SO";
    // prefix[2] = "WE";
    // prefix[3] = "EA";
    // prefix[4] = "F";
    // prefix[5] = "C";
    while ((*str >= 9 && *str <= 13) || *str == 32)
        str++;
    value = -1;
    i = 0;
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
    if (value == 0 && i != 4 && i != 5 && ft_open_path(str))
        return (i - 1);
    else if (value == 0 && ft_valid_color(str))
        return (i - 1);
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

int ft_textures_and_colors(t_map *map)
{
    int array[6];
    int i;


	map->line = (char *)malloc(sizeof(char *));
	if (!map->line)
        return (ft_map_error(0, map));
    i = 0;
    while (i < 6)
    {
        array[i] = 0;
        i++;
    }
    i = 0;
	while (map->line != NULL)
	{
		free(map->line);
		map->line = get_next_line(map->fd);
        if (map->line && *map->line != '\n' && i == 6)
            return (-1);
        if (map->line && *map->line != '\n')
        {
            array[i] = ft_element_is_valid(map->line);
            if (array[i] == -1)
                return (-2);
            i++;
        }
	}
    if (i < 6)
        return (-4);
    if (!ft_check_array(array))
        return (-3);
    return (1);
}

char *ft_elements_to_parse(t_map *map)
{
    int value;

    value = ft_textures_and_colors(map);
    if (value == 0)
        return (NULL);
    if (value == -1 && ft_free_line(map))
        return (ft_custom_error("There are more than 6 elements!\n"));
    else if (value == -2 && ft_free_line(map))
        return (ft_custom_error("Invalid element or can't open path!\n"));
    else if (value == -3)
        return (ft_custom_error("There are duplicates in the elements!\n"));
    else if (value == -4)
        return (ft_custom_error("There are less than 6 elements!\n"));
    return ("ok");
}

int main(int argc, char **argv)
{
	t_map   map;

    if(!(map.path = ft_check_args(argc, argv[1])))
        return (0);
    map.fd = open(map.path, O_RDONLY);
	if (map.fd == -1)
        return (ft_map_error(1, &map));
    close(map.fd);
    if(!ft_elements_to_parse(&map))
        return (0);
    printf("ok\n");
    // if(!(ft_row_number(&map)))
    //     return (0);
    // ft_free(&map);
    return (1);
    
}