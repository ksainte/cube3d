
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
	mlx->player->px = mlx->player->start_x * TILE;
	mlx->player->py = mlx->player->start_y * TILE;
	mlx->ray->flag_cos = 1;
	mlx->ray->flag_sin = 1;
	mlx->player->orientation_start = mlx->data->tab[mlx->player->start_y][mlx->player->start_x];
	printf("letter is %c\n",mlx->player->orientation_start);
	if (mlx->player->orientation_start == 'N')
		mlx->player->pa = 90;
	if (mlx->player->orientation_start == 'S')
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

float ft_get_dist(float rx, float ry, t_mlx *mlx, float x_var, float y_var)
{
	int j;
	int mx;
	int my;
	int len_line;
	float dis;

	j = 0;
	mlx->ray->ray_coord = 5;
	while (j < mlx->ray->ray_coord)
	{
		mx = (int)rx / 64;
		my = (int)ry / 64;
		len_line = 0;
		if (my > -1 && my < mlx->data->row)
			len_line = ft_strlen(mlx->data->tab[my]);
		if ((my > -1 && my < mlx->data->row) && (mx > -1 && mx < len_line) && mlx->data->tab[my][mx] == '1')
			break;
		rx = rx + (mlx->ray->flag_cos) * x_var;
		ry = ry + (mlx->ray->flag_sin) * y_var;
		j++;
	}
	dis = (rx - mlx->player->px) / cos(ft_deg_to_rad(mlx->ray->ra));
	return (dis);
}

int ft_calculate_distH(float Tan, t_mlx *mlx)
{
	float x_var;
	float y_var;
	float ry;
	float rx;
	float px;
	float py;
	float distH;

	px = mlx->player->px;
	py = mlx->player->py;
	y_var = 64;
	if (Tan != -2)
		x_var = y_var / Tan;
	else
		x_var = 0;
	if (sin(ft_deg_to_rad(mlx->ray->ra)) > 0)//de 0 a 90
		ry=(((int)py >> 6) << 6) -0.0001;//arrondi a l unite inf
	else if (sin(ft_deg_to_rad(mlx->ray->ra)) < 0)//de 0 a 90
		ry=(((int)py >> 6) << 6) + 64;      //arrondi a l unite sup
	rx = px + (py - ry) / Tan;
	printf("rx is %f\n", rx);
	distH = ft_get_dist(rx, ry, mlx, x_var, y_var);
	printf("disH is %f\n", distH);
	return (distH);
}

int ft_calculate_distV(float Tan, t_mlx *mlx)
{
	float x_var;
	float y_var;
	float px;
	float py;
	float ry;
	float rx;
	float distV;

	px = mlx->player->px;
	py = mlx->player->py;
	x_var = 64;
	y_var = x_var * Tan;
	if (cos(ft_deg_to_rad(mlx->ray->ra)) > 0)//droite
		rx = (((int)px >> 6) << 6) + 64;
	else if (cos(ft_deg_to_rad(mlx->ray->ra)) < 0)
		rx = (((int)px >> 6) << 6) -0.0001;//gauche
	ry = py + (px - rx) * Tan;
	distV = ft_get_dist(rx, ry, mlx, x_var, y_var);
	printf("disV is %f\n", distV);
	return (distV);
}

void ft_set_flag(t_mlx *mlx, float *Tan)
{
	if (cos(ft_deg_to_rad(mlx->ray->ra)) < 0)
		mlx->ray->flag_cos = -1;
	if (sin(ft_deg_to_rad(mlx->ray->ra)) > 0)//de 0 a 90
		mlx->ray->flag_sin = -1;
	if (mlx->ray->ra != 90 && mlx->ray->ra != 270)//if 90 ou 270, que distH et tan == -1
		*Tan = tan(ft_deg_to_rad(mlx->ray->ra));
	else
		*Tan = -2;
}

int	ft_cast_rays(t_mlx *mlx)
{
	int i; 
	float disV; 
	float disH; 
	float Tan;

	i = 0;
	printf("%f \n", mlx->player->pa);
	// mlx->ray->ra = ft_adjust_angle(mlx->player->pa) + 30;//0 + 30
	mlx->ray->ra = 90;//0 + 30
	printf("ra is %f\n", mlx->ray->ra);
	while (i < 1)
	{
		ft_set_flag(mlx, &Tan);
		printf("cos %d\n", mlx->ray->flag_cos);
		printf("sin is %d\n", mlx->ray->flag_sin);
		printf("Tan is %f\n", Tan);
		if (Tan != 0)//ie si ! 0 ou 180 deg
			disH = ft_calculate_distH(Tan, mlx);
		if (Tan != -2)//ie si ! 90 ou 270 deg
			disV = ft_calculate_distV(Tan, mlx);
		else
			disV = disH + 1;
		if (Tan == 0)
			disH = disV + 1;
		if (disH < disV)
			disV = disH;//final dis is disV
		printf("Final Dis is %f\n",disV);
		mlx->ray->ra = ft_adjust_angle(mlx->ray->ra - 1);
		i++;
	}
	return (0);
}

int	ft_main_loop(void *mlx_ptr)
{
	t_mlx	*mlx;

	mlx = mlx_ptr;
	printf("%f \n", mlx->player->pa);
	// ft_cast_rays(mlx);
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
	// ft_print_data(&data);
	printf("initializing structs\n");
	mlx.data = &data;
	ft_init_structs(&player, &mlx, &ray);
	printf("init struct done\n");
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		return (0);
	ft_cast_rays(&mlx);
	// ft_main_loop(mlx.mlx_ptr);
	// mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT,
	// 		"cube");
	// mlx_loop_hook(mlx.mlx_ptr, ft_main_loop, &mlx);
	// printf("Entering mlx_loop...\n");
	// mlx_loop(mlx.mlx_ptr);
	ft_free_data(&data);
	return (0);
}
