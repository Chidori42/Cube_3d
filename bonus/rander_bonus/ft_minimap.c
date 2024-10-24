/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:54:35 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/24 11:24:49 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"


void draw_line(t_data *dt, int x0, int y0, int x1, int y1, int color)
{
	float dx, dy, steps;
	float x_inc, y_inc;
	float x, y;
	int i;

	dx = x1 - x0;
	dy = y1 - y0;
	steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
	x_inc = dx / steps;
	y_inc = dy / steps;
	x = x0;
	y = y0;
	for (i = 0; i <= steps; i++)
	{
		if (x < 0 || y < 0 || x > S_W || y > S_H)
			break ;
		draw_pixel(dt->img, 1, round(x), round(y), color);
		x += x_inc;
		y += y_inc;
	}
}

void minimap_rays(t_data *dt, int minimap_width, int minimap_height)
{
	int		i;
	double	fov_angle;
	double	ray_length;
	double	angle_step;

	ray_length = 30;
	fov_angle = FOV_ANGLE * M_PI / 180.0;
	angle_step = fov_angle / S_W;
	i = 0;
	while (i <= S_W)
	{
		double ray_angle = dt->player->rot_angle - fov_angle / 2.0 + i * angle_step;
		if (ray_angle < 0) ray_angle += 2 * M_PI;
		if (ray_angle > 2 * M_PI) ray_angle -= 2 * M_PI;
		double end_x = 100 + ray_length * cos(ray_angle);
		double end_y = 100 + ray_length * sin(ray_angle);
		draw_line(dt, 100, 100, end_x, end_y, 0xFF00FF);
		i++;
	}
}

void	draw_centered_minimap(t_data *dt, int range, float size, float start_x, float start_y)
{
	float	i;
	float	j;
	float	map_x;
	float	map_y;

	i = 0;
	while (i < range)
	{
		j = 0;
		while (j < range)
		{
			map_x = start_x / TILE_SIZE + j;
			map_y = start_y / TILE_SIZE + i;
			if (map_x > 0 && (int)map_x < dt->map_w && map_y > 0 && (int)map_y < dt->map_h)
			{
				if (dt->map[(int)map_y][(int)map_x] == '1')
					draw_pixel(dt->img, 4, j * size, i * size, 0x00FFFF);
				else if (dt->map[(int)map_y][(int)map_x] == 'D')
					draw_pixel(dt->img, 4, j * size, i * size, 0xFF00FF);
				else
					draw_pixel(dt->img, 4, j * size, i * size, 0x0000FFF);
			}
			else
				draw_pixel(dt->img, 4, j * size, i * size, 0x0000FFF);
			j += 0.1;
		}
		i += 0.1;
	}
	draw_pixel(dt->img, 4, 98, 98, 0x000FFFF);
	minimap_rays(dt, range, range);
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
	draw_centered_minimap(dt, range, size, start_x, start_y);
	return (0);
}
