/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:43:08 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/09/10 23:15:38 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int draw_pixel(mlx_image_t *img, float pixel_size, int a, int b, int color)
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
            mlx_put_pixel(img, (a  + j), (b + i), color);
            j++;
        }
        i++;
    }
	return (0);
}

void	draw_map(t_params *param)
{
    // int i;
    // int j;

    // j = 0;
    // i = 0;
    // while (param->data->map[j])
    // {
    //     i = 0;
    //     while (param->data->map[j][i])
    //     {     
    //         if (param->data->map[j][i] == '1')
    //             draw_pixel(param->data->img, 49, i * 50, j * 50, param->pars->ceiling_color);
    //         i++;
    //     }
    //     j++;
    // }
    draw_player_circle(param, param->player->x * 50, param->player->y * 50, 15, 0xFF00FF);
    draw_minimap(param); 
}
