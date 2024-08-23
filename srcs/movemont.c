/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movemont.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:42:46 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/23 15:44:58 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void draw_player(t_params *param, int color)
{
	float radius = 3.5;
	int cx = param->player->x * 50;
	int cy = param->player->y * 50;

	for (float y = -radius; y <= radius; y++)
	{
		for (float x = -radius; x <= radius; x++)
		{
			if (x * x + y * y <= radius * radius)
			{
				if (param->pars->map[(int)(cy + y) / 50][(int)(cx + x) / 50] == '1')
					continue;
				mlx_put_pixel(param->data->img, cx + x, cy + y, color);
			}
		}
	}
}

static void move_player(t_params *param, float dx, float dy)
{
    if (param->pars->map[(int)(param->player->y + dy)][(int)(param->player->x + dx)] != '1')
    {
        param->pars->map[(int)param->player->y][(int)param->player->x] = '0';
		draw_player(param, 0x000000);
        param->player->x += dx;
        param->player->y += dy;
		param->pars->map[(int)param->player->y][(int)param->player->x] = param->player->p_char;
        draw_map(param);
    }
}

void key_press(void *p)
{
	t_params *param;

	param = p;
    if (mlx_is_key_down(param->data->mlx, MLX_KEY_UP))
			move_player(param, 0, -MOVE_STEP);
	else if (mlx_is_key_down(param->data->mlx, MLX_KEY_DOWN))
			move_player(param, 0, MOVE_STEP);
	else if (mlx_is_key_down(param->data->mlx, MLX_KEY_RIGHT))
			move_player(param, MOVE_STEP, 0);
	else if (mlx_is_key_down(param->data->mlx, MLX_KEY_LEFT))
			move_player(param, -MOVE_STEP, 0);
	if (mlx_is_key_down(param->data->mlx, MLX_KEY_ESCAPE))
		(ft_free_exit(param), mlx_close_window(param->data->mlx));
	draw_minimap(param);
}
