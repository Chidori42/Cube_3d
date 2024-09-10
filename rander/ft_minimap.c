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

void ft_draw_square(t_data *data, int x, int y, int color)
{
    int i;
    int j;

    i = 0;
    while (i < 10)
    {
        j = 0;
        while (j < 10)
        {
            mlx_put_pixel(data->img, x * 10 + j, y * 10 + i, color);
            j++;
        }
        i++;
    }
}

void draw_minimap(t_params *param)
{
    int i;
    int j;

    i = param->player->x - 5;

    while (i < param->player->x + 5)
    {
        j = param->player->y - 5;
        while (j < param->player->y + 5)
        {
            if (i >= 0 && j >= 0 && i < param->data->wid && j < param->data->hei)
            {
                if (param->data->map[j][i] == '1')
                    ft_draw_square(param->data, i - param->player->x + 5, j - param->player->y + 5, 0xFF00FF);
                else if (param->data->map[j][i] == '0')
                    ft_draw_square(param->data, i - param->player->x + 5, j - param->player->y + 5, 0x00000000);
            }
            j++;
        }
        i++;
    }
}


