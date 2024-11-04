/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:16:04 by yakazdao          #+#    #+#             */
/*   Updated: 2024/11/03 09:43:37 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

bool	is_wall(t_data *dt, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / TILE_SIZE);
	map_y = (int)(y / TILE_SIZE);
	if (map_x >= 0 && map_x < dt->map_w && map_y >= 0 && map_y < dt->map_h)
		return (dt->map[map_y][map_x] == '1' || dt->map[map_y][map_x] == 'D');
	return (false);
}

int	circle_collision(t_data *dt, double x, double y)
{
	if (is_wall(dt, x - PLYR_SPEED, y - PLYR_SPEED)
		|| is_wall(dt, x + PLYR_SPEED, y - PLYR_SPEED)
		|| is_wall(dt, x - PLYR_SPEED, y + PLYR_SPEED)
		|| is_wall(dt, x + PLYR_SPEED, y + PLYR_SPEED))
		return (1);
	return (0);
}

void	player_rotation(t_data *dt, char rot_inc)
{
	if (rot_inc == '+')
	{
		dt->player->rot_angle += ROTATION_SPEED;
		dt->player->rot_angle = normalize_angle(dt->player->rot_angle);
	}
	else
	{
		dt->player->rot_angle -= ROTATION_SPEED;
		dt->player->rot_angle = normalize_angle(dt->player->rot_angle);
	}
	game_loop(dt);
}

void	game_loop( t_data *data)
{
	casting_rays(data);
}
