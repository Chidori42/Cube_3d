/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:57:43 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/23 14:13:51 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

float horz_intersection(t_data *dt, float angle)
{
    dt->y_intercept = floor(dt->player->y / TILE_SIZE) * TILE_SIZE;
    if (dt->ray->ray_facing_down)
        dt->y_intercept += TILE_SIZE;
    dt->x_intercept = dt->player->x + (dt->y_intercept - dt->player->y) / tan(angle);
    dt->y_step = TILE_SIZE;
    if (dt->ray->ray_facing_up)
        dt->y_step *= -1;
    dt->x_step = TILE_SIZE / tan(angle);
    if ((dt->ray->ray_facing_left && dt->x_step > 0) || (dt->ray->ray_facing_right && dt->x_step < 0))
        dt->x_step = -dt->x_step;
    while (dt->x_intercept >= 0 && dt->x_intercept / TILE_SIZE < dt->map_w &&
           dt->y_intercept >= 0 && dt->y_intercept / TILE_SIZE < dt->map_h)
    {
        dt->x_check = dt->x_intercept;
        dt->y_check = dt->y_intercept;
        if (dt->ray->ray_facing_up)
            dt->y_check -= 1;
        if (find_wall_at(dt, dt->x_check, dt->y_check, dt->map))
            break;
        dt->x_intercept += dt->x_step;
        dt->y_intercept += dt->y_step;
    }
    dt->ray->h_wall_x_hit = dt->x_intercept;
    dt->ray->h_wall_y_hit = dt->y_intercept;
    return sqrt(pow(dt->player->x - dt->ray->h_wall_x_hit, 2) + pow(dt->player->y - dt->ray->h_wall_y_hit, 2));
}

float vert_intersection(t_data *dt, float angle)
{
    dt->x_intercept = floor(dt->player->x / TILE_SIZE) * TILE_SIZE;
    if (dt->ray->ray_facing_right)
        dt->x_intercept += TILE_SIZE;
    dt->y_intercept = dt->player->y + (dt->x_intercept - dt->player->x) * tan(angle);
    dt->x_step = TILE_SIZE;
    if (dt->ray->ray_facing_left)
        dt->x_step *= -1;
    dt->y_step = TILE_SIZE * tan(angle);
    if ((dt->ray->ray_facing_up && dt->y_step > 0) || (dt->ray->ray_facing_down && dt->y_step < 0))
        dt->y_step = -dt->y_step;
    while (dt->x_intercept >= 0 && dt->x_intercept / TILE_SIZE < dt->map_w &&
           dt->y_intercept >= 0 && dt->y_intercept / TILE_SIZE < dt->map_h)
    {
        dt->x_check = dt->x_intercept;
        if (dt->ray->ray_facing_left)
            dt->x_check -= 1;
        dt->y_check = dt->y_intercept;
        if (find_wall_at(dt, dt->x_check, dt->y_check, dt->map))
            break;
        dt->x_intercept += dt->x_step;
        dt->y_intercept += dt->y_step;
    }
    dt->ray->v_wall_x_hit = dt->x_intercept;
    dt->ray->v_wall_y_hit = dt->y_intercept;
    return sqrt(pow(dt->player->x - dt->ray->v_wall_x_hit, 2) + pow(dt->player->y - dt->ray->v_wall_y_hit, 2));
}



void cast_ray(t_data *dt, float ray_angle, int i)
{
    float   horz_distance;
    float   vert_distance;

    ray_angle = normalize_angle(ray_angle);
    get_ray_facing(dt, ray_angle);
    horz_distance = horz_intersection(dt, ray_angle);
    vert_distance = vert_intersection(dt, ray_angle);
    compare_ray_dis(dt, horz_distance, vert_distance);
    dt->grid_x = floor(dt->ray->wall_x_hit / TILE_SIZE);
    dt->grid_y = floor(dt->ray->wall_y_hit / TILE_SIZE);
    if (dt->ray->is_vert)
    {
        if (dt->ray->ray_facing_left)
            dt->grid_x -= 1;
    }
    if (!dt->ray->is_vert)
    {
        if (dt->ray->ray_facing_up)
            dt->grid_y -= 1;
    }
    render_wall(dt, i);
}

void casting_rays(t_data *dt)
{
    int ray_id = 0;

    dt->ray->ray_angle = dt->player->rot_angle - (dt->player->fov_in_rd / 2);
    while (ray_id < dt->num_rays)
    {
        cast_ray(dt, dt->ray->ray_angle, ray_id);
        dt->ray->ray_angle += dt->player->fov_in_rd / dt->num_rays;
        ray_id++;
    }
}
