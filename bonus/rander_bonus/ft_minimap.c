/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:54:35 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/29 22:34:10 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

void minimap_rays(t_data *dt, int minimap_width, int minimap_height)
{
    int		i;
    double	angle_step;
	double	x;
	double	y;
    int		j;

	i = -1;
	angle_step = dt->player->fov_in_rd / S_W;
    while (++i < S_W)
    {
        dt->min_angle = dt->player->rot_angle - dt->player->fov_in_rd / 2 + i * angle_step;
        if (dt->min_angle  < 0)
			dt->min_angle  += 2 * M_PI;
        if (dt->min_angle  > 2 * M_PI)
			dt->min_angle  -= 2 * M_PI;
		x = 100;
        y = 100;
		j = -1;
        while (++j < 30)
        {
            draw_pixel(dt->img, 1,  x, y, 0xFF00FF);
            x += cos(dt->min_angle );
            y += sin(dt->min_angle );
        }
    }
}


void	draw_centered_minimap(t_data *dt, int range, float start_x, float start_y)
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
			if (map_x >= 0 && (int)map_x < dt->map_w && map_y >= 0 && (int)map_y < dt->map_h)
			{
				if (dt->map[(int)map_y][(int)map_x] == '1')
					draw_pixel(dt->img, 2.5, j * 25, i * 25, 0x00FFFF);
				else if (dt->map[(int)map_y][(int)map_x] == 'D')
					draw_pixel(dt->img, 2.5, j * 25, i * 25, 0xFF00FF);
				else
					draw_pixel(dt->img, 2.5, j * 25, i * 25, 0x0000FFF);
			}
			else
				draw_pixel(dt->img, 2.5, j * 25, i * 25, 0x0000FFF);
			j += 0.1;
		}
		i += 0.1;
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
	start_x = (dt->player->x  - ((range / 2) * TILE_SIZE));
	start_y = (dt->player->y - ((range / 2) * TILE_SIZE));
	draw_centered_minimap(dt, range, start_x, start_y);
	draw_pixel(dt->img, 4, 98, 98, 0x000FFFF);
	minimap_rays(dt, range, range);
	return (0);
}
