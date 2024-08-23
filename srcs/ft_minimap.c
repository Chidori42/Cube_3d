/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:54:35 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/23 15:49:19 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void draw_minimap(t_params *param)
{
    int x;
    int y;
    int color;

    y = 0;
    while (y < param->data->hei)
    {
        x = 0;
        while (x < param->data->wid)
        {
            if (param->pars->map[y][x] == '1')
                color = 0xFFFFFF;
            else if (param->pars->map[y][x] == 'N' || param->pars->map[y][x] == 'S'
                || param->pars->map[y][x] == 'W' || param->pars->map[y][x] == 'E')
                color = 0xFF00FF;
            else
                color = 0x000000;
            mlx_put_pixel(param->data->img, x * 5, y * 5, color);
            x++;
        }
        y++;
    }
}
