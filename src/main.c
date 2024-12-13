
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:14:55 by ks19              #+#    #+#             */
/*   Updated: 2024/11/15 13:30:58 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

void	ft_init_player(t_mlx *mlx)
{
	mlx->player->player_fov_radians = FIELD_OF_VIEW * (PI / 180);
	mlx->player->start_x = mlx->data->s_x;
	mlx->player->start_y = mlx->data->s_y;
	mlx->player->px = mlx->player->start_x * TILE + 32;
	mlx->player->py = mlx->player->start_y * TILE + 32;
	mlx->player->orientation_start = mlx->data->tab[mlx->player->start_y][mlx->player->start_x];
	if (mlx->player->orientation_start == 'N')
		mlx->player->pa = 90;
	if (mlx->player->orientation_start == 'S')
		mlx->player->pa = 270;
	if (mlx->player->orientation_start == 'W')
		mlx->player->pa = 180;
	if (mlx->player->orientation_start == 'E')
		mlx->player->pa = 0;
	mlx->player->pdx = cos(ft_deg_to_rad(mlx->player->pa));
	mlx->player->pdy = -sin(ft_deg_to_rad(mlx->player->pa));
}

int	ft_init_structs(t_player *player, t_mlx *mlx, t_ray *ray)
{
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->img = NULL;
	mlx->player = player;
	mlx->ray = ray;
	ft_init_player(mlx);
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr || !txtr_checkload(mlx) || !ft_init_txtr_images(mlx))
		return (0);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT,
			"cube");
	return (1);
}

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
	float dis;

	if (mlx->ray->ra == 90 || mlx->ray->ra == 270)
		dis = (ry - mlx->player->py) * mlx->ray->flag_sin;
	else
		dis = (rx - mlx->player->px) / cos(ft_deg_to_rad(mlx->ray->ra));
	if (dis > 2147483647)
		dis = 100000;
	if (flag == 1)
	{
		mlx->ray->rx_distV = rx;
		mlx->ray->ry_distV = ry;
	}
	else if (flag == 2)
	{
		mlx->ray->rx_distH = rx;
		mlx->ray->ry_distH = ry;
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
		if (len_line && (mx > -1 && mx < len_line) && mlx->data->tab[my][mx] == '1')
			break ;
		rx = rx + (mlx->ray->flag_cos) * mlx->player->x_var;
		ry = ry + (mlx->ray->flag_sin) * mlx->player->y_var;
		j++;
	}
	dis = ft_final_dist(mlx, rx, ry, flag);
	return (dis);
}

int	ft_calculate_distH(float Tan, t_mlx *mlx)
{
	float	ry;
	float	rx;
	float	px;
	float	py;
	float	distH;

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
	distH = ft_get_dist(rx, ry, mlx, 2);
	return (distH);
}

int	ft_calculate_distV(float Tan, t_mlx *mlx)
{
	float	px;
	float	py;
	float	ry;
	float	rx;
	float	distV;

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
	distV = ft_get_dist(rx, ry, mlx, 1);
	return (distV);
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

void ft_compare_dis(float disV, float disH, t_mlx *mlx)
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

void	ft_cast_rays(t_mlx *mlx)
{
	int		i;
	float	disV;
	float	disH;
	float	Tan;

	i = 0;
	mlx->ray->ra = ft_adjust_angle(mlx->player->pa + 30);
	while (i < SCREEN_WIDTH)
	{
		ft_set_flag(mlx, &Tan);
		if (mlx->ray->ra != 0 && mlx->ray->ra != 180)
			disH = ft_calculate_distH(Tan, mlx);
		ft_set_flag(mlx, &Tan);
		if (mlx->ray->ra != 90 && mlx->ray->ra != 270)
			disV = ft_calculate_distV(Tan, mlx);
		else
			disV = disH + 1;
		if (mlx->ray->ra == 0 || mlx->ray->ra == 180)
			disH = disV + 1;
		ft_compare_dis(disV, disH, mlx);
		ft_fill_colors(mlx, i);
		mlx->ray->ra = ft_adjust_angle(mlx->ray->ra - ((float)60 / SCREEN_WIDTH));
		i++;
	}
}

int	ft_main_loop(void *mlx_ptr)
{
	t_mlx	*mlx;
	t_image	img;

	mlx = mlx_ptr;
	mlx->img = &img;
	img.img = mlx_new_image(mlx->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!img.img)
		return (1);
	img.img_data = mlx_get_data_addr(img.img, &img.bpp, &img.line_length,
			&img.endian);
	if (!img.img_data)
	{
		mlx_destroy_image(mlx->mlx_ptr, img.img);
		return (1);
	}
	ft_set_player(mlx);
	ft_cast_rays(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img->img, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img->img);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_player	player;
	t_mlx		mlx;
	t_map		map;
	t_ray		ray;

	if (!(map.path = ft_check_args(argc, argv[1])))
		return (0);
	if ((!ft_parse_valid(&map) || !ft_map_playable(&map, &data))
		&& ft_free(&map))
		return (0);
	mlx.data = &data;
	if (!ft_init_structs(&player, &mlx, &ray))
		return (0);
	mlx_hook(mlx.win_ptr, 2, 1L << 0, &key_press, &mlx);
	mlx_hook(mlx.win_ptr, 3, 1L << 1, &key_release, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, &ft_main_loop, &mlx);
	mlx_loop(mlx.mlx_ptr);
	ft_free_data(&data);
	return (0);
}
