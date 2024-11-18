	// // prefix = (char **)malloc(sizeof(char *) * 6);
    // prefix[0] = "NO";
    // prefix[1] = "SO";
    // prefix[2] = "WE";
    // prefix[3] = "EA";
    // prefix[4] = "F";
    // prefix[5] = "C";

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

// char *ft_elements_to_parse(t_map *map)
// {
//     int value;

//     map->fd = open(map->path, O_RDONLY);
// 	if (map->fd == -1)
//         return (ft_map_error(1, map));
//     value = ft_textures_and_colors(map);
//     if (value == 0)
//         return (NULL);
//     if (value == -1 && ft_free_line(map))
//         return (ft_custom_error("There are more than 6 elements!\n"));
//     else if (value == -2 && ft_free_line(map))
//         return (ft_custom_error("Invalid element or can't open path!\n"));
//     else if (value == -3)
//         return (ft_custom_error("There are duplicates in the elements!\n"));
//     else if (value == -4)
//         return (ft_custom_error("There are less than 6 elements!\n"));
//     return ("ok");
// }