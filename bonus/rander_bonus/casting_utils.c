/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:13:03 by yakazdao          #+#    #+#             */
/*   Updated: 2024/11/03 08:59:38 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

void	ft_exit(t_data *dt, char *err_msg)
{
	int	i;

	i = 0;
	perror(err_msg);
	free(dt->player);
	free(dt->ray);
	mlx_delete_texture(dt->door_txt);
	mlx_delete_texture(dt->pars.north);
	mlx_delete_texture(dt->pars.south);
	mlx_delete_texture(dt->pars.west);
	mlx_delete_texture(dt->pars.east);
	if (dt->weapen_img)
		mlx_delete_image(dt->mlx, dt->weapen_img);
	while (i < 329)
	{
		mlx_delete_texture(dt->weapen_txt[i]);
		i++;
	}
	ft_free_exit(dt);
}

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
