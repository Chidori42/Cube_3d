/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 23:03:48 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/18 23:03:23 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void    draw_line_dda(t_params *param, int x0, int y0, int x1, int y1, int color)
{
    int dx = x1 - x0; 
    int dy = y1 - y0; 
  
    int step; 
    if (abs(dx) > abs(dy)) 
        step = abs(dx); 
    else
        step = abs(dy); 
  
    float x_incr = (float)dx / step; 
    float y_incr = (float)dy / step; 
  
    float x = x0; 
    float y = y0; 
  
    for (int i = 0; i < step; i++)
    {
        if (param->pars->map[(int)y / 50][(int)x / 50] == '1')
            break ;
        mlx_put_pixel(param->data->img, x, y, color);
        x += x_incr; 
        y += y_incr; 
    } 
}

void    draw_camera_direction(t_params *param, int color)
{
    int px;
    int py;
    int dx;
    int dy;

    px = param->camera->posX * 50;
    py = param->camera->posY * 50;
    dx = param->camera->dirX * 50;
    dy = param->camera->dirY * 50;
    printf("px = %d py = %d\n dx = %d dy = %d\n", px, py, dx, dy);
    draw_line_dda(param, px, py, dx, dy - 50, color);
    printf("hello !\n");
}
