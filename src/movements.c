
/* ************************************************************************** */
/* */
/* ::: :::::::: */
/* movement.c :+: :+: :+: */
/* +:+ +:+ +:+ */
/* By: roko <roko@student.42.fr> +#+ +:+ +#+ */
/* +#+#+#+#+#+ +#+ */
/* Created: 2024/12/01 14:52:32 by roko #+# #+# */
/* Updated: 2024/12/01 20:41:30 by roko ### ########.fr */
/* */
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
	pos_x = mlx->player->px + (move_x * 25);
	pos_y = mlx->player->py + (move_y * 25);
	if (mlx->data->tab[(int)pos_y / 64][(int)pos_x / 64] == '1')
		return (0);
	mlx->player->px = mlx->player->px + (move_x * 15);
	mlx->player->py = mlx->player->py + (move_y * 15);
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
	pos_x = mlx->player->px + (move_x * 25);
	pos_y = mlx->player->py + (move_y * 25);
	if (mlx->data->tab[(int)pos_y / 64][(int)pos_x / 64] == '1')
		return (0);
	mlx->player->px = mlx->player->px + (move_x * 15);
	mlx->player->py = mlx->player->py + (move_y * 15);
	return (0);
}

int	ft_set_player(t_mlx *mlx)
{
	float	pos_x;
	float	pos_y;
	int		flag;

	flag = 1;
	if (mlx->player->moving_back_forth == 1)
	{
		printf("px is %f\n", mlx->player->px);
		printf("py is %f\n", mlx->player->py);
		pos_x = mlx->player->px + (mlx->player->pdx * 45);
		pos_y = mlx->player->py + (mlx->player->pdy * 45);
		if (mlx->data->tab[(int)pos_y / 64][(int)pos_x / 64] == '1')
		{
			if (MV_VERT_RIGHT_UP && mlx->data->tab[((int)mlx->player->py - 10)
				/ 64][((int)mlx->player->px) / 64] != '1') // droite
				mlx->player->py = mlx->player->py - 10;
			else if (MV_VERT_RIGHT_DOWN && mlx->data->tab[((int)mlx->player->py
					+ 10) / 64][((int)mlx->player->px) / 64] != '1') // droite
				mlx->player->py = mlx->player->py + 10;
			else if (MV_VERT_LEFT_UP && mlx->data->tab[((int)mlx->player->py
					- 10) / 64][(int)mlx->player->px / 64] != '1') // droite
				mlx->player->py = mlx->player->py - 10;
			else if (MV_VERT_LEFT_DOWN && mlx->data->tab[((int)mlx->player->py
					+ 10) / 64][(int)mlx->player->px / 64] != '1') // droite
				mlx->player->py = mlx->player->py + 10;
			else if (MV_VERT_RIGHT_UP && mlx->data->tab[(int)mlx->player->py
				/ 64][((int)mlx->player->px + 10) / 64] != '1') // droite
				mlx->player->px = mlx->player->px + 10;
			else if (MV_VERT_RIGHT_DOWN && mlx->data->tab[(int)mlx->player->py
				/ 64][((int)mlx->player->px + 10) / 64] != '1') // droite
				mlx->player->px = mlx->player->px + 10;
			else if (MV_VERT_LEFT_UP && mlx->data->tab[(int)mlx->player->py
				/ 64][((int)mlx->player->px - 10) / 64] != '1')
				mlx->player->px = mlx->player->px - 10;
			else if (MV_VERT_LEFT_DOWN && mlx->data->tab[(int)mlx->player->py
				/ 64][((int)mlx->player->px - 10) / 64] != '1')
				mlx->player->px = mlx->player->px - 10;
			flag = -1;
		}
		if (flag == 1)
		{
			mlx->player->px = mlx->player->px + (mlx->player->pdx * 10);
			mlx->player->py = mlx->player->py + (mlx->player->pdy * 10);
		}
	}
	if (mlx->player->moving_back_forth == -1)
	{
		pos_x = mlx->player->px - (mlx->player->pdx * 25);
		pos_y = mlx->player->py - (mlx->player->pdy * 25);
		if (mlx->data->tab[(int)pos_y / 64][(int)pos_x / 64] == '1')
		{
			if (MV_VERT_RIGHT_UP && mlx->data->tab[((int)mlx->player->py)
				/ 64][((int)mlx->player->px - 10) / 64] != '1') // droite
				mlx->player->px = mlx->player->px - 10;
			// ok
			else if (MV_VERT_RIGHT_DOWN && mlx->data->tab[((int)mlx->player->py)
				/ 64][((int)mlx->player->px - 10) / 64] != '1') // droite
				mlx->player->px = mlx->player->px - 10;
			// ok
			else if (MV_VERT_LEFT_UP && mlx->data->tab[((int)mlx->player->py)
				/ 64][((int)mlx->player->px + 10) / 64] != '1') // droite
				mlx->player->px = mlx->player->px + 10;
			// ok
			else if (MV_VERT_LEFT_DOWN && mlx->data->tab[((int)mlx->player->py)
				/ 64][((int)mlx->player->px + 10) / 64] != '1') // droite
				mlx->player->px = mlx->player->px + 10;
			// ok
			else if (MV_VERT_RIGHT_UP && mlx->data->tab[((int)mlx->player->py
					+ 10) / 64][((int)mlx->player->px) / 64] != '1') // droite
				mlx->player->py = mlx->player->py + 10;
			// ok
			else if (MV_VERT_RIGHT_DOWN && mlx->data->tab[((int)mlx->player->py
					- 10) / 64][((int)mlx->player->px) / 64] != '1') // droite
				mlx->player->py = mlx->player->py - 10;
			// ok
			else if (MV_VERT_LEFT_UP && mlx->data->tab[((int)mlx->player->py
					+ 10) / 64][((int)mlx->player->px) / 64] != '1')
				mlx->player->py = mlx->player->py + 5;
			else if (MV_VERT_LEFT_DOWN && mlx->data->tab[((int)mlx->player->py
					- 10) / 64][((int)mlx->player->px) / 64] != '1')
				mlx->player->py = mlx->player->py - 10;
			flag = -1;
		}
		if (flag == 1)
		{
			mlx->player->px = mlx->player->px - (mlx->player->pdx * 10);
			mlx->player->py = mlx->player->py - (mlx->player->pdy * 10);
		}
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
