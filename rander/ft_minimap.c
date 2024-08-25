/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:54:35 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/25 12:52:09 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void draw_minimap(t_params *param)
{
    int x;
    int y;
    int color;

    y = 0;
    while (param->pars->map[y])
    {
        x = 0;
        while (param->pars->map[y][x])
        {
            if (param->pars->map[y][x] == '1')
                color = 0xFFFFFF;
            else
                color = 0;
            draw_pixel(param->data->minimap, 3, x * 5, y * 5, color);
            x++;
        }
        y++;
    }
    draw_pixel(param->data->minimap, 1.5, param->player->x * 5, param->player->y * 5, 0xFF00FF);
}


void create_minimap(t_params *param)
{
    mlx_delete_image(param->data->mlx, param->data->minimap);
    param->data->minimap = mlx_new_image(param->data->mlx, param->data->wid * 5, param->data->hei * 5);
    if (!param->data->minimap)
    {
        ft_putstr_fd("Error\nFailed to create minimap image", 2);
        exit(1);
    }
    draw_minimap(param);
    mlx_image_to_window(param->data->mlx, param->data->minimap, 0, 0);
}
