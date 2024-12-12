/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:15:20 by ks19              #+#    #+#             */
/*   Updated: 2024/12/11 16:57:31 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

void	ft_init_textures_to_null(t_map *map)
{
	map->index = -1;
	map->NO = NULL;
	map->SO = NULL;
	map->EA = NULL;
	map->WE = NULL;
	map->tab = NULL;
	map->tmp = NULL;
}
void	ft_print_elements(t_map *map)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		printf("F %d\n", map->F[i]);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		printf("C %d\n", map->C[i]);
		i++;
	}
	printf("NO %s\n", map->NO);
	printf("SO %s\n", map->SO);
	printf("EA %s\n", map->EA);
	printf("WE %s\n", map->WE);
	printf("-----------------\n");
	ft_print_table(map->tab);
}

int	ft_free_table(char **buffer)
{
	int	i;

	if (!buffer)
		return (1);
	i = -1;
	while (buffer[++i] != NULL)
		free(buffer[i]);
	free(buffer);
	return (1);
}

void	ft_print_table(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}
int	ft_reopen_fd(t_map *map)
{
	if (close(map->fd) == -1)
		return (0);
	map->fd = open(map->path, O_RDONLY);
	if (map->fd == -1)
		return (ft_map_error(1));
	return (1);
}
