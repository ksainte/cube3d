/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:52:32 by roko              #+#    #+#             */
/*   Updated: 2024/12/13 19:59:45 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

int	txtr_checkload(t_mlx *mlx)
{
	void	*texture;
	int		h;
	int		w;
	int		i;

	i = 0;
	w = 64;
	h = 64;
	if (mlx->mlx_ptr == NULL)
		return (0);
	while (i < 4)
	{
		if (mlx->data->txtr_tab[i].key != NULL)
		{
			texture = mlx_xpm_file_to_image(mlx->mlx_ptr,
					mlx->data->txtr_tab[i].path, &h, &w);
			if (texture == NULL)
				return (0);
			mlx_destroy_image(mlx->mlx_ptr, texture);
			texture = NULL;
		}
		i++;
	}
	return (1);
}

int	ft_init_txtr_images(t_mlx *mlx)
{
	int		i;
	int		h;
	int		w;
	t_txtr	*txtr;

	i = 0;
	w = 64;
	h = 64;
	while (i < 4)
	{
		txtr = &mlx->data->txtr_tab[i];
		txtr->img_data.img = mlx_xpm_file_to_image(mlx->mlx_ptr, txtr->path, &w,
				&h);
		if (txtr->img_data.img == NULL)
		{
			printf("Error loading texture %d\n", i);
			return (0);
		}
		txtr->img_data.img_data = mlx_get_data_addr(txtr->img_data.img,
				&txtr->img_data.pixel_bits, &txtr->img_data.size_line,
				&txtr->img_data.endian);
		i++;
	}
	printf("Textures initialized!\n");
	return (1);
}

int	ft_get_textr_color(t_mlx *mlx, int x_tex, int y_tex, int texture_i)
{
	int	color;
	int	pixel_index;
	int	tex_x;
	int	tex_y;

	tex_x = x_tex % 64;
	tex_y = y_tex % 64;
	pixel_index = tex_y * mlx->data->txtr_tab[texture_i].img_data.size_line
		+ tex_x * (mlx->data->txtr_tab[texture_i].img_data.pixel_bits / 8);
	color = *(unsigned int *)(mlx->data->txtr_tab[texture_i].img_data.img_data
			+ pixel_index);
	return (color);
}

int	ft_get_texture(t_mlx *mlx)
{
	int	i;

	i = 0;
	if (mlx->ray->wall_touch == VERTICAL_WALL)
	{
		if (mlx->ray->ra > 90 && mlx->ray->ra < 270)
			i = 2;
		else
			i = 1;
	}
	else
	{
		if (mlx->ray->ra > 0 && mlx->ray->ra < 180)
			i = 0;
		else
			i = 3;
	}
	return (i);
}
double	ft_get_x_pos(t_mlx *mlx)
{
	double	x_o;

	if (mlx->ray->wall_touch == HORIZONTAL_WALL)
		x_o = (int)fmodf(mlx->ray->rx, 64);
	else
		x_o = (int)fmodf(mlx->ray->ry, 64);
	return (x_o);
}
void	ft_draw_wall(t_mlx *mlx, double wall_height, int diff)
{
	double texture_step;
	double texture_pos;
	double tex_x;
	int y;
	int tex_y;
	int color;

	texture_step = (64 / wall_height);
	texture_pos = 0.0 + (diff * -1) * texture_step;
	tex_x = ft_get_x_pos(mlx);
	y = mlx->ray->wall_top;
	while (y < mlx->ray->wall_bottom)
	{
		tex_y = (int)texture_pos;
		color = ft_get_textr_color(mlx, tex_x, tex_y, ft_get_texture(mlx));
		ft_put_pixel_to_screen(mlx, mlx->ray->index, y, color);
		texture_pos += texture_step;
		y++;
	}
}