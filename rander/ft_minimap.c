/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:54:35 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/02 20:27:05 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void draw_player_circle(mlx_image_t *img, float x, float y, int size, int color)
{
    int i;
    int j;
    int r;

    r = size / 2;
    i = -r;
    while (i < r)
    {
        j = -r;
        while (j < r)
        {
            if (i * i + j * j <= r * r)
                draw_pixel(img, 1, x + i, y + j, color);
            j++;
        }
        i++;
    }
    mlx_put_pixel(img, x, y, 0x00FF00);
}

void draw_centered_minimap(t_data *data, int range, float start_x, float start_y)
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
            if (map_x > 0 && map_x < data->map_w && map_y > 0 && map_y < data->map_h)
            {
                if (data->map[(int)map_y][(int)map_x] == '1')
                    draw_pixel(data->img, 4, j * 25, i * 25, data->pars.ceiling_color);
                else
                    draw_pixel(data->img, 4, j * 25, i * 25, 0x0000FFF);
            }
            else
                draw_pixel(data->img, 4, j * 25, i * 25, 0x0000FFF);
            j += 0.1;
        }
        i += 0.1;
    }
    draw_player_circle(data->img, 100, 100, 15, 0xFF00FF);
}

int draw_minimap(t_data *dt)
{
    int     range;
    float   start_x;
    float   start_y;

    range = 8;
    float px = dt->player->x / TILE_SIZE;
    float py = dt->player->y / TILE_SIZE;
    printf("player_x: %d, player_y: %d\n", dt->p_x_pos_in_map, dt->p_y_pos_in_map);
    printf("player_x: %f, player_y: %f\n", px, py);
    start_x = px - range / 2;
    start_y =  py - range / 2;
    draw_centered_minimap(dt, range, start_x, start_y);
    return (0);
}
