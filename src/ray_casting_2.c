/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:35:00 by ks19              #+#    #+#             */
/*   Updated: 2024/12/17 01:11:41 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

float	ft_adjust_angle(float angle)
{
	if (angle < 0)
		angle = angle + 360;
	else if (angle > 360)
		angle = angle - 360;
	return (angle);
}

float	ft_deg_to_rad(float ray_angle)
{
	float	ray_radian;

	ray_radian = ((ray_angle / 180) * PI);
	return (ray_radian);
}

float	ft_final_dist(t_mlx *mlx, float rx, float ry, int flag)
{
	float	dis;

	if (mlx->ray->ra == 90 || mlx->ray->ra == 270)
		dis = (ry - mlx->player->py) * mlx->ray->flag_sin;
	else
		dis = (rx - mlx->player->px) / cos(ft_deg_to_rad(mlx->ray->ra));
	if (dis > 2147483647)
		dis = 100000;
	if (flag == 1)
	{
		mlx->ray->rx_distv = rx;
		mlx->ray->ry_distv = ry;
	}
	else if (flag == 2)
	{
		mlx->ray->rx_disth = rx;
		mlx->ray->ry_disth = ry;
	}
	return (dis);
}

float	ft_get_dist(float rx, float ry, t_mlx *mlx, int flag)
{
	int		j;
	int		mx;
	int		my;
	int		len_line;
	float	dis;

	j = 0;
	mlx->ray->ray_coord = 30;
	len_line = 0;
	while (j < mlx->ray->ray_coord)
	{
		mx = (int)rx / 64;
		my = (int)ry / 64;
		len_line = 0;
		if (my > -1 && my < mlx->data->row)
			len_line = ft_strlen(mlx->data->tab[my]);
		if (len_line && (mx > -1 && mx < len_line)
			&& mlx->data->tab[my][mx] == '1')
			break ;
		rx = rx + (mlx->ray->flag_cos) * mlx->player->x_var;
		ry = ry + (mlx->ray->flag_sin) * mlx->player->y_var;
		j++;
	}
	dis = ft_final_dist(mlx, rx, ry, flag);
	return (dis);
}
