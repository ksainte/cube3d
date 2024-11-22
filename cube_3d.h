/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:37:29 by ksainte           #+#    #+#             */
/*   Updated: 2024/11/22 11:05:16 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_3D_H
# define CUBE_3D_H

# include "./Libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
#include <string.h>
#include <stdbool.h>


typedef struct s_map
{
    int fd;
    int index;
    int s_x;
    int s_y;
    char *line;
    int row;
    char *path;
    char **tab;
    char **tmp;
    char *NO;
    char *SO;
    char *WE;
    char *EA;
    int F[3];
    int C[3];
        
} t_map;

typedef struct s_data
{

    char **tab;
    int s_x;
    int s_y;
    int row;
    char *NO;
    char *SO;
    char *WE;
    char *EA;
    int F[3];
    int C[3];


} t_data;

void ft_system_error(void);
char *ft_custom_error(char *str);
int ft_free(t_map *map);
int ft_free_line(t_map *map);
int	ft_map_error(int error);
int ft_valid_number_range(char *str, int range);
int ft_check_until_comma_or_null(char *str);
int ft_valid_characters(char *str, int range, int *len, int *rgb);
int ft_valid_color_range(char *str, int *rgb);
int ft_valid_color(char *str);
int	ft_check_map_left_over(t_map *map);
int ft_char_is_space(char c);
int ft_has_valid_characters(char *str, int *spawn);
int	ft_map_to_parse(t_map *map);
int ft_element_is_valid(char *str, t_map *map);
int ft_check_array(int array[6], int elements);
int ft_line_is_space(char *str);
int ft_textures_and_colors(t_map *map, int elements);
int ft_parse_valid(t_map *map);
char *ft_check_args(int argc, char *str);
int ft_has_valid_suffix(char *str);
int ft_open_path(char *str);
char *ft_remove_spaces(char *str);
char *ft_handle_spaces(char *str);
void ft_atoi_valid_range(char *str, int index, t_map *map, int range, int rgb);
int ft_fill_color(char *str, t_map *map, int index);
int ft_fill_texture(char *str, int index, t_map *map);
void ft_init_textures_to_null(t_map *map);
void ft_print_elements(t_map *map);
int	ft_free_table(char **buffer);
void ft_print_table(char **tab);
int ft_reopen_fd(t_map *map);
int	ft_calloc_tab(t_map *map);
int	ft_fill_tab(t_map *map);
void ft_print_data(t_data *data);
int ft_free_data(t_data *data);
int	ft_copy_table(t_map *map);
bool	ft_has_valid_path(t_map *map, int y, int x);
void	ft_find_start_pos(t_map *map);
int ft_copy_to_data(t_map *map, t_data *data);
int	ft_map_playable(t_map *map, t_data *data);
#endif