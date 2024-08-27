/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:04:33 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/26 20:13:17 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void draw_line(t_params *param, int start_x, int start_y, int end_x, int end_y, int color)
{
    int dy = end_y - start_y;
    int dx = end_x - start_x;
    int d = (2 * dy) - dx;
    int step;
    if (d > 0)
        step = 2 * dy - 2 * dx;
    else
        step = 2 * dy;
    while (start_x < end_x)
    {
        mlx_put_pixel(param->data->img, start_x, start_y, color);
        if (d > 0)
        {
            start_y++;
            d += step;
        }
        else
            d += 2 * dy;
        start_x++;
    }
}
