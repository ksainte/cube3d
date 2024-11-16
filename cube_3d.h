/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:37:29 by ksainte           #+#    #+#             */
/*   Updated: 2024/11/16 13:04:56 by ks19             ###   ########.fr       */
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
    
    
} t_map;

#endif