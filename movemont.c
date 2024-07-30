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
    data->map[(int)data->y0][(int)data->x0] = '0';
    draw_pixel(data, 10, data->x0 * 50, data->y0 * 50, 0x000000);
    data->y0 -= 0.25;
    draw_pixel(data, 10, data->x0 * 50, data->y0 * 50, 0xFFFF00);
	data->map[(int)data->y0][(int)data->x0] = 'P';
}

static void move_down(t_data *data)
{
    data->map[(int)data->y0][(int)data->x0] = '0';
    draw_pixel(data, 10, data->x0 * 50, data->y0 * 50, 0x000000);
    data->y0 += 0.25;
    draw_pixel(data, 10, data->x0 * 50, data->y0 * 50, 0xFFFF00);
	data->map[(int)data->y0][(int)data->x0] = 'P';
}

static void move_right(t_data *data)
{
    data->map[(int)data->y0][(int)data->x0] = '0';
    draw_pixel(data, 10, data->x0 * 50, data->y0 * 50, 0x000000);
    data->x0 += 0.25;
    draw_pixel(data, 10, data->x0 * 50, data->y0 * 50, 0xFFFF00);
	data->map[(int)data->y0][(int)data->x0] = 'P';
}

static void move_left(t_data *data) {
    data->map[(int)data->y0][(int)data->x0] = '0';
    draw_pixel(data, 10, data->x0 * 50, data->y0 * 50, 0x000000);
    data->x0 -= 0.25;
    draw_pixel(data, 10, data->x0 * 50, data->y0 * 50, 0xFFFF00);
	data->map[(int)data->y0][(int)data->x0] = 'P';
}

int	key_press(int keycode, t_data *args)
{
    printf("keycode: %d\n", keycode);
	ft_dda_ago(args, args->wid - args->x0, 0, 0x000000);
	// draw_direction_line(args, 0x000000);
    if (keycode ==  65362 || keycode == 122)
	{
		if (args->map[(int)(args->y0 - 0.25)][(int)(args->x0)] != '1')
			move_up(args);
	}
	else if (keycode == 65364 || keycode == 115)
	{
		if (args->map[(int)(args->y0 + 0.25)][(int)args->x0] != '1')
			move_down(args);
	}
	else if (keycode == 65363 || keycode == 100)
	{
		if (args->map[(int)args->y0][(int)(args->x0 + 0.25)] != '1')
			move_right(args);
	}
	else if (keycode == 65361 || keycode == 113)
	{
		if (args->map[(int)args->y0][(int)(args->x0 - 0.25)] != '1')
			move_left(args);
	}
	else if (keycode == 65307)
		exit(0);
	ft_dda_ago(args, args->wid - args->x0, 0, 0xFF0000);
	// draw_direction_line(args, 0xFF0000);
	printf("x0: %f, y0: %f\n", args->x0, args->y0);
    return (0);
}