/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:48:25 by ks19              #+#    #+#             */
/*   Updated: 2024/12/17 00:15:12 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

void	ft_move_backward(t_mlx *mlx)
{
	float	pos_x;
	float	pos_y;
	int		flag;

	flag = 1;
	pos_x = mlx->player->px - (mlx->player->pdx * 24);
	pos_y = mlx->player->py - (mlx->player->pdy * 24);
	if (mlx->data->tab[(int)pos_y / 64][(int)pos_x / 64] == '1')
	{
		ft_backward_along_wall(mlx);
		flag = -1;
	}
	if (flag == 1)
	{
		mlx->player->px = mlx->player->px - (mlx->player->pdx * SPEED);
		mlx->player->py = mlx->player->py - (mlx->player->pdy * SPEED);
	}
}

void	ft_set_player(t_mlx *mlx)
{
	if (mlx->player->moving_back_forth == 1)
		ft_move_forward(mlx);
	if (mlx->player->moving_back_forth == -1)
		ft_move_backward(mlx);
	if (mlx->player->moving_left_right == -1)
		ft_oblique_left(mlx);
	if (mlx->player->moving_left_right == 1)
		ft_oblique_right(mlx);
	if (mlx->player->look_rot == -1)
	{
		mlx->player->pa = ft_adjust_angle(mlx->player->pa + ANGLE);
		mlx->player->pdx = cos(ft_deg_to_rad(mlx->player->pa));
		mlx->player->pdy = -sin(ft_deg_to_rad(mlx->player->pa));
	}
	if (mlx->player->look_rot == 1)
	{
		mlx->player->pa = ft_adjust_angle(mlx->player->pa - ANGLE);
		mlx->player->pdx = cos(ft_deg_to_rad(mlx->player->pa));
		mlx->player->pdy = -sin(ft_deg_to_rad(mlx->player->pa));
	}
}

int	key_press(int keycode, void *ml)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ml;
	if (keycode == KEY_ESCAPE)
		ft_close(mlx);
	else if (keycode == KEY_A)
		mlx->player->moving_left_right = -1;
	else if (keycode == KEY_D)
		mlx->player->moving_left_right = 1;
	else if (keycode == KEY_S)
		mlx->player->moving_back_forth = -1;
	else if (keycode == KEY_W)
		mlx->player->moving_back_forth = 1;
	else if (keycode == KEY_LEFT)
		mlx->player->look_rot = -1;
	else if (keycode == KEY_RIGHT)
		mlx->player->look_rot = 1;
	return (0);
}

int	key_release(int keycode, void *ml)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ml;
	if (keycode == KEY_A || keycode == KEY_D)
		mlx->player->moving_left_right = 0;
	else if (keycode == KEY_W || keycode == KEY_S)
		mlx->player->moving_back_forth = 0;
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		mlx->player->look_rot = 0;
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
