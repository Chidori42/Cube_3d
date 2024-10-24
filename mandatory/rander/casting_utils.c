/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:52:57 by yakazdao          #+#    #+#             */
/*   Updated: 2024/10/24 15:09:38 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

#include "../cub.h"

void	get_ray_facing(t_data *dt, float ray_angle)
{
	dt->ray->ray_facing_down = ray_angle > 0 && ray_angle < M_PI;
	dt->ray->ray_facing_up = !dt->ray->ray_facing_down;
	dt->ray->ray_facing_right = ray_angle < M_PI / 2
		|| ray_angle > (3 * M_PI) / 2;
	dt->ray->ray_facing_left = !dt->ray->ray_facing_right;
}

void	compare_ray_dis(t_data *dt, float horz_distance, float vert_distance)
{
	dt->ray->is_vert = vert_distance < horz_distance;
	if (dt->ray->is_vert)
	{
		dt->ray->distance = vert_distance;
		dt->ray->wall_x_hit = dt->ray->v_wall_x_hit;
		dt->ray->wall_y_hit = dt->ray->v_wall_y_hit;
	}
	else
	{
		dt->ray->distance = horz_distance;
		dt->ray->wall_x_hit = dt->ray->h_wall_x_hit;
		dt->ray->wall_y_hit = dt->ray->h_wall_y_hit;
	}
}
