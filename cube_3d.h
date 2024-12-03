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

# define SCREEN_WIDTH 600
# define SCREEN_HEIGHT 600
# define TILE 64
# define FIELD_OF_VIEW 60
# define ROTATION_S
# define PLAYER_S
# define PI 3.14159265358979323846
# define PI_90 1.57079632679
// # define PI_270
# define VERTICAL_WALL 0
# define HORIZONTAL_WALL 1

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
typedef struct s_player
{
	int			start_x;//start x pos
	int			start_y;//start y pos
	float		px;
	float		py;
	char		orientation_start;
	float		pa;
	float		player_fov_radians;
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
	int 		flag_cos;
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
	void		*img;
}				t_mlx;

#endif