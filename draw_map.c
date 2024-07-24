/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:43:08 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/07/24 01:28:10 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


int draw_pixel(t_data *data, int pixel_size, int a, int b, int color)
{
    int i;
    int j;

    i = 0;
    j = 0;
	while (i < pixel_size)
    {
        j = 0;
        while (j < pixel_size)
        {
            mlx_pixel_put(data->mlx, data->win, (a  + j), (b + i), color);
            j++;
        }
        i++;
    }
	return (0);
}
void	draw_map(t_data *arg)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (arg->map[j])
    {
        i = 0;
        while (arg->map[j][i])
        {
            if (arg->map[j][i] == '1')
                draw_pixel(arg, 49, i * 50, j * 50, 0xFFFFFF);
            else if (arg->map[j][i] == 'N' || arg->map[j][i] == 'S'
                || arg->map[j][i] == 'W' || arg->map[j][i] == 'E')
                draw_pixel(arg, 10, i * 50, j * 50, 0xFFFF00);
            else if (arg->map[j][i] == '0')
                draw_pixel(arg, 49, i * 50, j * 50, 0x000000);
            i++;
        }
        j++;
    }
}
