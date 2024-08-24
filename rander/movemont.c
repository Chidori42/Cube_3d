/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movemont.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:42:46 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/24 10:03:14 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void move_player(t_params *param, float dx, float dy)
{
	mlx_delete_image(param->data->mlx, param->data->img);
	param->data->img = mlx_new_image(param->data->mlx, param->data->wid * 50, param->data->hei * 50);
    if (param->pars->map[(int)(param->player->y + dy)][(int)(param->player->x + dx)] != '1')
    {
        param->pars->map[(int)param->player->y][(int)param->player->x] = '0';
        param->player->x += dx;
        param->player->y += dy;
		param->pars->map[(int)param->player->y][(int)param->player->x] = param->player->p_char;
    }
	mlx_image_to_window(param->data->mlx, param->data->img, 0, 0);
    draw_map(param);
    create_minimap(param, 200);
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
}
