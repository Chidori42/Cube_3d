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

static void move_player(t_data *args, float dx, float dy)
{
    args->map[(int)args->y0][(int)args->x0] = '0';
	dda_algo(args, args->x0 * 50, args->y0 * 50, args->x0 * 50, (args->y0 - 1) * 50, 0x000000);
    draw_pixel(args, 10, args->x0 * 50, args->y0 * 50, 0x000000);
    args->x0 += dx;
    args->y0 += dy;
    args->map[(int)args->y0][(int)args->x0] = 'P';
    dda_algo(args, args->x0 * 50, args->y0 * 50, args->x0 * 50, (args->y0 - 1) * 50, 0xFF0000); 
    draw_pixel(args, 10, args->x0 * 50, args->y0 * 50, 0xFFFF00);
}

int	key_press(int keycode, t_data *args)
{
    if (keycode ==  65362 || keycode == 122)
	{
		if (args->map[(int)(args->y0 - MOVE_STEP)][(int)(args->x0)] != '1')
			move_player(args, 0, -MOVE_STEP);
	}
	else if (keycode == 65364 || keycode == 115)
	{
		if (args->map[(int)(args->y0 + MOVE_STEP)][(int)args->x0] != '1')
			move_player(args, 0, MOVE_STEP);
	}
	else if (keycode == 65363 || keycode == 100)
	{
		if (args->map[(int)args->y0][(int)(args->x0 + MOVE_STEP)] != '1')
			move_player(args, MOVE_STEP, 0);
	}
	else if (keycode == 65361 || keycode == 113)
	{
		if (args->map[(int)args->y0][(int)(args->x0 - MOVE_STEP)] != '1')
			move_player(args, -MOVE_STEP, 0);
	}
	else if (keycode == 65307)
		exit(0);
    return (0);
}