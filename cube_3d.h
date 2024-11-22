/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:37:29 by ksainte           #+#    #+#             */
/*   Updated: 2024/11/21 16:54:31 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_3D_H
# define CUBE_3D_H

# include "./Libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define SCREEN_WIDTH 600
# define SCREEN_HEIGHT 600
# define TILE_S 100
# define FIELD_OF_VIEW 60
# define ROTATION_S
# define PLAYER_S
# define PI 3.14159265358979323846
# define VERTICAL_WALL 0
# define HORIZONTAL_WALL 1
typedef struct s_data
{
	int			fd;
	char		*line;
	int			row;
	char		**map;
	int			map_w;
	int			map_h;
	int			player_x_map;
	int			player_y_map;
}				t_data;
typedef struct s_player
{
	int			player_x_px;
	int			player_y_px;
	char		player_orientation_start;
	double		player_angle;
	float		player_fov_radians;
}				t_player;
typedef struct s_ray
{
	double		ray_angle;
	double		wall_distance;
	int			wall_touch;
}				t_ray;
typedef struct s_mlx
{
	t_data		*data;
	t_player	*player;
	void		*mlx_ptr;
	t_ray		*ray;
	void		*win_ptr;
	void		*img;
}				t_mlx;
void			ft_fake_map(t_data *map);
#endif