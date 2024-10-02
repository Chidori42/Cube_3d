/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:54:35 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/09/30 16:42:11 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void draw_centered_minimap(t_params *param, int range, float start_x, float start_y)
{
    float   i;
    float   j;
    float   map_x;
    float   map_y;

    i = 0;
    while (i < range)
    {
        j = 0;
        while (j < range)
        {
            map_x = start_x + j;
            map_y = start_y + i;
            if (map_x > 0 && map_x < param->data->map_wid && map_y > 0 && map_y < param->data->map_hei)
            {
                if (param->data->map[(int)map_y][(int)map_x] == '1')
                    draw_pixel(param->data->img, 4, j * 25, i * 25, param->pars->ceiling_color);
                else
                    draw_pixel(param->data->img, 4, j * 25, i * 25, 0x0000FFF);
            }
            else
                draw_pixel(param->data->img, 4, j * 25, i * 25, 0x0000FFF);
            j += 0.1;
        }
        i += 0.1;
    }
    draw_player_circle(param->data->img, 100, 100, 15, 0xFF00FF);
}

int draw_minimap(t_params *param)
{
    int     range;
    float   start_x;
    float   start_y;

    range = 8;
    start_x = param->player->x - range / 2;
    start_y =  param->player->y - range / 2;
    draw_centered_minimap(param, range, start_x, start_y);
    return (0);
}
