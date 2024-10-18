/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:57:43 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/18 02:50:03 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub_bonus.h"

float horz_intersection(t_data *dt, float angle)
{
    float x_intercept, y_intercept, x_step, y_step;

    y_intercept = floor(dt->player->y / TILE_SIZE) * TILE_SIZE;
    y_intercept += dt->ray->ray_facing_down ? TILE_SIZE : 0;
    x_intercept = dt->player->x + (y_intercept - dt->player->y) / tan(angle);
    y_step = TILE_SIZE * (dt->ray->ray_facing_up ? -1 : 1);
    x_step = TILE_SIZE / tan(angle);
    if ((dt->ray->ray_facing_left && x_step > 0) || (dt->ray->ray_facing_right && x_step < 0))
        x_step = -x_step;

    float next_horz_x = x_intercept;
    float next_horz_y = y_intercept;

    while (next_horz_x >= 0 && next_horz_x / TILE_SIZE < dt->map_w &&
           next_horz_y >= 0 && next_horz_y / TILE_SIZE < dt->map_h)
    {
        float x_check = next_horz_x;
        float y_check = next_horz_y + (dt->ray->ray_facing_up ? -1 : 0);

        if (find_wall_at(dt, x_check, y_check, dt->map))
            break;
        next_horz_x += x_step;
        next_horz_y += y_step;
    }
    dt->ray->h_wall_x_hit = next_horz_x;
    dt->ray->h_wall_y_hit = next_horz_y;
    return sqrt(pow(dt->player->x - dt->ray->h_wall_x_hit, 2) + pow(dt->player->y - dt->ray->h_wall_y_hit, 2));
}

float vert_intersection(t_data *dt, float angle)
{
    float x_intercept, y_intercept, x_step, y_step;

    x_intercept = floor(dt->player->x / TILE_SIZE) * TILE_SIZE;
    x_intercept += dt->ray->ray_facing_right ? TILE_SIZE : 0;
    y_intercept = dt->player->y + (x_intercept - dt->player->x) * tan(angle);
    x_step = TILE_SIZE * (dt->ray->ray_facing_left ? -1 : 1);
    y_step = TILE_SIZE * tan(angle);
    if ((dt->ray->ray_facing_up && y_step > 0) || (dt->ray->ray_facing_down && y_step < 0))
        y_step = -y_step;

    float next_vert_x = x_intercept;
    float next_vert_y = y_intercept;

    while (next_vert_x >= 0 && next_vert_x / TILE_SIZE < dt->map_w &&
           next_vert_y >= 0 && next_vert_y / TILE_SIZE < dt->map_h)
    {
        float x_check = next_vert_x + (dt->ray->ray_facing_left ? -1 : 0);
        float y_check = next_vert_y;

        if (find_wall_at(dt, x_check, y_check, dt->map))
            break;
        next_vert_x += x_step;
        next_vert_y += y_step;
    }
    dt->ray->v_wall_x_hit = next_vert_x;
    dt->ray->v_wall_y_hit = next_vert_y;
    return sqrt(pow(dt->player->x - dt->ray->v_wall_x_hit, 2) + pow(dt->player->y - dt->ray->v_wall_y_hit, 2));
}

void cast_ray(t_data *dt, float ray_angle, int i)
{
    float   horz_distance;
    float   vert_distance;

    ray_angle = normalize_angle(ray_angle);
    dt->ray->ray_facing_down = ray_angle > 0 && ray_angle < M_PI;
    dt->ray->ray_facing_up = !dt->ray->ray_facing_down;
    dt->ray->ray_facing_right = ray_angle < M_PI / 2 || ray_angle > (3 * M_PI) / 2;
    dt->ray->ray_facing_left = !dt->ray->ray_facing_right;
    horz_distance = horz_intersection(dt, ray_angle);
    vert_distance = vert_intersection(dt, ray_angle);
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
    dt->grid_x = floor(dt->ray->wall_x_hit / TILE_SIZE);
    dt->grid_y = floor(dt->ray->wall_y_hit / TILE_SIZE);
    if (dt->ray->is_vert)
         dt->grid_x =  dt->grid_x + (dt->ray->ray_facing_left ? -1 : 0);
    if (!dt->ray->is_vert)
        dt->grid_y = dt->grid_y + (dt->ray->ray_facing_up ? -1 : 0);
    render_wall(dt, i);
}

void casting_rays(t_data *dt)
{
    int ray_id = 0;

    dt->ray->ray_angle = dt->player->rot_angle - (dt->player->fov_in_rd / 2);
    while (ray_id < dt->num_rays)
    {
        dt->is_door = false;
        cast_ray(dt, dt->ray->ray_angle, ray_id);
        dt->ray->ray_angle += dt->player->fov_in_rd / dt->num_rays;
        ray_id++;
    }
    // exit(0);
}
