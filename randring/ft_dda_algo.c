/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-26 11:28:31 by ael-fagr          #+#    #+#             */
/*   Updated: 2024-07-26 11:28:31 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void dda_algo(t_data *args, float x1, float y1, float x2, float y2, int color)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    int steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
    float x_inc = dx / (float)steps;
    float y_inc = dy / (float)steps;
    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++)
    {
        if (args->map[(int)(y / 50)][(int)(x / 50)] == '1')
            return ;
        draw_pixel(args, 1, x, y, color);
        x += x_inc;
        y += y_inc;
    }
}
