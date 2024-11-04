/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:45:40 by yakazdao          #+#    #+#             */
/*   Updated: 2024/11/03 10:25:24 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

void	move_player(t_data *dt, double move_x, double move_y)
{
	double	potential_x;
	double	potential_y;

	potential_x = roundf(dt->player->x + move_x);
	potential_y = roundf(dt->player->y + move_y);
	if (!circle_collision(dt, potential_x, dt->player->y))
		dt->player->x = potential_x;
	if (!circle_collision(dt, dt->player->x, potential_y))
		dt->player->y = potential_y;
}

void	ft_close(void	*param)
{
	t_data	*dt;

	dt = (t_data *)param;
	exit(0);
}

void	ft_mlx_put_pixel(t_data *dt, int x, int y, int color)
{
	if (x < 0)
		return ;
	else if (x >= S_W)
		return ;
	if (y < 0)
		return ;
	else if (y >= S_H)
		return ;
	mlx_put_pixel(dt->img, x, y, color);
}

void	apply_shadow(uint32_t *color, t_data *dt)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	double		intensity;

	intensity = 0.9 - (dt->ray->distance / dt->max_distance);
	if (intensity < 0.3)
		intensity = 0.3;
	r = (*color >> 24) & 0xFF;
	g = (*color >> 16) & 0xFF;
	b = (*color >> 8) & 0xFF;
	r *= intensity;
	g *= intensity;
	b *= intensity;
	*color = (r << 24) | (g << 16) | (b << 8) | 0xff;
}

uint32_t	get_texture_pix(t_data *dt)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	uint32_t	a;
	uint32_t	index;

	if (dt->x_offset >= 0 && dt->x_offset < dt->texture->width
		&& dt->y_offset >= 0 && dt->y_offset < dt->texture->height)
	{
		index = (dt->y_offset * dt->texture->width + dt->x_offset) * 4;
		r = dt->texture->pixels[index];
		g = dt->texture->pixels[index + 1];
		b = dt->texture->pixels[index + 2];
		a = dt->texture->pixels[index + 3];
		return (r << 24 | g << 16 | b << 8 | a);
	}
	return (0x000000ff);
}
