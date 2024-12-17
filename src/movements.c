/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:46:37 by ks19              #+#    #+#             */
/*   Updated: 2024/12/17 01:47:41 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

int	ft_oblique_left(t_mlx *mlx)
{
	float	move_x;
	float	move_y;
	float	pos_x;
	float	pos_y;

	move_x = cos(ft_deg_to_rad(ft_adjust_angle(mlx->player->pa + 90)));
	move_y = -sin(ft_deg_to_rad(ft_adjust_angle(mlx->player->pa + 90)));
	pos_x = mlx->player->px + (move_x * 24);
	pos_y = mlx->player->py + (move_y * 24);
	if (mlx->data->tab[(int)pos_y / 64][(int)pos_x / 64] == '1')
		return (0);
	mlx->player->px = mlx->player->px + (move_x * SPEED);
	mlx->player->py = mlx->player->py + (move_y * SPEED);
	return (0);
}

int	ft_oblique_right(t_mlx *mlx)
{
	float	move_x;
	float	move_y;
	float	pos_x;
	float	pos_y;

	move_x = cos(ft_deg_to_rad(ft_adjust_angle(mlx->player->pa - 90)));
	move_y = -sin(ft_deg_to_rad(ft_adjust_angle(mlx->player->pa - 90)));
	pos_x = mlx->player->px + (move_x * 24);
	pos_y = mlx->player->py + (move_y * 24);
	if (mlx->data->tab[(int)pos_y / 64][(int)pos_x / 64] == '1')
		return (0);
	mlx->player->px = mlx->player->px + (move_x * SPEED);
	mlx->player->py = mlx->player->py + (move_y * SPEED);
	return (0);
}

void	ft_forward_along_wall(t_mlx *mlx)
{
	if (mv_vert_right_up(mlx) && mlx->data->tab[((int)mlx->player->py - (SPEED
					+ 20)) / 64][((int)mlx->player->px) / 64] != '1')
		mlx->player->py = mlx->player->py - SPEED;
	else if (mv_vert_right_down(mlx) && mlx->data->tab[((int)mlx->player->py + (SPEED
					+ 20)) / 64][((int)mlx->player->px) / 64] != '1')
		mlx->player->py = mlx->player->py + SPEED;
	else if (mv_vert_left_up(mlx) && mlx->data->tab[((int)mlx->player->py - (SPEED
					+ 20)) / 64][(int)mlx->player->px / 64] != '1')
		mlx->player->py = mlx->player->py - SPEED;
	else if (mv_vert_left_down(mlx) && mlx->data->tab[((int)mlx->player->py + (SPEED
					+ 20)) / 64][(int)mlx->player->px / 64] != '1')
		mlx->player->py = mlx->player->py + SPEED;
	else if (mv_vert_right_up(mlx) && mlx->data->tab[(int)mlx->player->py
			/ 64][((int)mlx->player->px + SPEED) / 64] != '1')
		mlx->player->px = mlx->player->px + SPEED;
	else if (mv_vert_right_down(mlx) && mlx->data->tab[(int)mlx->player->py
			/ 64][((int)mlx->player->px + SPEED) / 64] != '1')
		mlx->player->px = mlx->player->px + SPEED;
	else if (mv_vert_left_up(mlx) && mlx->data->tab[(int)mlx->player->py
			/ 64][((int)mlx->player->px - SPEED) / 64] != '1')
		mlx->player->px = mlx->player->px - SPEED;
	else if (mv_vert_left_down(mlx) && mlx->data->tab[(int)mlx->player->py
			/ 64][((int)mlx->player->px - SPEED) / 64] != '1')
		mlx->player->px = mlx->player->px - SPEED;
}

void	ft_backward_along_wall(t_mlx *mlx)
{
	if (mv_vert_right_up(mlx) && mlx->data->tab[((int)mlx->player->py)
			/ 64][((int)mlx->player->px - SPEED) / 64] != '1')
		mlx->player->px = mlx->player->px - SPEED;
	else if (mv_vert_right_down(mlx) && mlx->data->tab[((int)mlx->player->py)
			/ 64][((int)mlx->player->px - SPEED) / 64] != '1')
		mlx->player->px = mlx->player->px - SPEED;
	else if (mv_vert_left_up(mlx) && mlx->data->tab[((int)mlx->player->py)
			/ 64][((int)mlx->player->px + SPEED) / 64] != '1')
		mlx->player->px = mlx->player->px + SPEED;
	else if (mv_vert_left_down(mlx) && mlx->data->tab[((int)mlx->player->py)
			/ 64][((int)mlx->player->px + SPEED) / 64] != '1')
		mlx->player->px = mlx->player->px + SPEED;
	else if (mv_vert_right_up(mlx) && mlx->data->tab[((int)mlx->player->py + (SPEED
					+ 20)) / 64][((int)mlx->player->px) / 64] != '1')
		mlx->player->py = mlx->player->py + SPEED;
	else if (mv_vert_right_down(mlx) && mlx->data->tab[((int)mlx->player->py - (SPEED
					+ 20)) / 64][((int)mlx->player->px) / 64] != '1')
		mlx->player->py = mlx->player->py - SPEED;
	else if (mv_vert_left_up(mlx) && mlx->data->tab[((int)mlx->player->py + (SPEED
					+ 20)) / 64][((int)mlx->player->px) / 64] != '1')
		mlx->player->py = mlx->player->py + SPEED;
	else if (mv_vert_left_down(mlx) && mlx->data->tab[((int)mlx->player->py - (SPEED
					+ 20)) / 64][((int)mlx->player->px) / 64] != '1')
		mlx->player->py = mlx->player->py - SPEED;
}

void	ft_move_forward(t_mlx *mlx)
{
	float	pos_x;
	float	pos_y;
	int		flag;

	flag = 1;
	pos_x = mlx->player->px + (mlx->player->pdx * 48);
	pos_y = mlx->player->py + (mlx->player->pdy * 48);
	if (mlx->data->tab[(int)pos_y / 64][(int)pos_x / 64] == '1')
	{
		ft_forward_along_wall(mlx);
		flag = -1;
	}
	if (flag == 1)
	{
		mlx->player->px = mlx->player->px + (mlx->player->pdx * SPEED);
		mlx->player->py = mlx->player->py + (mlx->player->pdy * SPEED);
	}
}
