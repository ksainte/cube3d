
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
	// FORMULA : radians=degrees×(180π​)
	mlx->player->player_orientation_start = 'N';
	if (mlx->player->player_orientation_start == 'N')
		mlx->player->player_angle = (3 * PI) / 2; /// DEPEND DE LORIENTATION (N)
	mlx->player->player_y_px = mlx->data->s_y * TILE_S + TILE_S / 2;
	mlx->player->player_x_px = mlx->data->s_x * TILE_S + TILE_S / 2;
	printf("ok\n");
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
int	ft_cast_rays(t_mlx *mlx)
{
	float	hor_intersection;
	float	ver_intersection;
	int		i;

	i = 0;
	mlx->ray->ray_angle = mlx->player->player_angle - FIELD_OF_VIEW / 2;
	while (i < SCREEN_WIDTH)
	{
		mlx->ray->wall_touch = VERTICAL_WALL;
		hor_intersection = get_h_inter(mlx, mlx->ray->ray_angle);
		ver_intersection = get_v_inter(mlx, mlx->ray->ray_angle);
		if (ver_intersection <= hor_intersection)
			mlx->ray->wall_distance = ver_intersection;
		else
		{
			mlx->ray->wall_distance = hor_intersection;
			mlx->ray->wall_touch = HORIZONTAL_WALL;
		}
		// render_wall();
		i++;
		mlx->ray->ray_angle += mlx->player->player_fov_radians / SCREEN_WIDTH;
	}
	return (0);
}
int	ft_main_loop(void *mlx_ptr)
{
	t_mlx	*mlx;

	mlx = mlx_ptr;
	if (mlx->img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	printf("Setting new image\n");
	if (!mlx->img)
		printf("no image");
	// ft_set_player();
	ft_cast_rays(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
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
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT,
			"cube");
	mlx_loop_hook(mlx.mlx_ptr, ft_main_loop, &mlx);
	printf("Entering mlx_loop...\n");
	mlx_loop(mlx.mlx_ptr);
	ft_free_data(&data);
	return (0);
}
