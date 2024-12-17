/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:34:25 by ks19              #+#    #+#             */
/*   Updated: 2024/12/17 00:56:37 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

void	ft_system_error(void)
{
	write(2, strerror(errno), strlen(strerror(errno)));
	write(2, "\n", 1);
}

char	*ft_custom_error(char *str)
{
	if (str)
		write(2, str, ft_strlen(str));
	return (NULL);
}

int	ft_free(t_map *map)
{
	ft_free_table(map->tab);
	free(map->path);
	free(map->no);
	free(map->so);
	free(map->ea);
	free(map->we);
	if (map->fd != -1 && close(map->fd) == -1)
		ft_system_error();
	return (1);
}

int	ft_free_line(t_map *map)
{
	free(map->line);
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
	else if (error == 5)
		str = "Error\nThe map should have 1 spawning position!\n";
	else if (error == 6)
		str = "Error\nThe playable part of the map is invalid!\n";
	else if (error == 7)
		str = "Error\nThe copy of map to data failed!\n";
	ft_custom_error(str);
	return (0);
}
