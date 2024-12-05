
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roko <roko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:52:32 by roko              #+#    #+#             */
/*   Updated: 2024/12/01 20:41:30 by roko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

int	ft_rot_player(t_mlx *mlx, int direction)
{
	if (direction == 1)
	{
		mlx->player->pa += ROT_SPEED;
		if (mlx->player->pa > 360)
			mlx->player->pa -= 360;
	}
	else if (direction == 0)
	{
		mlx->player->pa -= ROT_SPEED;
		if (mlx->player->pa < 0)
			mlx->player->pa += 360;
	}
	return (0);
}
int	ft_move_player(void)
{
	return (0);
}
int	ft_adjust_values_move(void)
{
	return (0);
}
int	ft_set_player(t_mlx *mlx)
{
	double	move_x;
	double	move_y;

	move_x = 0;
	move_y = 0;
	if (mlx->player->moving_back_forth == 1)
	{
	}
	if (mlx->player->moving_back_forth == -1)
	{
	}
	if (mlx->player->moving_left_right == 1)
	{
	}
	if (mlx->player->moving_left_right == -1)
	{
	}
	if (mlx->player->look_rot == -1)
		ft_rot_player(mlx, 0);
	if (mlx->player->look_rot == 1)
		ft_rot_player(mlx, 0);
	return (0);
}
int	key_press(int keycode, void *ml)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ml;
	if (keycode == KEY_ESCAPE)
		exit(0);
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
	// ft_move_player(mlx, keycode);
	return (0);
}
int	key_release(int keycode, void *ml)
{
	t_mlx *mlx;

	mlx = (t_mlx *)ml;
	if (keycode == KEY_A || keycode == KEY_D)
		mlx->player->moving_left_right = 0;
	else if (keycode == KEY_W || keycode == KEY_S)
		mlx->player->moving_back_forth = 0;
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		mlx->player->look_rot = 0;
	return (0);
}