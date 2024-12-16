/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:14:55 by ks19              #+#    #+#             */
/*   Updated: 2024/12/16 23:02:57 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

void	ft_init_player(t_mlx *mlx)
{
	int	y;
	int	x;

	mlx->player->player_fov_radians = FIELD_OF_VIEW * (PI / 180);
	mlx->player->start_x = mlx->data->s_x;
	mlx->player->start_y = mlx->data->s_y;
	mlx->player->px = mlx->player->start_x * TILE + 32;
	mlx->player->py = mlx->player->start_y * TILE + 32;
	y = mlx->player->start_y;
	x = mlx->player->start_x;
	mlx->player->o_start = mlx->data->tab[y][x];
	if (mlx->player->o_start == 'N')
		mlx->player->pa = 90;
	if (mlx->player->o_start == 'S')
		mlx->player->pa = 270;
	if (mlx->player->o_start == 'W')
		mlx->player->pa = 180;
	if (mlx->player->o_start == 'E')
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
	{
		ft_custom_error("*mlx failed to init or texture not rightly loaded!\n");
		return (0);
	}
	if (SCREEN_WIDTH > 2560 || SCREEN_HEIGHT > 1440)
	{
		ft_custom_error("Map size is exceeding screen size!\n");
		return(0);
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT,
			"cube");
	return (1);
}

int	ft_close(t_mlx *mlx)
{
	ft_free_data(mlx->data);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_player	player;
	t_mlx		mlx;
	t_map		map;
	t_ray		ray;

	map.path = ft_check_args(argc, argv[1]);
	if (!map.path)
		return (0);
	if ((!ft_parse_valid(&map) || !ft_map_playable(&map, &data)))
		return (ft_free(&map));
	mlx.data = &data;
	if (!ft_init_structs(&player, &mlx, &ray))
		return (ft_free_data(&data));
	mlx_hook(mlx.win_ptr, 2, 1L << 0, &key_press, &mlx);
	mlx_hook(mlx.win_ptr, 3, 1L << 1, &key_release, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, *ft_close, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, &ft_main_loop, &mlx);
	mlx_loop(mlx.mlx_ptr);
	ft_free_data(&data);
	return (0);
}
