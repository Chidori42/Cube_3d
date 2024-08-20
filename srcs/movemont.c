/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movemont.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:42:46 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/20 04:33:13 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void move_player(t_params *param, float dx, float dy)
{
    param->pars->map[(int)param->pars->y0][(int)param->pars->x0] = '0';
	draw_camera_direction(param, 0x000000);
    draw_pixel(param->data, 10, param->pars->x0 * 50, param->pars->y0 * 50, 0x000000);
    param->pars->x0 += dx;
    param->pars->y0 += dy;
    param->pars->map[(int)param->pars->y0][(int)param->pars->x0] = 'P';
	init_camera(param->pars, param->camera);
	draw_camera_direction(param, 0xFF00FF);
    draw_pixel(param->data, 10, param->pars->x0 * 50, param->pars->y0 * 50, 0xFF00FF);
}

void key_press(void *p)
{
	t_params *param;

	param = p;
    if (mlx_is_key_down(param->data->mlx, MLX_KEY_UP))
	{
		if (param->pars->map[(int)(param->pars->y0 - MOVE_STEP)][(int)(param->pars->x0)] != '1')
			move_player(param, 0, -MOVE_STEP);
	}
	else if (mlx_is_key_down(param->data->mlx, MLX_KEY_DOWN))
	{
		if (param->pars->map[(int)(param->pars->y0 + MOVE_STEP)][(int)param->pars->x0] != '1')
			move_player(param, 0, MOVE_STEP);
	}
	else if (mlx_is_key_down(param->data->mlx, MLX_KEY_RIGHT))
	{
		if (param->pars->map[(int)param->pars->y0][(int)(param->pars->x0 + MOVE_STEP)] != '1')
			move_player(param, MOVE_STEP, 0);
	}
	else if (mlx_is_key_down(param->data->mlx, MLX_KEY_LEFT))
	{
		if (param->pars->map[(int)param->pars->y0][(int)(param->pars->x0 - MOVE_STEP)] != '1')
			move_player(param, -MOVE_STEP, 0);
	}
	if (mlx_is_key_down(param->data->mlx, MLX_KEY_ESCAPE))
		(ft_free_exit(param), mlx_close_window(param->data->mlx));
}
