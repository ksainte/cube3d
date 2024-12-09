
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
	// printf("px is %f\n", mlx->player->px);
	// printf("py is %f\n", mlx->player->py);
	mlx->player->orientation_start = mlx->data->tab[mlx->player->start_y][mlx->player->start_x];
	// printf("letter is %c\n", mlx->player->orientation_start);
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
	// printf("player well init\n");
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
	mlx->ray = ray;
	ft_init_player(mlx);
}

float	ft_adjust_angle(float angle)
{
	if (angle < 0)
		angle = angle + 360;
	// if (angle > 359.998)
	// 	angle = 359.9248;
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

float	ft_get_dist(float rx, float ry, t_mlx *mlx, float x_var, float y_var)
{
	int		j;
	int		mx;
	int		my;
	int		len_line;
	float	dis;

	j = 0;
	mlx->ray->ray_coord = 30;
	while (j < mlx->ray->ray_coord)
	{
		mx = (int)rx / 64;
		my = (int)ry / 64;
		len_line = 0;
		if (my > -1 && my < mlx->data->row)
			len_line = ft_strlen(mlx->data->tab[my]);
		if ((my > -1 && my < mlx->data->row) && (mx > -1 && mx < len_line)
			&& mlx->data->tab[my][mx] == '1')
			break ;
		rx = rx + (mlx->ray->flag_cos) * x_var;
		ry = ry + (mlx->ray->flag_sin) * y_var;
		j++;
	}
	// printf("final rx is %f\n", rx);
	// printf("final ry is %f\n", ry);
	if (mlx->ray->ra == 90 || mlx->ray->ra == 270)
		dis = (ry - mlx->player->py) * mlx->ray->flag_sin;
	else
		dis = (rx - mlx->player->px) / cos(ft_deg_to_rad(mlx->ray->ra));
	if (dis > 2147483647)
			dis = 100000;
	return (dis);
}

int	ft_calculate_distH(float Tan, t_mlx *mlx)
{
	float	x_var;
	float	y_var;
	float	ry;
	float	rx;
	float	px;
	float	py;
	float	distH;

	px = mlx->player->px;
	py = mlx->player->py;
	y_var = 64;
	// printf("DistH: \n");
	// printf("flag_sin is %d\n", mlx->ray->flag_sin);
	// printf("Tan_slope is %d\n", mlx->ray->Tan_slope);
	mlx->ray->flag_sin = mlx->ray->flag_sin * mlx->ray->Tan_slope;
	// printf("final flag_sin is %d\n", mlx->ray->flag_sin);
	// printf("final flag_cos is %d\n", mlx->ray->flag_cos);
	if (mlx->ray->ra != 90 && mlx->ray->ra != 270)
		x_var = y_var / Tan;
	else
		x_var = 0;
	if (sin(ft_deg_to_rad(mlx->ray->ra)) > 0.0000001)       // de 0 a 180
		ry = (((int)py >> 6) << 6) - 0.0001;            // arrondi a l unite inf
	else if (sin(ft_deg_to_rad(mlx->ray->ra)) < -0.0000001) // de 180 a 360
		ry = (((int)py >> 6) << 6) + 64;                // arrondi a l unite sup
	if (mlx->ray->ra == 90 || mlx->ray->ra == 270)
		rx = px;
	else
		rx = px + (py - ry) / Tan;
	distH = ft_get_dist(rx, ry, mlx, x_var, y_var);
	// printf("disH is %f\n", distH);
	return (distH);
}

int	ft_calculate_distV(float Tan, t_mlx *mlx)
{
	float	x_var;
	float	y_var;
	float	px;
	float	py;
	float	ry;
	float	rx;
	float	distV;

	px = mlx->player->px;
	py = mlx->player->py;
	x_var = 64;
	// printf("DistV: \n");
	// printf("flag_cos is %d\n", mlx->ray->flag_cos);
	// printf("Tan_slope is %d\n", mlx->ray->Tan_slope);
	mlx->ray->flag_cos = mlx->ray->flag_cos * mlx->ray->Tan_slope;
	// printf("final flag_cos is %d\n", mlx->ray->flag_cos);
	// printf("final flag_sin is %d\n", mlx->ray->flag_sin);
	y_var = x_var * Tan;
	if (cos(ft_deg_to_rad(mlx->ray->ra)) > 0.0000001) // droite
		rx = (((int)px >> 6) << 6) + 64;
	else if (cos(ft_deg_to_rad(mlx->ray->ra)) < -0.0000001)
		rx = (((int)px >> 6) << 6) - 0.0001; // gauche
	ry = py + (px - rx) * Tan;
	distV = ft_get_dist(rx, ry, mlx, x_var, y_var);
	// printf("disV is %f\n", distV);
	return (distV);
}

void	ft_set_flag(t_mlx *mlx, float *Tan)
{
	mlx->ray->Tan_slope = 1;
	mlx->ray->flag_cos = 1;
	mlx->ray->flag_sin = 1;
	// printf("%f\n", sin(ft_deg_to_rad(mlx->ray->ra)));
	// printf("%f\n", cos(ft_deg_to_rad(mlx->ray->ra)));
	// printf("%f\n", tan(ft_deg_to_rad(mlx->ray->ra)));
	if (cos(ft_deg_to_rad(mlx->ray->ra)) > 0.0000001) // de 0 a 90
		mlx->ray->flag_sin = -1;
	if (sin(ft_deg_to_rad(mlx->ray->ra)) < -0.0000001) // de 0 a 90
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

int	ft_cast_rays(t_mlx *mlx)
{
	int		i;
	float	disV;
	float	disH;
	float	Tan;
	float	ca;

	i = 0;
	// printf("%f \n", mlx->player->pa);
	mlx->ray->ra = ft_adjust_angle(mlx->player->pa + 30); // 0 + 30
	// mlx->ray->ra = ft_adjust_angle(mlx->player->pa + 0.5); // 0 + 30
	// mlx->ray->ra = 0.000026;//0 + 30//25 et 45
	// printf("ra is %f\n", mlx->ray->ra);
	while (i < SCREEN_WIDTH)
	{
		// printf("====================\n");
		// printf("current ra is %f\n", mlx->ray->ra);
		// usleep(10000);
		ft_set_flag(mlx, &Tan);
		// Calculate horizontal distance if not 0 or 180 degrees
		if (mlx->ray->ra != 0 && mlx->ray->ra != 180)
			disH = ft_calculate_distH(Tan, mlx);
		// Calculate vertical distance if not 90 or 270 degrees
		ft_set_flag(mlx, &Tan);
		if (mlx->ray->ra != 90 && mlx->ray->ra != 270)
			disV = ft_calculate_distV(Tan, mlx);
		else
			disV = disH + 1;
		// Special case for horizontal distance when ray is exactly 0 or 180 degrees
		if (mlx->ray->ra == 0 || mlx->ray->ra == 180)
			disH = disV + 1;
		//le probleme c est que sur l autre mur, il y a une egalite mais il print un HOR a la place d un VER!
		if (disH < disV)
		{
			// Set rx to the final horizontal distance
			mlx->ray->wall_distance = disH;
			mlx->ray->wall_touch = HORIZONTAL_WALL;
		}
		else if (disH > disV)
		{
			// printf("DIS V < DIS H %f\n", mlx->ray->ra);
			mlx->ray->wall_touch = VERTICAL_WALL;
		}
		else if (disH == disV)
		{
			if (mlx->ray->wall_touch == HORIZONTAL_WALL)
				mlx->ray->wall_touch = HORIZONTAL_WALL;
			else if (mlx->ray->wall_touch == VERTICAL_WALL)
				mlx->ray->wall_touch = VERTICAL_WALL;
		}
			mlx->ray->ry = disV;
			mlx->ray->rx = disH;
		// printf("disH is %f\n", disH);
		// printf("Dis is %f\n", disV);
		ca = ft_adjust_angle(mlx->player->pa - mlx->ray->ra);
		// printf("ca is %f\n", ca);
		disV = disV * cos(ft_deg_to_rad(ca));//on veut l angle adjacent
		// printf("Final Dis is %f\n", disV);
		mlx->ray->wall_distance = disV;
		ft_fill_colors(mlx, i);
		// printf("old ra is %f\n", mlx->ray->ra);
		mlx->ray->ra = ft_adjust_angle(mlx->ray->ra - ((float)60 / SCREEN_WIDTH));
		// printf("next ra is %f\n", mlx->ray->ra);
		i++;
	}
	// printf("------------------------------\n");
	// ft_fill_colors(mlx, i);
	return (0);
}

int	ft_main_loop(void *mlx_ptr)
{
	t_mlx	*mlx;
	t_image	img;

	mlx = mlx_ptr;
	mlx->img = &img;
	img.img = mlx_new_image(mlx->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!img.img)
	{
		// printf("Error: Failed to create image\n");
		return (1);
	}
	img.img_data = mlx_get_data_addr(img.img, &img.bpp, &img.line_length,
			&img.endian);
	if (!img.img_data)
	{
		// printf("Error: Failed to get image data address\n");
		mlx_destroy_image(mlx->mlx_ptr, img.img);
		return (1);
	}
	// printf("Setting new image\n");
	ft_set_player(mlx);
	ft_cast_rays(mlx);
	// printf("RAYS CASTED\n");
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img->img, 0, 0);
	// printf("New image added\n");
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
	ft_init_structs(&player, &mlx, &ray);
	printf("structs well initiated!\n");
	mlx.mlx_ptr = mlx_init();
	txtr_checkload(&mlx);
	ft_init_txtr_images(&mlx);
	if (!mlx.mlx_ptr)
		return (0);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT,
			"cube");
	// ft_main_loop(&mlx);
	mlx_hook(mlx.win_ptr, 2, 1L << 0, &key_press, &mlx);
	mlx_hook(mlx.win_ptr, 3, 1L << 1, &key_release, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, &ft_main_loop, &mlx);
	printf("Entering mlx_loop...\n");
	mlx_loop(mlx.mlx_ptr);
	ft_free_data(&data);
	return (0);
}
