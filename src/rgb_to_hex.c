/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:29:14 by asideris          #+#    #+#             */
/*   Updated: 2024/12/17 14:33:01 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_3d.h"

int rgb_to_hex(int r, int g, int b) 
{
    if (r < 0) {
        r = 0;
    }
    if (r > 255) {
        r = 255;
    }

    if (g < 0) {
        g = 0;
    }
    if (g > 255) {
        g = 255;
    }

    if (b < 0) {
        b = 0;
    }
    if (b > 255) {
        b = 255;
    }

    return (r << 16) | (g << 8) | b;
}
