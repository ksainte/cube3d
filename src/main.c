
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

// void	ft_init_player(t_mlx *mlx)
// {
// 	mlx->player->player_fov_radians = FIELD_OF_VIEW * (PI / 180);
// 	// FORMULA : radians=degrees×(180π​)
// 	mlx->player->player_orientation_start = 'N';
// 	if (mlx->player->player_orientation_start == 'N')
// 		mlx->player->player_angle = (3 * PI) / 2; /// DEPEND DE LORIENTATION (N)
// 	mlx->player->player_y_px = mlx->data->s_y * TILE_S + TILE_S / 2;
// 	mlx->player->player_x_px = mlx->data->s_x * TILE_S + TILE_S / 2;
// 	printf("ok\n");
// }

void	ft_init_player(t_mlx *mlx)
{
	mlx->player->player_fov_radians = FIELD_OF_VIEW * (PI / 180);
	mlx->player->start_x = mlx->data->s_x;
	mlx->player->start_y = mlx->data->s_y;
	mlx->player->orientation_start = mlx->data->tab[mlx->player->py][mlx->player->px];
	printf("%c\n",mlx->player->orientation_start);
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
// int	ft_cast_rays(t_mlx *mlx)
// {
// 	float	hor_intersection;
// 	float	ver_intersection;
// 	int		i;

// 	i = 0;
// 	mlx->ray->ray_angle = mlx->player->player_angle - FIELD_OF_VIEW / 2;
// 	while (i < SCREEN_WIDTH)
// 	{
// 		mlx->ray->wall_touch = VERTICAL_WALL;
// 		hor_intersection = get_h_inter(mlx, mlx->ray->ray_angle);
// 		ver_intersection = get_v_inter(mlx, mlx->ray->ray_angle);
// 		if (ver_intersection <= hor_intersection)
// 			mlx->ray->wall_distance = ver_intersection;
// 		else
// 		{
// 			mlx->ray->wall_distance = hor_intersection;
// 			mlx->ray->wall_touch = HORIZONTAL_WALL;
// 		}
// 		// render_wall();
// 		i++;
// 		mlx->ray->ray_angle += mlx->player->player_fov_radians / SCREEN_WIDTH;
// 	}
// 	return (0);
// }


float ft_adjust_angle(int angle)
{
	if (angle < 0)
		angle = angle + 360;
	if (angle > 360)
		angle = angle - 360;
	return(angle);
}
float ft_deg_to_rad(float ray_angle)
{
	float ray_radian;

	ray_radian = ((ray_angle / 180 ) * PI);
	return (ray_radian); 
}

int	ft_cast_rays(t_mlx *mlx)
{
	int mx,my,mp, ray_counter, i, j, ray_coord, len_line, flag_cos, flag_sin;
	float px, py, vx,vy,rx,ry,ra,x_var,y_var,disV,disH, Tan;

	ray_counter = 1;
	ray_coord = 1;
	i = 0;
	ra = ft_adjust_angle(mlx->player->start_angle) + 30;//0 + 30
	px = mlx->player->start_x * TILE;
	py = mlx->player->start_y * TILE;
	flag_cos = 1;
	flag_sin = 1;
	//if o ou 360 deg, cos = 1, sin = 0, tan = 0, que distV
	//if 90 deg, cos = 0, sin = 1, tan = seg, que distH - 64
	//if 180 deg, cos = -1, sin = 0, tan = 0, que distV
	//if 270 deg, cos = 0, sin = -1, tan = seg, que distH + 64

	//if 0, 180 ou 360, que distV car tan == 0
	//if 90 ou 270, !tan et que distH
	
	while (i < ray_counter)
	{
		if (cos(ft_deg_to_rad(ra)) < 0)
			flag_cos = -1;
		if (sin(ft_deg_to_rad(ra)) > 0)//de 0 a 90
			flag_sin = -1;
		if (ra != 90 && ra != 270)//if 90 ou 270, que distH et tan == -1
			Tan = tan(ft_deg_to_rad(ra));
		else
			Tan = -1;
		// if (Tan == 0) ie si 0 ou 360 deg ou 180
			//skip HOR et set disH = distV + 1
		//horizontal
		y_var = 64;
		if (Tan != -1)
			x_var = y_var / Tan;
		else
			x_var = 0;
		if (sin(ft_deg_to_rad(ra)) > 0)//de 0 a 90
			ry=(((int)py >> 6) << 6) -0.0001;//arrondi a l unite inf
		if (sin(ft_deg_to_rad(ra)) < 0)//de 0 a 90
     		ry=(((int)py >> 6) << 6) + 64;      //arrondi a l unite sup
		rx = px + (py - ry) / Tan;
		j = 0;
		while (j < ray_coord)
		{
			mx = (int)rx / 64;
			my = (int)ry / 64;
			len_line = 0;
			if (my < mlx->data->row)
				len_line = ft_strlen(mlx->data->tab[my]);
			if (my < mlx->data->row && mx < len_line && mlx->data->tab[my][mx] == 1)
			{
				disH = (rx - px) / cos(ft_deg_to_rad(ra));
				break;
			}
			rx = rx + (flag_cos) * x_var;
			ry = ry + (flag_sin) * y_var;
			j++;
		}
		vx = rx;
		vy = ry;

		//vertical
		// if (Tan == -1) ie 90 ou 270
		//skip VER et set disV = distH + 1
		x_var = 64;
		y_var = x_var * Tan;
		if (cos(ft_deg_to_rad(ra)) > 0)//droite
			rx = (((int)px >> 6) << 6) + 64;
		if (cos(ft_deg_to_rad(ra)) < 0)
			rx = (((int)px >> 6) << 6) -0.0001;//gauche
		ry = py + (px - rx) * Tan;
		j = 0;
		while (j < ray_coord)
		{
			mx = (int)rx / 64;
			my = (int)ry / 64;
			len_line = 0;
			if (my < mlx->data->row)
				len_line = ft_strlen(mlx->data->tab[my]);
			if (my < mlx->data->row && mx < len_line && mlx->data->tab[my][mx] == 1)
			{
				disV = (rx - px) / cos(ft_deg_to_rad(ra));
				break;
			}
			rx = rx + (flag_cos) * x_var;
			ry = ry + (flag_sin) * y_var;
			j++;
		}
		if (disH < disV)
		{
			rx = vx;
			ry = vy;
			disV = disH;
		}
		ra = ft_adjust_angle(ra - 1);
		i++;
	}
	return (0);
}



int	ft_main_loop(void *mlx_ptr)
{
	t_mlx	*mlx;

	mlx = mlx_ptr;
	ft_cast_rays(mlx);
	// mlx->img = mlx_new_image(mlx->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	// // printf("Setting new image\n");
	// // ft_set_player();
	// mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
	// mlx_destroy_image(mlx->mlx_ptr, mlx->img);
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
	if ((!ft_parse_valid(&map) || !ft_map_playable(&map, &data)) && ft_free(&map))
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
	// mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT,
	// 		"cube");
	// mlx_loop_hook(mlx.mlx_ptr, ft_main_loop, &mlx);
	// printf("Entering mlx_loop...\n");
	// mlx_loop(mlx.mlx_ptr);
	ft_free_data(&data);
	return (0);
}
