/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:00:26 by yakazdao          #+#    #+#             */
/*   Updated: 2024/10/27 02:49:09 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void ft_exit(t_data *dt , char *err_msg)
{
	perror(err_msg);
	free(dt->player);
	free(dt->ray);
	ft_free_exit(dt);
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
		r = dt->texture->pixel_data[index];
		g = dt->texture->pixel_data[index + 1];
		b = dt->texture->pixel_data[index + 2];
		a = dt->texture->pixel_data[index + 3];
		return (r << 24 | g << 16 | b << 8 | a);
	}
	return (0x000000ff);
}
