/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:54:35 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/11/03 12:10:43 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

void	minimap_ray(t_data *dt)
{
	double	x;
	double	y;
	int		j;

	x = 100;
	y = 100;
	j = -1;
	while (++j < 30)
	{
		dt->color = 0xFF00FF;
		draw_pixel(dt, 1, x, y);
		x += cos(dt->player->rot_angle);
		y += sin(dt->player->rot_angle);
	}
}

void	ft_minimao_check(t_data *dt, float map_x, float map_y)
{
	dt->color = 0x0000FFF;
	if (map_x >= 0 && (int)map_x < dt->map_w \
		&& map_y >= 0 && (int)map_y < dt->map_h)
	{
		if (dt->map[(int)map_y][(int)map_x] == '1')
			dt->color = 0x00FFFF;
		else if (dt->map[(int)map_y][(int)map_x] == 'D')
			dt->color = 0xFF00FF;
		else
			dt->color = 0x0000FFF;
		draw_pixel(dt, 2.5, dt->mini_j * 25, dt->mini_i * 25);
	}
	else
		draw_pixel(dt, 2.5, dt->mini_j * 25, dt->mini_i * 25);
}

void	ft_minimap(t_data *dt, int range, float start_x, float start_y)
{
	float	map_x;
	float	map_y;

	dt->mini_i = 0;
	while (dt->mini_i < range)
	{
		dt->mini_j = 0;
		while (dt->mini_j < range)
		{
			map_x = start_x / TILE_SIZE + dt->mini_j;
			map_y = start_y / TILE_SIZE + dt->mini_i;
			ft_minimao_check(dt, map_x, map_y);
			dt->mini_j += 0.1;
		}
		dt->mini_i += 0.1;
	}
}

int	draw_minimap(t_data *dt)
{
	int		range;
	float	size;
	float	start_x;
	float	start_y;

	range = 8;
	size = 200 / range;
	start_x = (dt->player->x - ((range / 2) * TILE_SIZE));
	start_y = (dt->player->y - ((range / 2) * TILE_SIZE));
	ft_minimap(dt, range, start_x, start_y);
	dt->color = 0x000FFFF;
	draw_pixel(dt, 4, 98, 98);
	minimap_ray(dt);
	return (0);
}
