
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
	mlx->player->player_y_px = mlx->data->player_y_map * TILE_S + TILE_S / 2;
	mlx->player->player_x_px = mlx->data->player_x_map * TILE_S + TILE_S / 2;
}
void	ft_init_data(t_mlx *mlx)
{
	mlx->data->player_x_map = 0;
	mlx->data->player_y_map = 0;
	mlx->data->map_w = 100;
	mlx->data->map_h = 100;
}
void	ft_init_structs(t_data *data, t_player *player, t_mlx *mlx, t_ray *ray)
{
	mlx->data = data;
	mlx->player = player;
	mlx->ray = ray;
	ft_init_data(mlx);
	ft_init_player(mlx);
}
int	ft_cast_rays(t_mlx *mlx)
{
	(void)mlx;
	return (0);
}
int	ft_main_loop(void *mlx_ptr)
{
	t_mlx	*mlx;

	mlx = mlx_ptr;
	mlx_destroy_image(mlx->mlx_ptr, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	// ft_set_player();
	ft_cast_rays(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
	return (0);
}
int	ft_launch_game(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
	{
		printf("MLX initialization failed!\n");
		return (1);
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT,
			"cube");
	if (mlx->win_ptr == NULL)
	{
		printf("Failed to create window!\n");
		return (1);
	}
	printf("Window opened!\n");
	// mlx_key_hook(mlx->win_ptr, ft_keys_handle, mlx);
	mlx_loop_hook(mlx->win_ptr, ft_main_loop, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data data;
	t_player player;
	t_mlx mlx;
	t_ray ray;

	char *path;
	(void)path;
	(void)argc;
	(void)argv;
	ft_fake_map(&data);
	ft_init_structs(&data, &player, &mlx, &ray);
	ft_launch_game(&mlx);
	return (1);
}