/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movemont.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:42:46 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/01/25 00:15:05 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void move_up(t_data *data)
{
    if (data->map[data->y - 1][data->x] != 'E')
    {
        data->map[data->y][data->x] = 0;
		draw_pixel(data, 20, data->x * 50, data->y * 50, 0x000000);
		ft_draw_lines(data, data->retate_y, data->retate_x, 0x000000);
        data->y -= 1;
        draw_pixel(data, 20, data->x * 50, data->y * 50, 0xFFFF00);
		ft_draw_lines(data, data->retate_y, data->retate_x, 0xFFFF00);
    }
}

static void move_down(t_data *data)
{
    if (data->map[data->y + 1][data->x] != 'E')
    {
        data->map[data->y][data->x] = 0;
		draw_pixel(data, 20, data->x * 50, data->y * 50, 0x000000);
		ft_draw_lines(data, data->retate_y, data->retate_x, 0x000000);
        data->y += 1;
        draw_pixel(data, 20, data->x * 50, data->y * 50, 0xFFFF00);
		ft_draw_lines(data, data->retate_y, data->retate_x, 0xFFFF00);
    }
}

static void move_right(t_data *data)
{
    if (data->map[data->y][data->x + 1] != 'E')
    {
        data->map[data->y][data->x] = 0;
		draw_pixel(data, 20, data->x * 50, data->y * 50, 0x000000);
		ft_draw_lines(data, data->retate_y, data->retate_x, 0x000000);
        data->x += 1;
        draw_pixel(data, 20, data->x * 50, data->y * 50, 0xFFFF00);
		ft_draw_lines(data, data->retate_y, data->retate_x, 0xFFFF00);
    }
}

static void move_left(t_data *data)
{
    if (data->map[data->y][data->x - 1] != 'E')
    {
        data->map[data->y][data->x] = 0;
		draw_pixel(data, 20, data->x * 50, data->y * 50, 0x000000);
		ft_draw_lines(data, data->retate_y, data->retate_x, 0x000000);
        data->x -= 1;
        draw_pixel(data, 20, data->x * 50, data->y * 50, 0xFFFF00);
		ft_draw_lines(data, data->retate_y, data->retate_x, 0xFFFF00);
	}
}

int	key_press(int keycode, t_data *par)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 119)
	{
		ft_draw_lines(par, par->retate_y, par->retate_x, 0x000000);
		par->retate_y += 1;
		par->retate_x -= 1;
		ft_draw_lines(par, par->retate_y, par->retate_x, 0xFFFF00);
	}
	if (keycode == 120)
	{
		ft_draw_lines(par, par->retate_y, par->retate_x, 0x000000);
		par->retate_y -= 1;
		par->retate_x += 1;
		ft_draw_lines(par, par->retate_y, par->retate_x, 0xFFFF00);
	}
	if (keycode ==  65362 || keycode == 122)
	{
		if (par->map[par->y - 1][par->x] != '1')
			move_up(par);
	}
	else if (keycode == 65364 || keycode == 115)
	{
		if (par->map[par->y + 1][par->x] != '1')
			move_down(par);
	}
	else if (keycode == 65363 || keycode == 100)
	{
		if (par->map[par->y][par->x + 1] != '1')
			move_right(par);
	}
	else if (keycode == 65361 || keycode == 113)
	{
		if (par->map[par->y][par->x - 1] != '1')
			move_left(par);
	}
	else if (keycode == 65307)
		exit(0);
	return (0);
}
