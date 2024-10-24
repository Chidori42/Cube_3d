/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:58:00 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/23 14:36:18 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void move_player(t_data *dt, double move_x, double move_y)
{
    double potential_x;
    double potential_y;

    potential_x = roundf(dt->player->x + move_x);
    potential_y = roundf(dt->player->y + move_y);
    if (!circle_collision(dt, potential_x, dt->player->y))
        dt->player->x = potential_x;
    if (!circle_collision(dt, dt->player->x, potential_y))
        dt->player->y = potential_y;
}

void    key_up_down(t_data *dt)
{
    double  new_x;
    double  new_y;

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

void    key_left_right(t_data *dt)
{
    double  new_x;
    double  new_y;

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

void key_handler(void *param)
{
    t_data *dt;

    dt = (t_data *)param;
    if (mlx_is_key_down(dt->mlx, MLX_KEY_ESCAPE))
    {
        free_render_allocation(dt);
        exit(0);
    }
    if (mlx_is_key_down(dt->mlx, MLX_KEY_LEFT))
        player_rotation(dt, '-');
    else if (mlx_is_key_down(dt->mlx, MLX_KEY_RIGHT))
        player_rotation(dt, '+');
    key_up_down(dt);
    key_left_right(dt);
}

void start_game(t_data *data)
{
    init_player(data);
    data->mlx = mlx_init(S_W, S_H, "CUB3D", true);
    if (!data->mlx)
    {
        perror("Error initializing window");
        ft_free_exit(data);
    }
    data->img = mlx_new_image(data->mlx, S_W, S_H);
    if (!data->img)
    {
        perror("Error creating image");
        exit(1) ;
    }
    game_loop(data);
    mlx_image_to_window(data->mlx, data->img, 0, 0);
	mlx_loop_hook(data->mlx,  key_handler, data);
	mlx_loop(data->mlx);
}