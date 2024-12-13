
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
void ft_forward_along_wall(t_mlx *mlx)
{
	if (MV_VERT_RIGHT_UP && mlx->data->tab[((int)mlx->player->py - 30)//1 cadrant
		/ 64][((int)mlx->player->px) / 64] != '1') // droite
		mlx->player->py = mlx->player->py - 10;
	else if (MV_VERT_RIGHT_DOWN && mlx->data->tab[((int)mlx->player->py//4 cad
			+ 30) / 64][((int)mlx->player->px) / 64] != '1') // droite
		mlx->player->py = mlx->player->py + 10;
	else if (MV_VERT_LEFT_UP && mlx->data->tab[((int)mlx->player->py
			- 30) / 64][(int)mlx->player->px / 64] != '1') // droite
		mlx->player->py = mlx->player->py - 10;
	else if (MV_VERT_LEFT_DOWN && mlx->data->tab[((int)mlx->player->py
			+ 30) / 64][(int)mlx->player->px / 64] != '1') // droite
		mlx->player->py = mlx->player->py + 10;
	else if (MV_VERT_RIGHT_UP && mlx->data->tab[(int)mlx->player->py//1 cadrant
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
}

void ft_backward_along_wall(t_mlx *mlx)
{
	if (MV_VERT_RIGHT_UP && mlx->data->tab[((int)mlx->player->py)
		/ 64][((int)mlx->player->px - 10) / 64] != '1') // droite
		mlx->player->px = mlx->player->px - 10;
	else if (MV_VERT_RIGHT_DOWN && mlx->data->tab[((int)mlx->player->py)
		/ 64][((int)mlx->player->px - 10) / 64] != '1') // droite
		mlx->player->px = mlx->player->px - 10;
	else if (MV_VERT_LEFT_UP && mlx->data->tab[((int)mlx->player->py)
		/ 64][((int)mlx->player->px + 10) / 64] != '1') // droite
		mlx->player->px = mlx->player->px + 10;
	else if (MV_VERT_LEFT_DOWN && mlx->data->tab[((int)mlx->player->py)
		/ 64][((int)mlx->player->px + 10) / 64] != '1') // droite
		mlx->player->px = mlx->player->px + 10;
	else if (MV_VERT_RIGHT_UP && mlx->data->tab[((int)mlx->player->py
			+ 30) / 64][((int)mlx->player->px) / 64] != '1') // droite
		mlx->player->py = mlx->player->py + 10;
	else if (MV_VERT_RIGHT_DOWN && mlx->data->tab[((int)mlx->player->py
			- 30) / 64][((int)mlx->player->px) / 64] != '1') // droite
		mlx->player->py = mlx->player->py - 10;
	else if (MV_VERT_LEFT_UP && mlx->data->tab[((int)mlx->player->py
			+ 30) / 64][((int)mlx->player->px) / 64] != '1')
		mlx->player->py = mlx->player->py + 5;
	else if (MV_VERT_LEFT_DOWN && mlx->data->tab[((int)mlx->player->py
			- 30) / 64][((int)mlx->player->px) / 64] != '1')
		mlx->player->py = mlx->player->py - 10;	
}

void ft_move_forward(t_mlx *mlx)
{
	float	pos_x;
	float	pos_y;
	int		flag;

	flag = 1;
	pos_x = mlx->player->px + (mlx->player->pdx * 50);
	pos_y = mlx->player->py + (mlx->player->pdy * 50);
	if (mlx->data->tab[(int)pos_y / 64][(int)pos_x / 64] == '1')
	{
		ft_forward_along_wall(mlx);
		flag = -1;
	}
	if (flag == 1)
	{
		mlx->player->px = mlx->player->px + (mlx->player->pdx * 10);
		mlx->player->py = mlx->player->py + (mlx->player->pdy * 10);
	}
}


