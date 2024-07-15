/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:43:08 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/02/05 11:33:02 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int draw_pixel(t_data *data, int pixel_size, int a, int b, int color)
{
	for (int i = 0; i < pixel_size; i++)
    {
        for (int j = 0; j < pixel_size; j++)
        {
            mlx_pixel_put(data->mlx, data->win, (a  + j), (b + i), color);
        }
    }
	return (0);
}
void	draw_map(t_data *arg)
{
    while (arg->map[arg->j])
    {
        arg->i = 0;
        while (arg->map[arg->j][arg->i])
        {
            if (arg->map[arg->j][arg->i] == '1')
                draw_pixel(arg, 30, arg->i * 50, arg->j * 50, 0xFFFFFF);
            else if (arg->map[arg->j][arg->i] == 'P')
                draw_pixel(arg, 20, arg->i * 50, arg->j * 50, 0xFFFF00);
            else if (arg->map[arg->j][arg->i] == '0')
                draw_pixel(arg, 30, arg->i * 50, arg->j * 50, 0x000000);
            arg->i++;
        }
        arg->j++;
    }
}
