
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


// void	ft_init_data(t_mlx *mlx)
// {
// 	mlx->mlx_ptr = NULL;
// 	mlx->win_ptr = NULL;
// 	mlx->img = NULL;
// }
// void	ft_init_structs(t_player *player, t_mlx *mlx, t_ray *ray)
// {
// 	mlx->player = player;
// 	printf("init mlx->player ptr [ok]\n");
// 	mlx->ray = ray;
// 	printf("init mlx->ray ptr [ok]\n");
// 	ft_init_player(mlx);
// }
// float	get_v_inter(t_mlx *mlx, float angle)
// {
// 	(void)mlx;
// 	(void)angle;
// 	return (0);
// }
// float	get_h_inter(t_mlx *mlx, float angle)
// {
// 	(void)mlx;
// 	(void)angle;
// 	return (0);
// }
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

// int	ft_main_loop(void *mlx_ptr)
// {
// 	t_mlx	*mlx;

// 	mlx = mlx_ptr;
// 	// ft_cast_rays(mlx);
// 	mlx->img = mlx_new_image(mlx->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
// 	printf("Setting new image\n");
// 	// ft_set_player();
// 	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
// 	mlx_destroy_image(mlx->mlx_ptr, mlx->img);
// 	return (0);
// }

int	ft_close(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.reference_player);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.reference_walls);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.reference_bgd);
	exit(1);
}

void	ft_right(int x, int y, t_mlx *mlx)
{
	mlx->img_pos.x += 64;
	mlx_put_image_to_window(mlx, mlx->win_ptr,
		mlx->img.reference_bgd, mlx->img_pos.x,
		mlx->img_pos.y);
	ft_printf("Movement counter is -> %d\n");
}

void	ft_left(int x, int y, t_mlx *mlx)
{
	mlx->img_pos.x -= 64;
	mlx_put_image_to_window(mlx, mlx->win_ptr,
		mlx->img.reference_bgd, mlx->img_pos.x,
		mlx->img_pos.y);
	ft_printf("Movement counter is -> %d\n");
}

void	ft_down(int x, int y, t_mlx *mlx)
{
	mlx->img_pos.y += 64;
	mlx_put_image_to_window(mlx, mlx->win_ptr,
		mlx->img.reference_bgd, mlx->img_pos.x,
		mlx->img_pos.y);
	ft_printf("Movement counter is -> %d\n");
}

void	ft_up(int x, int y, t_mlx *mlx)
{
	mlx->img_pos.y -= 64;
	mlx_put_image_to_window(mlx, mlx->win_ptr,
		mlx->img.reference_bgd, mlx->img_pos.x,
		mlx->img_pos.y);
	ft_printf("Movement counter is -> %d\n");
}

void	ft_move(t_mlx *mlx, int key, int x, int y)
{
	if (key == 124 && mlx->data->tab[x][y + 1] != '1')
		ft_right(x, y, mlx);
	else if (key == 123 && mlx->data->tab[x][y - 1] != '1')
		ft_left(x, y, mlx);
	else if (key == 125 && mlx->data->tab[x + 1][y] != '1')
		ft_down(x, y, mlx);
	else if (key == 126 && mlx->data->tab[x - 1][y] != '1')
		ft_up(x, y, mlx);
	else if (key == 53)
		ft_close(mlx);
}

int	ft_input(int key, void *param)
{
	t_mlx	*mlx;
	int		x;
	int		y;

	mlx = (t_mlx *)param;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->img.reference_bgd, mlx->img_pos.x,
		mlx->img_pos.y);
	y = mlx->img_pos.x / 64;
	x = mlx->img_pos.y / 64;
	ft_move(mlx, key, x, y);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->img.reference_player, mlx->img_pos.x,
		mlx->img_pos.y);
	return (0);
}

void	ft_init_player(t_mlx *mlx)
{
	mlx->player->player_fov_radians = FIELD_OF_VIEW * (PI / 180);
	// FORMULA : radians=degrees×(180π​)
	mlx->player->player_orientation_start = 'N';
	if (mlx->player->player_orientation_start == 'N')
		mlx->player->player_angle = (3 * PI) / 2; /// DEPEND DE LORIENTATION (N)
	// mlx->player->player_y_px = mlx->data->s_y * TILE_S + TILE_S / 2;
	// mlx->player->player_x_px = mlx->data->s_x * TILE_S + TILE_S / 2;
	mlx->img_pos.x = mlx->data->s_x * 64;
	mlx->img_pos.y = mlx->data->s_y * 64;
	printf("ok\n");
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->img.reference_player, mlx->img_pos.x,
		mlx->img_pos.y);
	mlx_hook(mlx->win_ptr, 2, 0, *ft_input, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, *ft_close, mlx);
}

void	ft_paste_walls(t_mlx *mlx)
{
	int	x;
	int	y;
	int i;
	int j;

	x = 0;
	y = 0;
	j = 0;
	while (j < mlx->data->row)
	{
		i = 0;
		while (mlx->data->tab[j][i])
		{
			if (mlx->data->tab[j][i] == '1')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->img.reference_walls, x, y);
			}
			x += 64;
			i++;
		}
		y += 64;
		x = 0;
		j++;
	}
}

void	ft_paste_bgd(t_mlx *mlx)
{
	int	x;
	int	y;
	int i;
	int j;

	x = 0;
	y = 0;
	j = 0;
	while (j < mlx->data->row)
	{
		i = 0;
		while (mlx->data->tab[j][i])
		{
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
				mlx->img.reference_bgd, x, y);
			x += 64;
			i++;
		}
		y += 64;
		x = 0;
		j++;
	}
}

void	ft_init_textures_pointers(t_mlx *mlx)
{

	mlx->img.reference_walls = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/wall_1.xpm", &mlx->isize[0], &mlx->isize[1]);
	mlx->img.reference_player = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/wall_2.xpm", &mlx->isize[0], &mlx->isize[1]);
	mlx->img.reference_bgd = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./textures/wall_3.xpm", &mlx->isize[0], &mlx->isize[1]);
}


void	ft_init_window(t_player *player, t_mlx *mlx, t_ray *ray)
{
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	printf("initializing structs\n");
	mlx->player = player;
	mlx->ray = ray;
	// ft_init_player(mlx);
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return ;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 8 * 64, mlx->data->row * 64,
			"cube3d");
	ft_init_textures_pointers(mlx);
	ft_paste_walls(mlx);
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
	mlx.data = &data;
	ft_init_window(&player, &mlx, &ray);
	ft_init_player(&mlx);
	// ft_init_structs(&player, &mlx, &ray);
	// printf("init struct done\n");
	// mlx.mlx_ptr = mlx_init();
	// if (!mlx.mlx_ptr)
	// 	return (0);
	// mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT,
	// 		"cube");
	// mlx_loop_hook(mlx.mlx_ptr, ft_main_loop, &mlx);
	printf("Entering mlx_loop...\n");
	mlx_loop(mlx.mlx_ptr);
	ft_free_data(&data);
	
	return (0);
}
