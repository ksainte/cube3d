
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
	printf("Wall color : %d \n", color);
	// retourne le 0x du wall celon son orientation
	// WALL
	j = wall_top_px;
	while (j < wall_bot_px)
	{
		// apllique la couleur au bon pixel en question
		ft_put_pixel_to_screen(mlx, ray_num, j, color);
		j++;
	}
	printf("Wall print done\n");
	// FLOOR
	i = wall_bot_px;
	while (i < SCREEN_HEIGHT)
	{
		ft_put_pixel_to_screen(mlx, ray_num, i, 0xFF6347FF);
		i++;
	}
	printf("Floor done\n");
	// CEILING
	i = 0;
	while (i < wall_top_px)
	{
		ft_put_pixel_to_screen(mlx, ray_num, i, 0x0000FF00);
		i++;
	}
	printf("Ceiling done \n");
	return (0);
}
int	ft_put_wall(t_mlx *mlx, int ray_num)
{
	double	wall_height;
	double	bottom_px;
	double	top_px;

	printf("put_wall_dist = %f\n", mlx->ray->wall_distance);
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

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

void	ft_init_player(t_mlx *mlx)
{
	mlx->player->player_fov_radians = FIELD_OF_VIEW * (PI / 180);
	mlx->player->start_x = mlx->data->s_x;
	mlx->player->start_y = mlx->data->s_y;
	mlx->player->px = mlx->player->start_x * TILE;
	mlx->player->py = mlx->player->start_y * TILE;
	printf("px is %f\n", mlx->player->px);
	printf("py is %f\n", mlx->player->py);
	mlx->player->orientation_start = mlx->data->tab[mlx->player->start_y][mlx->player->start_x];
	printf("letter is %c\n", mlx->player->orientation_start);
	if (mlx->player->orientation_start == 'S')
		mlx->player->pa = 90;
	if (mlx->player->orientation_start == 'N')
		mlx->player->pa = 270;
	if (mlx->player->orientation_start == 'E')
		mlx->player->pa = 0;
	if (mlx->player->orientation_start == 'W')
		mlx->player->pa = 180;
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

float	ft_adjust_angle(float angle)
{
	if (angle < 0)
		angle = angle + 360;
	if (angle > 359)
		angle = angle - 360;
	return (angle);
}
float	ft_deg_to_rad(float ray_angle)
{
	float	ray_radian;

	ray_radian = ((ray_angle / 180) * PI);
	return (ray_radian);
}

// void Buttons(unsigned char key,int x,int y)
// {
// 	if(key=='a')
// 	{
// 		mlx->player->pa = ft_adjust_angle(mlx->player->pa + 5);
// 		printf("pa is %f\n", mlx->player->pa);
// 		mlx->player->pdx = cos(ft_deg_to_rad(mlx->player->pa));
// 		printf("pdx is %f\n", mlx->player->pdx);
// 		printf("px is %f\n", mlx->player->px);
// 		mlx->player->pdy = -sin(ft_deg_to_rad(mlx->player->pa));
// 		printf("pdy is %f\n", mlx->player->pdy);
// 		printf("py is %f\n", mlx->player->py);
// 		printf("==============\n");
// 	}
// 	if(key=='d')
// 	{
// 		mlx->player->pa = ft_adjust_angle(mlx->player->pa - 5);
// 		printf("pa is %f\n", mlx->player->pa);
// 		mlx->player->pdx = cos(ft_deg_to_rad(mlx->player->pa));
// 		printf("pdx is %f\n", mlx->player->pdx);
// 		printf("px is %f\n", mlx->player->px);
// 		mlx->player->pdy = -sin(ft_deg_to_rad(mlx->player->pa));
// 		printf("pdy is %f\n", mlx->player->pdy);
// 		printf("py is %f\n", mlx->player->py);
// 		printf("==============\n");
// 	}
// 	if(key=='w')
// 	{
// 		printf("pdx is %f\n", mlx->player->pdx);
// 		mlx->player->px = mlx->player->px + (mlx->player->pdx * 5);
// 		printf("px is %f\n", mlx->player->px);
// 		printf("pdy is %f\n", mlx->player->pdy);
// 		mlx->player->py = mlx->player->py + (mlx->player->pdy * 5);
// 		printf("py is %f\n", mlx->player->py);
// 		printf("==============\n");
// 	}
// 	if(key=='s')
// 	{
// 		printf("pdx is %f\n", mlx->player->pdx);
// 		mlx->player->px = mlx->player->px - (mlx->player->pdx * 5);
// 		printf("px is %f\n", mlx->player->px);
// 		printf("pdy is %f\n", mlx->player->pdy);
// 		mlx->player->py = mlx->player->py - (mlx->player->pdy * 5);
// 		printf("py is %f\n", mlx->player->py);
// 		printf("==============\n");
// 	}
// }

float	ft_get_dist(float rx, float ry, t_mlx *mlx, float x_var, float y_var)
{
	int		j;
	int		mx;
	int		my;
	int		len_line;
	float	dis;

	j = 0;
	mlx->ray->ray_coord = 10;
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
	printf("final rx is %f\n", rx);
	printf("final ry is %f\n", ry);
	if (mlx->ray->ra == 90 || mlx->ray->ra == 270)
		dis = (ry - mlx->player->py) * mlx->ray->flag_sin;
	else
		dis = (rx - mlx->player->px) / cos(ft_deg_to_rad(mlx->ray->ra));
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
	printf("DistH: \n");
	printf("flag_sin is %d\n", mlx->ray->flag_sin);
	printf("Tan_slope is %d\n", mlx->ray->Tan_slope);
	mlx->ray->flag_sin = mlx->ray->flag_sin * mlx->ray->Tan_slope;
	printf("final flag_sin is %d\n", mlx->ray->flag_sin);
	printf("final flag_cos is %d\n", mlx->ray->flag_cos);
	if (mlx->ray->ra != 90 && mlx->ray->ra != 270)
		x_var = y_var / Tan;
	else
		x_var = 0;
	if (sin(ft_deg_to_rad(mlx->ray->ra)) > 0.001)       // de 0 a 180
		ry = (((int)py >> 6) << 6) - 0.0001;            // arrondi a l unite inf
	else if (sin(ft_deg_to_rad(mlx->ray->ra)) < -0.001) // de 180 a 360
		ry = (((int)py >> 6) << 6) + 64;                // arrondi a l unite sup
	if (mlx->ray->ra == 90 || mlx->ray->ra == 270)
		rx = px;
	else
		rx = px + (py - ry) / Tan;
	distH = ft_get_dist(rx, ry, mlx, x_var, y_var);
	printf("disH is %f\n", distH);
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
	printf("DistV: \n");
	printf("flag_cos is %d\n", mlx->ray->flag_cos);
	printf("Tan_slope is %d\n", mlx->ray->Tan_slope);
	mlx->ray->flag_cos = mlx->ray->flag_cos * mlx->ray->Tan_slope;
	printf("final flag_cos is %d\n", mlx->ray->flag_cos);
	printf("final flag_sin is %d\n", mlx->ray->flag_sin);
	y_var = x_var * Tan;
	if (cos(ft_deg_to_rad(mlx->ray->ra)) > 0.001) // droite
		rx = (((int)px >> 6) << 6) + 64;
	else if (cos(ft_deg_to_rad(mlx->ray->ra)) < -0.001)
		rx = (((int)px >> 6) << 6) - 0.0001; // gauche
	ry = py + (px - rx) * Tan;
	distV = ft_get_dist(rx, ry, mlx, x_var, y_var);
	printf("disV is %f\n", distV);
	return (distV);
}

void	ft_set_flag(t_mlx *mlx, float *Tan)
{
	mlx->ray->Tan_slope = 1;
	mlx->ray->flag_cos = 1;
	mlx->ray->flag_sin = 1;
	if (cos(ft_deg_to_rad(mlx->ray->ra)) > 0.001) // de 0 a 90
		mlx->ray->flag_sin = -1;
	if (sin(ft_deg_to_rad(mlx->ray->ra)) < -0.001) // de 0 a 90
		mlx->ray->flag_cos = -1;
	if (mlx->ray->ra != 90 && mlx->ray->ra != 270)
	{
		*Tan = tan(ft_deg_to_rad(mlx->ray->ra));
		if (*Tan < 0)
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

	i = 0;
	printf("%f \n", mlx->player->pa);
	// mlx->ray->ra = ft_adjust_angle(mlx->player->pa + 30); // 0 + 30
	mlx->ray->ra = ft_adjust_angle(mlx->player->pa - 30); // 0 + 30
	// mlx->ray->ra = 90;//0 + 30//25 et 45
	printf("ra is %f\n", mlx->ray->ra);
	while (i < 600)
	{
		printf("====================\n");
		printf("current ra is %f\n", mlx->ray->ra);
		ft_set_flag(mlx, &Tan);
		printf("Tan is %f\n", Tan);
		if (mlx->ray->ra != 0 && mlx->ray->ra != 180) // ie si ! 0 ou 180 deg
			disH = ft_calculate_distH(Tan, mlx);
		ft_set_flag(mlx, &Tan);
		if (mlx->ray->ra != 90 && mlx->ray->ra != 270) // ie si ! 90 ou 270 deg
			disV = ft_calculate_distV(Tan, mlx);
		else
			disV = disH + 1;
		if (mlx->ray->ra == 0 || mlx->ray->ra == 180)
			disH = disV + 1;
		mlx->ray->wall_touch = HORIZONTAL_WALL;
		if (disH < disV)
		{
			disV = disH;
			mlx->ray->wall_touch = VERTICAL_WALL; // final dis is disV
		}
		printf("disH is %f\n", disH);
		printf("Final Dis is %f\n", disV);
		float ca= ft_adjust_angle(mlx->player->pa - mlx->ray->ra); 
  		disV = disV * cos(ft_deg_to_rad(ca));
		mlx->ray->wall_distance = disV;
		ft_put_wall(mlx, i);
		// printf("test is %f\n", (60 / SCREEN_WIDTH));
		// mlx->ray->ra += (60 / SCREEN_WIDTH);
		mlx->ray->ra = ft_adjust_angle(mlx->ray->ra + 0.1);
		printf("next ra is %f\n", mlx->ray->ra);
		i++;
	}
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
		printf("Error: Failed to create image\n");
		return (1);
	}
	img.img_data = mlx_get_data_addr(img.img, &img.bpp, &img.line_length,
			&img.endian);
	if (!img.img_data)
	{
		printf("Error: Failed to get image data address\n");
		mlx_destroy_image(mlx->mlx_ptr, img.img);
		return (1);
	}
	printf("Setting new image\n");
	// ft_set_player(mlx);
	ft_cast_rays(mlx);
	printf("RAYS CASTED\n");
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img->img, 0, 0);
	printf("New image added\n");
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
	// ft_print_data(&data);
	printf("initializing structs\n");
	mlx.data = &data;
	ft_init_structs(&player, &mlx, &ray);
	printf("init struct done\n");
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		return (0);
	printf("mlx initiated \n");
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT,
			"cube");
	printf("Window created\n");
	// ft_cast_rays(&mlx);
	// ft_main_loop(&mlx);
	// mlx_hook(mlx.win_ptr, 2, 1L << 0, &key_press, &mlx);
	// mlx_hook(mlx.win_ptr, 3, 1L << 1, &key_release, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, &ft_main_loop, &mlx);
	printf("Entering mlx_loop...\n");
	mlx_loop(mlx.mlx_ptr);
	ft_free_data(&data);
	return (0);
}
