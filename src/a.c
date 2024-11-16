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