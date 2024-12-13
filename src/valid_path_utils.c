/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:03:51 by ks19              #+#    #+#             */
/*   Updated: 2024/12/13 20:17:42 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

char	*ft_check_args(int argc, char *str)
{
	char	*path;

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
	if (!(path = ft_strjoin("./maps/", path)))
	{
		str = "Error\nPath allocation failed\n";
		return (ft_custom_error(str));
	}
	return (path);
}

int	ft_has_valid_suffix(char *str)
{
	int	i;

	i = 1;
	while (str[i] != '.' && str[i])
		i++;
	if (ft_strncmp(".xpm", str + i, 4) != 0 || ft_strlen(str + i) != 4)
	{
		write(2, "Extension of the texture not valid : <>.xpm\n", 45);
		return (0);
	}
	return (1);
}

int	ft_open_path(char *str)
{
	int		fd;
	size_t	len;

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
