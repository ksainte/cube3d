/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ks19 <ks19@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 01:27:12 by ks19              #+#    #+#             */
/*   Updated: 2024/12/17 01:43:52 by ks19             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

int mv_vert_right_up(t_mlx *mlx) 
{
    float cos1 = cos(ft_deg_to_rad(mlx->player->pa));
    float cos2 = cos(ft_deg_to_rad(ft_adjust_angle(mlx->player->pa - 90)));
    if (cos1 > 0.0000001 && cos2 > 0.0000001)
        return (1);
    return (0);
}

int mv_vert_right_down(t_mlx *mlx) 
{
    float cos1 = cos(ft_deg_to_rad(mlx->player->pa));
    float cos2 = cos(ft_deg_to_rad(ft_adjust_angle(mlx->player->pa + 90)));
    
    if (cos1 > 0.0000001 && cos2 > 0.0000001)
        return (1);
    return (0);
}

int mv_vert_left_up(t_mlx *mlx) 
{
    float cos1 = cos(ft_deg_to_rad(mlx->player->pa));
    float cos2 = cos(ft_deg_to_rad(ft_adjust_angle(mlx->player->pa + 90)));
    
    if (cos1 < -0.0000001 && cos2 < -0.0000001)
        return (1);
    return (0);
}

int mv_vert_left_down(t_mlx *mlx) 
{
    float cos1 = cos(ft_deg_to_rad(mlx->player->pa));
    float cos2 = cos(ft_deg_to_rad(ft_adjust_angle(mlx->player->pa - 90)));
    
    if (cos1 < -0.0000001 && cos2 < -0.0000001)
        return (1);
    return (0);
}
