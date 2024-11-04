/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:58:00 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/11/03 12:18:53 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

void	key_up_down(t_data *dt)
{
	double	new_x;
	double	new_y;

	if (mlx_is_key_down(dt->mlx, MLX_KEY_W))
	{
		new_x = cos(dt->player->rot_angle) * PLYR_SPEED;
		new_y = sin(dt->player->rot_angle) * PLYR_SPEED;
		move_player(dt, new_x, new_y);
		game_loop(dt);
	}
	else if (mlx_is_key_down(dt->mlx, MLX_KEY_S))
	{
		new_x = -cos(dt->player->rot_angle) * PLYR_SPEED;
		new_y = -sin(dt->player->rot_angle) * PLYR_SPEED;
		move_player(dt, new_x, new_y);
		game_loop(dt);
	}
}

void	ft_mouse_hook(t_data *dt)
{
	int	x;
	int	y;
	int	dx;

	if (dt->is_mouse == false)
		return ;
	mlx_get_mouse_pos(dt->mlx, &x, &y);
	dx = x - S_W / 2;
	dt->player->rot_angle += dx * FACTOR;
	dt->player->rot_angle = normalize_angle(dt->player->rot_angle);
	mlx_set_mouse_pos(dt->mlx, S_W / 2, S_H / 2);
	game_loop(dt);
}

void	key_left_right(t_data *dt)
{
	double	new_x;
	double	new_y;

	if (mlx_is_key_down(dt->mlx, MLX_KEY_A))
	{
		new_x = sin(dt->player->rot_angle) * PLYR_SPEED;
		new_y = -cos(dt->player->rot_angle) * PLYR_SPEED;
		move_player(dt, new_x, new_y);
		game_loop(dt);
	}
	else if (mlx_is_key_down(dt->mlx, MLX_KEY_D))
	{
		new_x = -sin(dt->player->rot_angle) * PLYR_SPEED;
		new_y = cos(dt->player->rot_angle) * PLYR_SPEED;
		move_player(dt, new_x, new_y);
		game_loop(dt);
	}
}

void	key_handler(void *param)
{
	t_data		*dt;

	dt = (t_data *)param;
	if (mlx_is_key_down(dt->mlx, MLX_KEY_ESCAPE))
		ft_exit(dt, "exit");
	if (mlx_is_key_down(dt->mlx, MLX_KEY_LEFT))
		player_rotation(dt, '-');
	else if (mlx_is_key_down(dt->mlx, MLX_KEY_RIGHT))
		player_rotation(dt, '+');
	if (mlx_is_key_down(dt->mlx, MLX_KEY_X))
	{
		if (!dt->b_mouse)
		{
			if (dt->is_mouse == false)
				dt->is_mouse = true;
			else
				dt->is_mouse = false;
			dt->b_mouse = true;
		}
	}
	else
		dt->b_mouse = false;
	(key_up_down(dt), key_left_right(dt), ft_mouse_hook(dt));
}

void	start_game(t_data *data)
{
	init_player(data);
	data->mlx = mlx_init(S_W, S_H, "CUB3D", false);
	if (!data->mlx)
		ft_exit(data, "Error\ninitializing window");
	data->img = mlx_new_image(data->mlx, S_W, S_H);
	if (!data->img)
	{
		free (data->mlx);
		ft_exit(data, "Error\ncreating image");
	}
	game_loop(data);
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) == -1)
		ft_exit(data, "failled to push image pixels to window");
	data->weapen_img = mlx_texture_to_image(data->mlx, data->weapen_txt[0]);
	mlx_loop_hook(data->mlx, key_handler, data);
	mlx_loop_hook(data->mlx, doors_hook, data);
	mlx_loop_hook(data->mlx, weapen_hooks, data);
	mlx_close_hook(data->mlx, ft_close, &data);
	mlx_loop(data->mlx);
}
