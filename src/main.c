
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
	mlx->player->orientation_start = mlx->data->tab[mlx->player->py][mlx->player->px];
	printf("%c\n", mlx->player->orientation_start);
	if (mlx->player->orientation_start == 'N')
		mlx->player->start_angle = 90;
	if (mlx->player->orientation_start == 'S')
		mlx->player->start_angle = 270;
	if (mlx->player->orientation_start == 'E')
		mlx->player->start_angle = 0;
	if (mlx->player->orientation_start == 'W')
		mlx->player->start_angle = 180;
	printf("player well init\n");
}
void	ft_init_data(t_mlx *mlx)
{
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->img = NULL;
}
void	ft_init_structs(t_player *player, t_mlx *mlx, t_ray *ray)
{
	mlx->player = player;
	printf("init mlx->player ptr [ok]\n");
	mlx->ray = ray;
	printf("init mlx->ray ptr [ok]\n");
	ft_init_player(mlx);
}
float	get_v_inter(t_mlx *mlx, float angle)
{
	(void)mlx;
	(void)angle;
	return (0);
}
float	get_h_inter(t_mlx *mlx, float angle)
{
	(void)mlx;
	(void)angle;
	return (0);
}

float	ft_adjust_angle(int angle)
{
	if (angle < 0)
		angle = angle + 360;
	if (angle > 360)
		angle = angle - 360;
	return (angle);
}
int	ft_get_wall_color(t_mlx *mlx, int orientation_flag)
{
	mlx->ray->ray_angle = ft_adjust_angle(mlx->ray->ray_angle);
	if (orientation_flag == VERTICAL_WALL)
	{
		if (mlx->ray->ray_angle > 90 && mlx->ray->ray_angle < 270)
			return (0xB5B5B5FF); // mur regarde  gauche
		else
			return (0xB5B5B5FF); // mur regarde a droite
	}
	else
	{
		if (mlx->ray->ray_angle > 0 && mlx->ray->ray_angle < 180)
			return (0xF5F5F5FF); // mur regarde vers le bas
		else
			return (0xF5F5F5FF); // mur regarde vers le haut
	}
	return (0);
}
int	ft_draw_px_collumn(t_mlx *mlx, int ray_num, int wall_top_px,
		int wall_bot_px)
{
	int	color;
	int	j;
	int	i;

	color = ft_get_wall_color(mlx, mlx->ray->wall_touch);
	// retourne le 0x du wall celon son orientation
	// WALL
	j = wall_top_px;
	while (j < wall_bot_px)
	{
		// apllique la couleur au bon pixel en question
		ft_put_pixel_to_screen(mlx, ray_num, j, color);
		j++;
	}
	// FLOOR
	i = wall_bot_px;
	while (i < SCREEN_HEIGHT)
	{
		ft_put_pixel_to_screen(mlx, ray_num, i, color);
		i++;
	}
	// CEILING
	i = 0;
	while (i < wall_top_px)
	{
		ft_put_pixel_to_screen(mlx, ray_num, i, color);
		i++;
	}
	return (0);
}
int	ft_put_wall(t_mlx *mlx, int ray_num)
{
	double	wall_height;
	double	bottom_px;
	double	top_px;

	wall_height = ((64 / mlx->ray->wall_distance) * ((SCREEN_WIDTH / 2)
				/ tan(mlx->player->player_fov_radians)));
	top_px = (SCREEN_HEIGHT / 2) - (wall_height / 2);
	bottom_px = (SCREEN_HEIGHT / 2) + (wall_height / 2);
	if (bottom_px > SCREEN_HEIGHT)
		bottom_px = SCREEN_HEIGHT;
	if (top_px < 0)
		top_px = SCREEN_HEIGHT;
	ft_draw_px_collumn(mlx, ray_num, top_px, bottom_px);
	return (0);
}
float	ft_deg_to_rad(float ray_angle)
{
	float	ray_radian;

	ray_radian = ((ray_angle / 180) * PI);
	return (ray_radian);
}

