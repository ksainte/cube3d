#ifndef CUBE_3D_H
# define CUBE_3D_H

# include "./Libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define SCREEN_WIDTH 1200
# define SCREEN_HEIGHT 1200
# define TILE 64
# define FIELD_OF_VIEW 60
# define ROTATION_S
# define PLAYER_S
# define PI 3.14159265358979323846
# define PI_90 1.57079632679
// # define PI_270
# define VERTICAL_WALL 0
# define HORIZONTAL_WALL 1
// KEYS
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESCAPE 65307
// SPEEDS
# define ROT_SPEED 0.05
# define MOVE_SPEED 4

typedef struct s_map
{
	int			fd;
	int			index;
	int			s_x;
	int			s_y;
	char		*line;
	int			row;
	char		*path;
	char		**tab;
	char		**tmp;
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	int			F[3];
	int			C[3];

}				t_map;

typedef struct s_data
{
	char		**tab;
	int			s_x;
	int			s_y;
	int			row;
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	int			F[3];
	int			C[3];

}				t_data;

typedef struct s_image
{
	void		*img;
	char		*img_data;
	int			bpp;
	int			line_length;
	int			endian;
}				t_image;
typedef struct s_player
{
	int start_x; // start x pos
	int start_y; // start y pos
	float		px;
	float		py;
	float		pdx;
	float		pdy;
	char		orientation_start;
	float		pa;
	float		player_fov_radians;
	int			moving_left_right;
	int			moving_back_forth;
	int			look_rot;
}				t_player;
typedef struct s_ray
{
	double		wall_distance;
	int			wall_touch;
	float		ra;
	float		rx;
	float		ry;
	float		wrx;
	float		wry;
	int			flag_cos;
	int			flag_sin;
	int			ray_coord;
	int			Tan_slope;
}				t_ray;
typedef struct s_mlx
{
	t_data		*data;
	t_player	*player;
	void		*mlx_ptr;
	t_ray		*ray;
	void		*win_ptr;
	t_image		*img;
}				t_mlx;

void			ft_system_error(void);
char			*ft_custom_error(char *str);
int				ft_free(t_map *map);
int				ft_free_line(t_map *map);
int				ft_map_error(int error);
int				ft_valid_number_range(char *str, int range);
int				ft_check_until_comma_or_null(char *str);
int				ft_valid_characters(char *str, int range, int *len, int *rgb);
int				ft_valid_color_range(char *str, int *rgb);
int				ft_valid_color(char *str);
int				ft_check_map_left_over(t_map *map);
int				ft_char_is_space(char c);
int				ft_has_valid_characters(char *str, int *spawn);
int				ft_map_to_parse(t_map *map);
int				ft_element_is_valid(char *str, t_map *map);
int				ft_check_array(int array[6], int elements);
int				ft_line_is_space(char *str);
int				ft_textures_and_colors(t_map *map, int elements);
int				ft_parse_valid(t_map *map);
char			*ft_check_args(int argc, char *str);
int				ft_has_valid_suffix(char *str);
int				ft_open_path(char *str);
char			*ft_remove_spaces(char *str);
char			*ft_handle_spaces(char *str);
void			ft_atoi_valid_range(char *str, int index, t_map *map, int range,
					int rgb);
int				ft_fill_color(char *str, t_map *map, int index);
int				ft_fill_texture(char *str, int index, t_map *map);
void			ft_init_textures_to_null(t_map *map);
void			ft_print_elements(t_map *map);
int				ft_free_table(char **buffer);
void			ft_print_table(char **tab);
int				ft_reopen_fd(t_map *map);
int				ft_calloc_tab(t_map *map);
int				ft_fill_tab(t_map *map);
void			ft_print_data(t_data *data);
int				ft_free_data(t_data *data);
int				ft_copy_table(t_map *map);
bool			ft_has_valid_path(t_map *map, int y, int x);
void			ft_find_start_pos(t_map *map);
int				ft_copy_to_data(t_map *map, t_data *data);
int				ft_map_playable(t_map *map, t_data *data);

// RAYCASTING
float			ft_deg_to_rad(float ray_angle);
int				ft_cast_rays(t_mlx *mlx);
float			ft_adjust_angle(float angle);
int				ft_cast_rays(t_mlx *mlx);
// RENDERING
int				ft_get_wall_color(t_mlx *mlx, int orientation_flag);
int				ft_draw_px_collumn(t_mlx *mlx, int ray_num, int wall_top_px,
					int wall_bot_px);
int				ft_fill_colors(t_mlx *mlx, int ray_num);
int				ft_put_pixel_to_screen(t_mlx *mlx, int x, int y, int color);
// MOVEMENT
int				key_release(int keycode, void *ml);
int				key_press(int keycode, void *ml);
int				ft_set_player(t_mlx *mlx);

#endif