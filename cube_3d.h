/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:37:29 by ksainte           #+#    #+#             */
/*   Updated: 2024/11/19 16:01:58 by ks19             ###   ########.fr       */
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


typedef struct s_map
{
    int fd;
    char *line;
    int row;
    char *path;
    char **tab;
    char *NO;
    char *SO;
    char *WE;
    char *EA;
    char *F;
    char *C;
    
    
} t_map;

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
int ft_has_valid_characters(char *str);
int	ft_map_to_parse(t_map *map);
int ft_element_is_valid(char *str);
int ft_check_array(int array[6]);
int ft_line_is_space(char *str);
int ft_textures_and_colors(t_map *map, int elements);
int ft_elements_to_parse(t_map *map);
char *ft_check_args(int argc, char *str);
int ft_has_valid_suffix(char *str);
int ft_open_path(char *str);

#endif