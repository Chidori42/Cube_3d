/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:54:35 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/24 10:06:44 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void draw_minimap_player(t_params *param, int color)
{
    int player_size = 5;
    int x = param->player->x * player_size;
    int y = param->player->y * player_size;
    int map_width = param->data->wid;
    int map_height = param->data->hei;

    for (int i = 0; i < player_size; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if ((x - j >= 0) && (x + j < map_width) && (y + i >= 0) && (y + i < map_height))
            {
                mlx_put_pixel(param->data->img, x - j, y + i, color);
                mlx_put_pixel(param->data->img, x + j, y + i, color);
            }
        }
    }
}

void draw_minimap_circle(t_params *param, int x, int y, int radius, int color)
{
    int thickness = 1;
    for (int i = -radius; i <= radius; i++)
    {
        for (int j = -radius; j <= radius; j++)
        {
            int distance_squared = i * i + j * j;
            if (distance_squared <= (radius * radius) && distance_squared >= ((radius - thickness) * (radius - thickness)))
                mlx_put_pixel(param->data->img, x + j, y + i, color);
        }
    }
    draw_minimap_player(param, 0xFF0FF0);
}


void create_minimap(t_params *param, int minimap_size)
{
    mlx_delete_image(param->data->mlx, param->data->minimap);
    param->data->minimap = mlx_new_image(param->data->mlx, minimap_size, minimap_size);
    if (!param->data->minimap)
    {
        ft_putstr_fd("Error\nFailed to create minimap image", 2);
        exit(1);
    }
    draw_minimap_circle(param, minimap_size / 2, minimap_size / 2, minimap_size / 2, 0xFF00FF);
    mlx_image_to_window(param->data->mlx, param->data->minimap, 0, 0);
}
