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

int ft_dda_ago(t_data *args, int y1, int x1, int color)
{
    float dx = (float)x1 - args->x0; 
    float dy = (float)y1 - args->y0; 
   
    float steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy); 

    float Xinc = dx / steps * 0.25; 
    float Yinc = dy / steps * 0.25; 
    float X = args->x0; 
    float Y = args->y0; 
    for (int i = 0; i <= steps; i++) {
        if (args->map[(int)Y][(int)X] == '1')
            break ;
        draw_pixel(args, 3, X * 50, Y * 50, color);
        X += Xinc;
        Y += Yinc;
    } 
}