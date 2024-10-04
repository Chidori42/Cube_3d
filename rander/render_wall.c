/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:57:50 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/03 21:37:53 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int get_color(t_data *dt, float ray_angle)
{
    ray_angle = normalize_angle(ray_angle);
    if (dt->ray->is_vert)
    {
        if (ray_angle >0 && ray_angle < M_PI)
            return (0xB5B5B5FF);
        else
            return (0xB5B5B5FF);
    }
    else
    {
        if (ray_angle > M_PI / 2 && ray_angle < 3 * (M_PI / 2))
            return (0xF5F5F5FF);
        else
            return (0xF5F5F5FF);
    }
}

void     ft_mlx_put_pixel(t_data *dt, int x, int y, int color)
{
    if (x < 0)
        return ;
    else if (x >= S_W)
        return;
    if (y < 0)
        return;
    else if (y >= S_H)
        return;
    mlx_put_pixel(dt->img, x, y, color);
}
void    draw_wall(t_data *dt, int wall_top_pixel, int wall_bot_pixel, int ray)
{
    int color;

    color = get_color(dt, dt->ray->ray_angle);
    while(wall_top_pixel < wall_bot_pixel)
    {
        ft_mlx_put_pixel(dt, ray, wall_top_pixel, color);
        wall_top_pixel++;
    }
}

void draw_floor(t_data *dt, int wall_bot_pixel, int ray)
{
    int y;

    y = wall_bot_pixel;
    while (y < S_H)
    {
        if (y >= 0 && y < S_H && ray >= 0 && ray < S_W)
            mlx_put_pixel(dt->img, ray, y, dt->pars.floor_color);
        else
            break;
        y++;
    }
}

void draw_ceiling(t_data *dt, int wall_top_pixel, int ray)
{
    int y;

    y = 0;
    while (y < wall_top_pixel)
    {
        if (y >= 0 || y < S_H || ray >= 0 || ray < S_W)
            mlx_put_pixel(dt->img, ray, y, dt->pars.ceiling_color);
        else
            break;
        y++;
    }
}

void    render_wall(t_data *dt, int ray)
{
    float   wall_height;
    float   angle_in_rad;
    float   actual_slice_height;
    float   dist_to_proj_plane;
    int     wall_top_pixel;
    int     wall_bot_pixel;

    float distorted_distance = dt->ray->distance;
    float angle_difference = dt->ray->ray_angle - dt->player->rot_angle;

    float corrected_distance = distorted_distance * cos(angle_difference);
    dt->ray->distance = corrected_distance;
    angle_in_rad = FOV_ANGLE * (M_PI / 180);

    actual_slice_height = TILE_SIZE;
    dist_to_proj_plane = (S_W / 2) / tan(normalize_angle(angle_in_rad / 2));
    wall_height = dist_to_proj_plane * (actual_slice_height / dt->ray->distance);
    wall_top_pixel = (S_H / 2) - (wall_height / 4);
    if (wall_top_pixel < 0)
        wall_top_pixel = 0;
    wall_bot_pixel = (S_H / 2) + (wall_height / 4);
    if (wall_bot_pixel > S_H)
        wall_bot_pixel = S_H;
    draw_wall(dt, wall_top_pixel, wall_bot_pixel, ray);
    draw_floor(dt, wall_bot_pixel, ray);
    draw_ceiling(dt, wall_top_pixel, ray);
}
