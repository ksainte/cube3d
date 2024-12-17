/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:52:32 by roko              #+#    #+#             */
/*   Updated: 2024/12/17 14:48:58 by ks19             ###   ########.fr       */
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

int	ft_draw_ceiling_floor(t_mlx *mlx, int ray_num)
{
	int	i;

	i = mlx->ray->wall_bottom;
	while (i < SCREEN_HEIGHT)
	{
		ft_put_pixel_to_screen(mlx, ray_num, i, rgb_to_hex(mlx->data->f[0],
				mlx->data->f[1], mlx->data->f[2]));
		i++;
	}
	i = 0;
	while (i < mlx->ray->wall_top)
	{
		ft_put_pixel_to_screen(mlx, ray_num, i, rgb_to_hex(mlx->data->c[0],
				mlx->data->c[1], mlx->data->c[2]));
		i++;
	}
	return (0);
}

int	ft_fill_colors(t_mlx *mlx, int ray_num)
{
	double	wall_height;
	int		diff;

	diff = 0;
	mlx->ray->index = ray_num;
	wall_height = (64 / mlx->ray->wall_distance) * ((SCREEN_WIDTH / 2)
			/ tan(mlx->player->player_fov_radians / 2));
	mlx->ray->wall_top = (SCREEN_HEIGHT / 2) - (wall_height / 2);
	mlx->ray->wall_bottom = (SCREEN_HEIGHT / 2) + (wall_height / 2);
	if (mlx->ray->wall_bottom > SCREEN_HEIGHT)
		mlx->ray->wall_bottom = SCREEN_HEIGHT;
	if (mlx->ray->wall_top < 0)
	{
		diff = mlx->ray->wall_top;
		mlx->ray->wall_top = 0;
	}
	ft_draw_wall(mlx, wall_height, diff);
	ft_draw_ceiling_floor(mlx, ray_num);
	return (0);
}
