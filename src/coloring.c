/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:52:32 by roko              #+#    #+#             */
/*   Updated: 2024/12/13 17:46:43 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

int	ft_put_pixel_to_screen(t_mlx *mlx, int x, int y, int color)
{
	char	*data;
	int		index;

	data = mlx->img->img_data;
	index = (y * SCREEN_WIDTH + x) * 4;
	data[index] = color & 0xFF;
	data[index + 1] = (color >> 8) & 0xFF;
	data[index + 2] = (color >> 16) & 0xFF;
	data[index + 3] = 0;
	return (0);
}

double	ft_get_x_val(t_mlx *mlx)
{
	double	x_o;

	if (mlx->ray->wall_touch == HORIZONTAL_WALL)
		x_o = (int)fmodf((mlx->ray->rx * (64 / 64)), 64);
	else
		x_o = (int)fmodf((mlx->ray->ry * (64 / 64)), 64);
	return (x_o);
}

int	reverse_bytes(int c)
{
	unsigned int	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}

int	ft_draw_ceiling_floor(t_mlx *mlx, int ray_num, int wall_top_px,
		int wall_bot_px)
{
	int	i;

	i = wall_bot_px;
	while (i < SCREEN_HEIGHT)
	{
		ft_put_pixel_to_screen(mlx, ray_num, i, 0xFF6347FF);
		i++;
	}
	i = 0;
	while (i < wall_top_px)
	{
		ft_put_pixel_to_screen(mlx, ray_num, i, 0x0000FF00);
		i++;
	}
	return (0);
}

int	ft_fill_colors(t_mlx *mlx, int ray_num)
{
	double	wall_height;
	int		diff;
	int		wall_px[2];

	diff = 0;
	mlx->ray->index = ray_num;
	wall_height = (64 / mlx->ray->wall_distance) * ((SCREEN_WIDTH / 2)
			/ tan(mlx->player->player_fov_radians / 2));
	wall_px[0] = (SCREEN_HEIGHT / 2) - (wall_height / 2);
	wall_px[1] = (SCREEN_HEIGHT / 2) + (wall_height / 2);
	if (wall_px[1] > SCREEN_HEIGHT)
		wall_px[1] = SCREEN_HEIGHT;
	if (wall_px[0] < 0)
	{
		diff = wall_px[0];
		wall_px[0] = 0;
	}
	ft_draw_wall(mlx, wall_px, wall_height, diff);
	ft_draw_ceiling_floor(mlx, ray_num, wall_px[0], wall_px[1]);
	return (0);
}