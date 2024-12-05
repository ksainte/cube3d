
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


int ft_oblique_left(t_mlx *mlx)
{
	float	move_x;
	float	move_y;

	move_x = cos(ft_deg_to_rad(ft_adjust_angle(mlx->player->pa + 90)));
	move_y = -sin(ft_deg_to_rad(ft_adjust_angle(mlx->player->pa + 90)));
	mlx->player->px = mlx->player->px + (move_x * 5);
	mlx->player->py = mlx->player->py + (move_y * 5);
	return (0);
}

int ft_oblique_right(t_mlx *mlx)
{
	float	move_x;
	float	move_y;

	move_x = cos(ft_deg_to_rad(ft_adjust_angle(mlx->player->pa - 90)));
	move_y = -sin(ft_deg_to_rad(ft_adjust_angle(mlx->player->pa - 90)));
	mlx->player->px = mlx->player->px + (move_x * 5);
	mlx->player->py = mlx->player->py + (move_y * 5);
	return (0);
}

int	ft_set_player(t_mlx *mlx)
{

	if (mlx->player->moving_back_forth == 1)
	{
		mlx->player->px = mlx->player->px + (mlx->player->pdx * 5);
		mlx->player->py = mlx->player->py + (mlx->player->pdy * 5);
	}
	if (mlx->player->moving_back_forth == -1)
	{
		mlx->player->px = mlx->player->px - (mlx->player->pdx * 5);
		mlx->player->py = mlx->player->py - (mlx->player->pdy * 5);
	}
	if (mlx->player->moving_left_right == -1)
		ft_oblique_left(mlx);
	if (mlx->player->moving_left_right == 1)
		ft_oblique_right(mlx);
	if (mlx->player->look_rot == -1)
	{
		mlx->player->pa = ft_adjust_angle(mlx->player->pa + 5);
		mlx->player->pdx = cos(ft_deg_to_rad(mlx->player->pa));
		mlx->player->pdy = -sin(ft_deg_to_rad(mlx->player->pa));
	}
	if (mlx->player->look_rot == 1)
	{
		mlx->player->pa = ft_adjust_angle(mlx->player->pa - 5);
		mlx->player->pdx = cos(ft_deg_to_rad(mlx->player->pa));
		mlx->player->pdy = -sin(ft_deg_to_rad(mlx->player->pa));
	}
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