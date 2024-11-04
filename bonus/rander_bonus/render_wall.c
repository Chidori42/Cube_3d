/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:57:50 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/11/03 11:53:21 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

void	choice_texture(t_data *dt)
{
	if (dt->is_door && dt->map[dt->grid_y][dt->grid_x] == 'D')
		dt->texture = dt->door_txt;
	else if (!dt->ray->is_vert)
	{
		if (dt->ray->ray_facing_up)
			dt->texture = dt->pars.north;
		else if (dt->ray->ray_facing_down)
			dt->texture = dt->pars.south;
	}
	else
	{
		if (dt->ray->ray_facing_left)
			dt->texture = dt->pars.west;
		else if (dt->ray->ray_facing_right)
			dt->texture = dt->pars.east;
	}
}

void	draw_wall(t_data *dt, int wall_top_pixel, int wall_bot_pixel, int ray)
{
	uint32_t	color;
	int			y;
	float		dist;

	y = wall_top_pixel;
	while (y < wall_bot_pixel)
	{
		if (y < 0 || y >= S_H)
			break ;
		dist = y - (S_H / 2) + (dt->wall_height / 2);
		dt->y_offset = dist * ((float)dt->texture->height / dt->wall_height);
		color = get_texture_pix(dt);
		apply_shadow(&color, dt);
		ft_mlx_put_pixel(dt, ray, y, color);
		y++;
	}
}

void	draw_floor(t_data *dt, int wall_bot_pixel, int ray)
{
	int	y;

	y = wall_bot_pixel;
	while (y < S_H)
	{
		if (y < 0 || y >= S_H || ray < 0 || ray >= S_W)
			break ;
		mlx_put_pixel(dt->img, ray, y, dt->pars.floor_color);
		y++;
	}
}

void	draw_ceiling(t_data *dt, int wall_top_pixel, int ray)
{
	int	y;

	y = 0;
	while (y < wall_top_pixel)
	{
		if (y < 0 || y >= S_H || ray < 0 || ray >= S_W)
			break ;
		mlx_put_pixel(dt->img, ray, y, dt->pars.ceiling_color);
		y++;
	}
}

void	render_wall(t_data *dt, int ray)
{
	float	dist_to_proj_plane;
	int		wall_top_pixel;
	int		wall_bot_pixel;
	float	angle_diff;

	angle_diff = normalize_angle(dt->ray->ray_angle - dt->player->rot_angle);
	dt->ray->distance = dt->ray->distance * cos(angle_diff);
	dist_to_proj_plane = (S_W / 2) / tan(dt->player->fov_in_rd / 2);
	dt->wall_height = dist_to_proj_plane * (TILE_SIZE / dt->ray->distance);
	wall_top_pixel = (S_H / 2) - (dt->wall_height / 2);
	if (wall_top_pixel < 0)
		wall_top_pixel = 0;
	wall_bot_pixel = (S_H / 2) + (dt->wall_height / 2);
	if (wall_bot_pixel > S_H)
		wall_bot_pixel = S_H;
	choice_texture(dt);
	if (!dt->ray->is_vert)
		dt->x_offset = (int)(dt->ray->wall_x_hit * \
			dt->texture->width / TILE_SIZE) % dt->texture->width;
	else
		dt->x_offset = (int)(dt->ray->wall_y_hit * \
			dt->texture->width / TILE_SIZE) % dt->texture->width;
	draw_ceiling(dt, wall_top_pixel, ray);
	draw_wall(dt, wall_top_pixel, wall_bot_pixel, ray);
	draw_floor(dt, wall_bot_pixel, ray);
}
