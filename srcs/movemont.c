/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movemont.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:42:46 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/18 22:53:12 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void move_player(t_data *data, t_pars *args, float dx, float dy)
{
    args->map[(int)args->y0][(int)args->x0] = '0';
    draw_pixel(data, 10, args->x0 * 50, args->y0 * 50, 0x000000);
    args->x0 += dx;
    args->y0 += dy;
    args->map[(int)args->y0][(int)args->x0] = 'P';
    draw_pixel(data, 10, args->x0 * 50, args->y0 * 50, 0xFF00FF);
}

void key_press(void *p)
{
	t_params *param;

	param = p;
	init_camera(param->pars, param->camera);
	draw_camera_direction(param, 0x000000); 
    if (mlx_is_key_down(param->data->mlx, MLX_KEY_UP))
	{
		if (param->pars->map[(int)(param->pars->y0 - MOVE_STEP)][(int)(param->pars->x0)] != '1')
			move_player(param->data, param->pars, 0, -MOVE_STEP);
	}
	else if (mlx_is_key_down(param->data->mlx, MLX_KEY_DOWN))
	{
		if (param->pars->map[(int)(param->pars->y0 + MOVE_STEP)][(int)param->pars->x0] != '1')
			move_player(param->data, param->pars, 0, MOVE_STEP);
	}
	else if (mlx_is_key_down(param->data->mlx, MLX_KEY_RIGHT))
	{
		if (param->pars->map[(int)param->pars->y0][(int)(param->pars->x0 + MOVE_STEP)] != '1')
			move_player(param->data, param->pars, MOVE_STEP, 0);
	}
	else if (mlx_is_key_down(param->data->mlx, MLX_KEY_LEFT))
	{
		if (param->pars->map[(int)param->pars->y0][(int)(param->pars->x0 - MOVE_STEP)] != '1')
			move_player(param->data, param->pars, -MOVE_STEP, 0);
	}
	if (mlx_is_key_down(param->data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(param->data->mlx);
	draw_camera_direction(param, 0xFF00FF); 
}
