
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:52:32 by roko              #+#    #+#             */
/*   Updated: 2024/12/01 20:41:30 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

int	ft_get_wall_color(t_mlx *mlx, int orientation_flag)
{
	mlx->ray->ra = ft_adjust_angle(mlx->ray->ra);
	if (orientation_flag == VERTICAL_WALL)
	{
		if (mlx->ray->ra > 90 && mlx->ray->ra < 270)
			return (0x006400FF);
		else
			return (0x1E90FFFF);
	}
	else
	{
		if (mlx->ray->ra > 0 && mlx->ray->ra < 180)
			return (0xFFD700FF);
		else
			return (0x8B0000FF);
	}
	return (0);
}

void	set_pixel(char *data, int width, int x, int y, int color)
{
	int	index;

	index = (y * width + x) * 4;
	data[index] = color & 0xFF;
	data[index + 1] = (color >> 8) & 0xFF;
	data[index + 2] = (color >> 16) & 0xFF;
	data[index + 3] = 0;
}

int	ft_put_pixel_to_screen(t_mlx *mlx, int x, int y, int color)
{
	char	*data;

	data = mlx->img->img_data;
	set_pixel(data, SCREEN_WIDTH, x, y, color);
	return (0);
}

int	ft_draw_px_collumn(t_mlx *mlx, int ray_num, int wall_top_px,
		int wall_bot_px)
{
	int	color;
	int	j;
	int	i;

	color = ft_get_wall_color(mlx, mlx->ray->wall_touch);
	// printf("Wall color : %d \n", color);
	// retourne le 0x du wall celon son orientation
	// WALL
	j = wall_top_px;
	while (j < wall_bot_px)
	{
		// apllique la couleur au bon pixel en question
		ft_put_pixel_to_screen(mlx, ray_num, j, color);
		j++;
	}
	// printf("Wall print done\n");
	// FLOOR
	i = wall_bot_px;
	while (i < SCREEN_HEIGHT)
	{
		ft_put_pixel_to_screen(mlx, ray_num, i, 0xFF6347FF);
		i++;
	}
	// printf("Floor done\n");
	// CEILING
	i = 0;
	while (i < wall_top_px)
	{
		ft_put_pixel_to_screen(mlx, ray_num, i, 0x0000FF00);
		i++;
	}
	// printf("Ceiling done \n");
	return (0);
}
int	ft_fill_colors(t_mlx *mlx, int ray_num)
{
	double wall_height;
	double bottom_px;
	double top_px;

	// printf("put_wall_dist = %f\n", mlx->ray->wall_distance);
	wall_height = (64 / mlx->ray->wall_distance) * ((SCREEN_WIDTH / 2)
			/ tan(mlx->player->player_fov_radians / 2));
	top_px = (SCREEN_HEIGHT / 2) - (wall_height / 2);
	bottom_px = (SCREEN_HEIGHT / 2) + (wall_height / 2);
	if (bottom_px > SCREEN_HEIGHT)
		bottom_px = SCREEN_HEIGHT;
	if (top_px < 0)
		top_px = 0;
	ft_draw_px_collumn(mlx, ray_num, top_px, bottom_px);
	return (0);
}