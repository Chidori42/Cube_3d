/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:21:19 by yakazdao          #+#    #+#             */
/*   Updated: 2024/10/28 15:43:45 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

void	open_close_door(t_data *dt)
{
	int		grid_x;
	int		grid_y;
	float	next_x;
	float	next_y;

	next_x = dt->player->x + cos(dt->player->rot_angle) * TILE_SIZE;
	next_y = dt->player->y + sin(dt->player->rot_angle) * TILE_SIZE;
	if ((dt->map[dt->player->y / TILE_SIZE][dt->player->x / TILE_SIZE] == 'D'\
		|| dt->map[dt->player->y / TILE_SIZE][dt->player->x / TILE_SIZE] == 'O')
		&& (dt->map[(int)next_y / TILE_SIZE][(int)next_x / TILE_SIZE] == 'D'\
		|| dt->map[(int)next_y / TILE_SIZE][(int)next_x / TILE_SIZE] == 'O'))
		return ;
	grid_x = (int)floor(next_x / TILE_SIZE);
	grid_y = (int)floor(next_y / TILE_SIZE);
	if (grid_x >= 0 && grid_x < dt->map_w && grid_y >= 0 && grid_y < dt->map_h)
	{
		if (dt->map[grid_y][grid_x] == 'D')
			dt->map[grid_y][grid_x] = 'O';
		else if (dt->map[grid_y][grid_x] == 'O')
			dt->map[grid_y][grid_x] = 'D';
	}
	game_loop(dt);
}

void	doors_hook(void *p)
{
	t_data	*dt;

	dt = (t_data *)p;
	if (mlx_is_key_down(dt->mlx, MLX_KEY_C))
	{
		if (!dt->door_key_pressed)
		{
			open_close_door(dt);
			dt->door_key_pressed = true;
		}
	}
	else
		dt->door_key_pressed = false;
}
