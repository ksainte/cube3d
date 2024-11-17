/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:19:51 by asideris          #+#    #+#             */
/*   Updated: 2024/11/15 14:52:33 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

void	ft_print_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		printf("%s\n", data->map[i]);
		i++;
	}
}
void	ft_fake_map(t_data *data)
{
	data->map = malloc(sizeof(char *) * 6);
	data->map[0] = ft_strdup("111111");
	data->map[1] = ft_strdup("100101");
	data->map[2] = ft_strdup("101001");
	data->map[3] = ft_strdup("1100N1");
	data->map[4] = ft_strdup("111111");
	data->map[5] = NULL;
	data->map_h = 5;
	data->map_w = 6;
	data->player_x_map = 5;
	data->player_y_map = 1;
	ft_print_map(data);
}
