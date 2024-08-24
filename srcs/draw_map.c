/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:43:08 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/24 09:00:19 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"


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
            mlx_put_pixel(data->img, (a  + j), (b + i), color);
            j++;
        }
        i++;
    }
	return (0);
}

void	draw_map(t_params *param)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (param->pars->map[j])
    {
        i = 0;
        while (param->pars->map[j][i])
        {
            if (param->pars->map[j][i] == '1')
                draw_pixel(param->data, 49, i * 50, j * 50, 0xFFFFFF);
            i++;
        }
        j++;
    }
}
