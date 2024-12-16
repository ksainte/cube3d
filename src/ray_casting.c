/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:31:47 by ks19              #+#    #+#             */
/*   Updated: 2024/12/17 00:30:33 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

int	ft_calculate_dis_h(float Tan, t_mlx *mlx)
{
	float	ry;
	float	rx;
	float	px;
	float	py;
	float	disth;

	px = mlx->player->px;
	py = mlx->player->py;
	mlx->player->y_var = 64;
	mlx->ray->flag_sin = mlx->ray->flag_sin * mlx->ray->Tan_slope;
	if (mlx->ray->ra != 90 && mlx->ray->ra != 270)
		mlx->player->x_var = mlx->player->y_var / Tan;
	else
		mlx->player->x_var = 0;
	if (sin(ft_deg_to_rad(mlx->ray->ra)) > 0.0000001)
		ry = (((int)py >> 6) << 6) - 0.0001;
	else if (sin(ft_deg_to_rad(mlx->ray->ra)) < -0.0000001)
		ry = (((int)py >> 6) << 6) + 64;
	if (mlx->ray->ra == 90 || mlx->ray->ra == 270)
		rx = px;
	else
		rx = px + (py - ry) / Tan;
	disth = ft_get_dist(rx, ry, mlx, 2);
	return (disth);
}

int	ft_calculate_dis_v(float Tan, t_mlx *mlx)
{
	float	px;
	float	py;
	float	ry;
	float	rx;
	float	distv;

	px = mlx->player->px;
	py = mlx->player->py;
	mlx->player->x_var = 64;
	mlx->ray->flag_cos = mlx->ray->flag_cos * mlx->ray->Tan_slope;
	mlx->player->y_var = mlx->player->x_var * Tan;
	if (cos(ft_deg_to_rad(mlx->ray->ra)) > 0.0000001)
		rx = (((int)px >> 6) << 6) + 64;
	else if (cos(ft_deg_to_rad(mlx->ray->ra)) < -0.0000001)
		rx = (((int)px >> 6) << 6) - 0.0001;
	ry = py + (px - rx) * Tan;
	distv = ft_get_dist(rx, ry, mlx, 1);
	return (distv);
}

void	ft_compare_dis(float disV, float disH, t_mlx *mlx)
{
	float	ca;

	if (disH < disV)
	{
		mlx->ray->rx = mlx->ray->rx_distH;
		mlx->ray->ry = mlx->ray->ry_distH;
		disV = disH;
		mlx->ray->wall_touch = HORIZONTAL_WALL;
	}
	else if (disH > disV)
	{
		mlx->ray->rx = mlx->ray->rx_distV;
		mlx->ray->ry = mlx->ray->ry_distV;
		mlx->ray->wall_touch = VERTICAL_WALL;
	}
	else if (disH == disV)
	{
		mlx->ray->rx = mlx->ray->rx_distV;
		mlx->ray->ry = mlx->ray->ry_distV;
	}
	ca = ft_adjust_angle(mlx->player->pa - mlx->ray->ra);
	disV = disV * cos(ft_deg_to_rad(ca));
	mlx->ray->wall_distance = disV;
}

void	ft_set_flag(t_mlx *mlx, float *Tan)
{
	mlx->ray->Tan_slope = 1;
	mlx->ray->flag_cos = 1;
	mlx->ray->flag_sin = 1;
	if (cos(ft_deg_to_rad(mlx->ray->ra)) > 0.0000001)
		mlx->ray->flag_sin = -1;
	if (sin(ft_deg_to_rad(mlx->ray->ra)) < -0.0000001)
		mlx->ray->flag_cos = -1;
	if (mlx->ray->ra != 90 && mlx->ray->ra != 270)
	{
		*Tan = tan(ft_deg_to_rad(mlx->ray->ra));
		if (*Tan < -0.0000001)
			mlx->ray->Tan_slope = -1;
	}
	if (mlx->ray->ra == 90 || mlx->ray->ra == 180)
		mlx->ray->Tan_slope = -1;
}

void	ft_cast_rays(t_mlx *mlx)
{
	int		i;
	float	disv;
	float	dish;
	float	tan;

	i = 0;
	mlx->ray->ra = ft_adjust_angle(mlx->player->pa + 30);
	while (i < SCREEN_WIDTH)
	{
		ft_set_flag(mlx, &tan);
		if (mlx->ray->ra != 0 && mlx->ray->ra != 180)
			dish = ft_calculate_dis_h(tan, mlx);
		ft_set_flag(mlx, &tan);
		if (mlx->ray->ra != 90 && mlx->ray->ra != 270)
			disv = ft_calculate_dis_v(tan, mlx);
		else
			disv = dish + 1;
		if (mlx->ray->ra == 0 || mlx->ray->ra == 180)
			dish = disv + 1;
		ft_compare_dis(disv, dish, mlx);
		ft_fill_colors(mlx, i);
		mlx->ray->ra = ft_adjust_angle(mlx->ray->ra - ((float)FIELD_OF_VIEW
					/ SCREEN_WIDTH));
		i++;
	}
}
