/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:14:41 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/24 14:59:28 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

float	normalize_angle(float ray_angle)
{
	if (ray_angle < 0)
		ray_angle += (2 * M_PI);
	if (ray_angle > (2 * M_PI))
		ray_angle -= (2 * M_PI);
	return (ray_angle);
}

void	init_player(t_data *dt)
{
	dt->player->x = dt->p_x_pos_in_map * TILE_SIZE + TILE_SIZE / 2;
	dt->player->y = dt->p_y_pos_in_map * TILE_SIZE + TILE_SIZE / 2;
	dt->player->fov_in_rd = (FOV_ANGLE * M_PI) / 180;
	if (dt->map[dt->p_y_pos_in_map][dt->p_x_pos_in_map] == 'W')
		dt->player->rot_angle = M_PI;
	else if (dt->map[dt->p_y_pos_in_map][dt->p_x_pos_in_map] == 'N')
		dt->player->rot_angle = (3 * M_PI) / 2;
	else if (dt->map[dt->p_y_pos_in_map][dt->p_x_pos_in_map] == 'E')
		dt->player->rot_angle = 0;
	else if (dt->map[dt->p_y_pos_in_map][dt->p_x_pos_in_map] == 'S')
		dt->player->rot_angle = M_PI / 2;
}

bool	find_wall_at(t_data *dt, int x, int y, char **grid)
{
	int	grid_x;
	int	grid_y;

	grid_x = floor(x / TILE_SIZE);
	grid_y = floor(y / TILE_SIZE);
	if (grid_x < 0 || grid_x >= dt->map_w || grid_y < 0 || grid_y >= dt->map_h)
		return (false);
	return (grid[grid_y][grid_x] == '1' || grid[grid_y][grid_x] == 'D');
}

void	get_player_pos(char **grid, t_data *dt)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == 'E' || grid[i][j] == 'S'
				|| grid[i][j] == 'N' || grid[i][j] == 'W')
			{
				dt->p_y_pos_in_map = i;
				dt->p_x_pos_in_map = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_data(t_data *dt)
{
	dt->player = calloc(1, sizeof(t_player));
	dt->ray = calloc(1, sizeof(t_ray));
	get_player_pos(dt->map, dt);
	dt->num_rays = S_W;
	dt->max_distance = 500.0f;
}
