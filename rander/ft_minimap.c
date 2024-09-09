/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:54:35 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/09/09 08:33:05 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void draw_square_minimap(t_params *param, int x, int y, int minimap_width, int minimap_height)
{
    int i;
    int j;
    int color;

    i = 0;
    j = 0;
    while (i < minimap_height)
    {
        j = 0;
        while (j < minimap_width)
        {
            if (param->data->map[(int)(i)][(int)(j)] == '1')
                color = 0xFFFFFF;
            else
                color = 0x000000;
            draw_pixel(param->data->img, 3, x + j, y + i, color);
            j++;
        }
        i++;
    }
}

void draw_minimap(t_params *param)
{
    int minimap_width = 200;
    int minimap_height = 200;
    int minimap_x = 50;
    int minimap_y = 50;

    draw_square_minimap(param, minimap_x, minimap_y, minimap_width, minimap_height);
}


