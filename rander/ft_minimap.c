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

void ft_draw_square(t_data *data, int x, int y, int color, int scale)
{
    int i;
    int j;

    i = 0;
    while (i < scale)
    {
        j = 0;
        while (j < scale)
        {
            mlx_put_pixel(data->img, x + j, y + i, color);
            j++;
        }
        i++;
    }
}

void draw_centered_minimap(t_params *param, int tile_size, int minimap_width, int minimap_height)
{
    int i, j;
    int map_x, map_y;

    int start_x = param->player->x - minimap_width / 2;
    int start_y =  param->player->y - minimap_height / 2;

    i =0;
    while (i < minimap_height)
    {
        j = 0;
        while(j < minimap_width)
        {
            map_x = start_x + j;
            map_y = start_y + i;
            if (map_x >= 0 && map_x < param->data->wid && map_y >= 0 && map_y < param->data->hei)
            {
                int draw_x = j * tile_size; 
                int draw_y = i * tile_size;
                if (param->data->map[map_y][map_x] == '1')
                    ft_draw_square(param->data, draw_x, draw_y, 0xFFFFFF, tile_size);
                else if (param->data->map[map_y][map_x] == '0')
                    ft_draw_square(param->data, draw_x, draw_y, 0x000000, tile_size);
            }
        }
    }
    int player_draw_x = (minimap_width / 2) * tile_size;
    int player_draw_y = (minimap_height / 2) * tile_size;
    draw_player_circle(param, player_draw_x, player_draw_y, tile_size / 2, 0xFF00FF);
}

void draw_minimap(t_params *param)
{
    int tile_size = 25; 
    int minimap_width = 8; 
    int minimap_height = 8;   
    draw_centered_minimap(param, tile_size, minimap_width, minimap_height);
}