int	ft_put_pixel_to_screen(t_mlx *mlx, int x, int y, int color)
{
	if (x < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT || y < 0)
		return (0);
	mlx_pixel_put(mlx->img, mlx->win_ptr, x, y, color);
	return (0);
}
int	ft_cast_rays(t_mlx *mlx)
{
	int mx, my, mp, ray_counter, i, j, ray_coord, len_line;
	float px, py, vx, vy, rx, ry, ra, x_var, y_var, disV, disH, Tan, final_dist;
	ray_counter = 1;
	ray_coord = 1;
	i = 0;
	ra = ft_adjust_angle(mlx->player->start_angle) + 30; // 0 + 30
	px = mlx->player->start_x * TILE;
	py = mlx->player->start_y * TILE;
	while (i < ray_counter)
	{
		Tan = tan(ft_deg_to_rad(ra));
		x_var = y_var / Tan;
		y_var = 64;
		// horizontal
		if (cos(ft_deg_to_rad(ra)) > 0)
		{
			rx = px + x_var;
			if (sin(ft_deg_to_rad(ra)) > 0) // de 0 a 90
				ry = py - y_var;
			if (sin(ft_deg_to_rad(ra)) < 0) // de 270 a 360
				ry = py + y_var;
		}
		if (cos(ft_deg_to_rad(ra)) < 0)
		{
			rx = px - x_var;
			if (sin(ft_deg_to_rad(ra)) > 0) // de 90 a 180
				ry = py - y_var;
			if (sin(ft_deg_to_rad(ra)) < 0) // de 180 a 270
				ry = py + y_var;
		}
		j = 0;
		while (j < (mlx->data->row - ((int)py / 64) - 1))
		{
			mx = (int)rx / 64;
			my = (int)ry / 64;
			len_line = 0;
			if (my < mlx->data->row)
				len_line = ft_strlen(mlx->data->tab[my]);
			if (my < mlx->data->row && mx < len_line
				&& mlx->data->tab[my][mx] == 1)
			{
				disH = (rx - px) / cos(ft_deg_to_rad(ra));
				break ;
			}
			ry = ry - y_var;
			rx = rx + x_var;
			j++;
		}
		vx = rx;
		vy = ry;
		// vertical
		// cas de 0 a 90 et 270 a 360 ie lorsque cos est pos!
		if (cos(ft_deg_to_rad(ra)) > 0)
		{
			if (sin(ft_deg_to_rad(ra)) > 0) // de 0 a 90
			{
				Tan = tan(ft_deg_to_rad(ra));
				x_var = 64;
				y_var = x_var * Tan;
				ry = py - y_var;
				rx = px + x_var;
			}
			if (sin(ft_deg_to_rad(ra)) < 0) // de 270 a 360
			{
				Tan = tan(ft_deg_to_rad(ra));
				x_var = 64;
				y_var = x_var * Tan;
				ry = py + y_var;
				rx = px + x_var;
			}
		}
		if (cos(ft_deg_to_rad(ra)) < 0)
		{
			if (sin(ft_deg_to_rad(ra)) > 0) // de 90 a 180
			{
				Tan = tan(ft_deg_to_rad(ra));
				x_var = 64;
				y_var = x_var * Tan;
				ry = py - y_var;
				rx = px - x_var;
			}
			if (sin(ft_deg_to_rad(ra)) < 0) // de 180 a 270
			{
				Tan = tan(ft_deg_to_rad(ra));
				x_var = 64;
				y_var = x_var * Tan;
				ry = py + y_var;
				rx = px - x_var;
			}
		}
		j = 0;
		while (j < ray_coord)
		{
			mx = (int)rx / 64;
			my = (int)ry / 64;
			len_line = 0;
			if (my < mlx->data->row)
				len_line = ft_strlen(mlx->data->tab[my]);
			if (my < mlx->data->row && mx < len_line
				&& mlx->data->tab[my][mx] == 1)
			{
				disV = (rx - px) / cos(ft_deg_to_rad(ra));
				break ;
			}
			ry = ry - y_var;
			rx = rx + x_var;
			j++;
		}
		final_dist = disV;
		mlx->ray->wall_touch = VERTICAL_WALL;
		if (disH < disV)
		{
			rx = vx;
			ry = vy;
			final_dist = disH;
			mlx->ray->wall_touch = HORIZONTAL_WALL;
		}
		mlx->ray->wall_distance = final_dist;
		mlx->ray->ray_angle = ra;
		ft_put_wall(mlx, i);
		ra = ft_adjust_angle(ra - 1);
		i++;
	}
	return (0);
}

int	ft_main_loop(void *mlx_ptr)
{
	t_mlx	*mlx;

	mlx = mlx_ptr;
	mlx->img = mlx_new_image(mlx->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	printf("Setting new image\n");
	ft_set_player(mlx);
	ft_cast_rays(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img);
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
	ft_print_data(&data);
	printf("initializing structs\n");
	mlx.data = &data;
	ft_init_structs(&player, &mlx, &ray);
	printf("init struct done\n");
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		return (0);
	ft_main_loop(mlx.mlx_ptr);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT,
			"cube");
	mlx_key_hook(mlx.mlx_ptr, &key_press, &mlx);
	mlx_key_hook(mlx.mlx_ptr, &key_release, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, &ft_main_loop, &mlx);
	printf("Entering mlx_loop...\n");
	mlx_loop(mlx.mlx_ptr);
	ft_free_data(&data);
	return (0);
}
