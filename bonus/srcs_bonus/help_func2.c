/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:16:04 by yakazdao          #+#    #+#             */
/*   Updated: 2024/10/24 14:23:52 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

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

void	ft_clear_image(mlx_image_t *img)
{
	uint32_t		i;
	uint32_t		j;
	unsigned int	clear;

	i = 0;
	clear = 255 << 24 | 255 << 16 | 255 << 8 | 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{
			mlx_put_pixel(img, j, i, clear);
			j++;
		}
		i++;
	}
}

void	player_rotation(t_data *dt, char rot_inc)
{
	if (rot_inc == '+')
	{
		dt->player->rot_angle += ROTATION_SPEED;
		if (dt->player->rot_angle > 2 * M_PI)
			dt->player->rot_angle -= 2 * M_PI;
	}
	else
	{
		dt->player->rot_angle -= ROTATION_SPEED;
		if (dt->player->rot_angle < 0)
			dt->player->rot_angle += 2 * M_PI;
	}
	game_loop(dt);
}

void	game_loop( t_data *data)
{
	casting_rays(data);
	draw_minimap(data);
}
