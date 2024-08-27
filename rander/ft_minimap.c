/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:54:35 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/26 20:34:12 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void draw_new_mini_map(t_params *param, int start_x, int start_y, int end_x, int end_y)
{
    int x, y;

    y = start_y;
    while (param->pars->map[y] && y < end_y)
    {
        x = start_x;
        while (param->pars->map[y][x] && x < end_x)
        {
            if (param->pars->map[y][x] == '1')
                draw_pixel(param->data->img, 4, x * 5, y * 5, 0xFFFFFF);
            else
                draw_pixel(param->data->img, 4, x * 5, y * 5, 0x00000000);
            x++;
        }
        y++;
    }
    draw_pixel(param->data->img, 2, param->player->x * 5, param->player->y * 5, 0xFF00FF);
}

void draw_minimap(t_params *param)
{
    int radius =  10;
    int start_x = param->player->x - radius;
    int start_y = param->player->y - radius;
    int end_x = param->player->x + radius;
    int end_y = param->player->y + radius;

    if (start_x < 0)
        start_x = 0;
    if (start_y < 0)
        start_y = 0;
    if (end_x > param->data->wid)
        end_x = param->data->wid;
    if (end_y > param->data->hei)
        end_y = param->data->hei;
    draw_new_mini_map(param, start_x, start_y, end_x, end_y);
}
