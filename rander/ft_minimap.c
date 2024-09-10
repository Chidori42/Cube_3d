/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:54:35 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/09/10 23:50:29 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void draw_centered_minimap(t_params *param, int tile_size, int minimap_width, int minimap_height)
{
    float i, j;
    float map_x, map_y;

    float start_x = param->player->x - minimap_width / 2;
    float start_y =  param->player->y - minimap_height / 2;

    for (i = 0; i < minimap_height; i += 0.1)
    {
        for (j = 0; j < minimap_width; j += 0.1)
        {
            map_x = start_x + j;
            map_y = start_y + i;
            if (map_x >= 0 && map_x < param->data->wid && map_y >= 0 && map_y < param->data->hei)
            {
                float draw_x = j * tile_size;
                float draw_y = i * tile_size;
                if (param->data->map[(int)map_y][(int)map_x] == '1')
                    draw_pixel(param->data->img, tile_size / 10, draw_x, draw_y, 0xFFFFFF);
                else if (param->data->map[(int)map_y][(int)map_x] == '0')
                    draw_pixel(param->data->img, tile_size / 10, draw_x, draw_y, 0x0000FF);
            }
        }
    }
    int player_draw_x = (minimap_width / 2) * tile_size;
    int player_draw_y = (minimap_height / 2) * tile_size;
    draw_player_circle(param, player_draw_x, player_draw_y, 15, 0xFF00FF);
}

void draw_minimap(t_params *param)
{
    int tile_size = 45;
    int minimap_width = 3; 
    int minimap_height = 3;   
    draw_centered_minimap(param, tile_size, minimap_width, minimap_height);
}
