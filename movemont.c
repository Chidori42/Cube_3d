/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movemont.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:42:46 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/07/24 01:25:45 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void move_up(t_data *data)
{
    data->map[(int)data->y0][(int)data->x0] = 0;
    draw_pixel(data, 10, data->x0 * 50, data->y0 * 50, 0x000000);
    data->y0 -= 0.25;
    draw_pixel(data, 10, data->x0 * 50, data->y0 * 50, 0xFFFF00);
}

static void move_down(t_data *data)
{
    data->map[(int)data->y0][(int)data->x0] = 0;
    draw_pixel(data, 10, data->x0 * 50, data->y0 * 50, 0x000000);
    data->y0 += 0.25;
    draw_pixel(data, 10, data->x0 * 50, data->y0 * 50, 0xFFFF00);
}

static void move_right(t_data *data)
{
    data->map[(int)data->y0][(int)data->x0] = 0;
    draw_pixel(data, 10, data->x0 * 50, data->y0 * 50, 0x000000);
    data->x0 += 0.25;
    draw_pixel(data, 10, data->x0 * 50, data->y0 * 50, 0xFFFF00);
}

static void move_left(t_data *data) {
    data->map[(int)data->y0][(int)data->x0] = 0;
    draw_pixel(data, 10, data->x0 * 50, data->y0 * 50, 0x000000);
    data->x0 -= 0.25;
    draw_pixel(data, 10, data->x0 * 50, data->y0 * 50, 0xFFFF00);
}

int	key_press(int keycode, t_data *args)
{
    printf("keycode: %d\n", keycode);
	// draw_direction_line(args, 0x000000);
    if (keycode == 126)//a
	{
		if (args->map[(int)(args->y0 - 0.25)][(int)args->x0] != '1')
			move_up(args);
	}
	else if (keycode == 125)//s
	{
		if (args->map[(int)(args->y0 + 0.25)][(int)args->x0] != '1')
			move_down(args);
	}
	else if (keycode == 124)//d
	{
		if (args->map[(int)args->y0][(int)(args->x0 + 0.25)] != '1')
			move_right(args);
	}	
	else if (keycode == 123)//w
	{
		if (args->map[(int)args->y0][(int)(args->x0 - 0.25)] != '1')
			move_left(args);
	}
    else if (keycode == 53)//esc
        exit(0);
	// draw_direction_line(args, 0xFF0000);
	printf("x0: %f, y0: %f\n", args->x0, args->y0);
    return (0);
}