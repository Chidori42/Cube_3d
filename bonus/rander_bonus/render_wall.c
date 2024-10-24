/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:57:50 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/22 21:47:09 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

t_texture *choice_texture(t_data *dt)
{
    t_texture *tex;

    if (dt->is_door && dt->map[dt->grid_y][dt->grid_x] == 'D')
        tex = dt->door_txt;
    else if (!dt->ray->is_vert)
    {
        if (dt->ray->ray_facing_up)
            tex = dt->pars.north;
        else if (dt->ray->ray_facing_down)
            tex = dt->pars.south;
    }
    else
    {
        if (dt->ray->ray_facing_left)
            tex = dt->pars.west;
        else if (dt->ray->ray_facing_right)
            tex = dt->pars.east;
    }
    return (tex);
}

void draw_wall(t_data *dt, int wall_top_pixel, int wall_bot_pixel, int ray)
{
    uint32_t color;
    float step;
    float tex_pos;
    int y;

    step = (float)dt->texture->height / dt->wall_height;
    tex_pos = (wall_top_pixel - (S_H / 2 - dt->wall_height / 2)) * step;
    y = wall_top_pixel;
    while (y < wall_bot_pixel)
    {
        if (y < 0 || y >= S_H)
            break;
        dt->y_offset = (int)tex_pos % dt->texture->height;
        color = get_texture_pix(dt);
        apply_shadow(&color, dt);
        ft_mlx_put_pixel(dt, ray, y, color);
        tex_pos += step;
        y++;
    }
}

void draw_floor(t_data *dt, int  wall_bot_pixel, int ray)
{
    int y;

    y = wall_bot_pixel;
    while (y < S_H)
    {
        if (y < 0 || y >= S_H || ray < 0 || ray >= S_W)
            break;
        mlx_put_pixel(dt->img, ray, y, dt->pars.floor_color);
        y++;
    }
}

void draw_ceiling(t_data *dt, int  wall_top_pixel, int ray)
{
    int y;

    y = 0;
    while (y < wall_top_pixel)
    {
        if (y < 0 || y >= S_H || ray < 0 || ray >= S_W)
            break;
        mlx_put_pixel(dt->img, ray, y, dt->pars.ceiling_color);
        y++;
    }
}



void render_wall(t_data *dt, int ray)
{
    float   angle_in_rad;
    float   dist_to_proj_plane;
    int     wall_top_pixel;
    int     wall_bot_pixel;
    float   angle_difference;

    angle_difference = normalize_angle(dt->ray->ray_angle - dt->player->rot_angle);
    dt->ray->distance =  dt->ray->distance * cos(angle_difference);
    angle_in_rad = FOV_ANGLE * (M_PI / 180);
    dist_to_proj_plane = (S_W / 2) / tan(angle_in_rad / 2);
    dt->wall_height = dist_to_proj_plane * (TILE_SIZE / dt->ray->distance);
    wall_top_pixel = (S_H / 2) - (dt->wall_height / 2);
    if (wall_top_pixel < 0)
        wall_top_pixel = 0;
    wall_bot_pixel = (S_H / 2) + (dt->wall_height / 2);
    if (wall_bot_pixel > S_H)
        wall_bot_pixel = S_H;
    dt->texture = choice_texture(dt);
    if (dt->ray->is_vert)
        dt->x_offset = (int)(dt->ray->wall_y_hit * dt->texture->width / TILE_SIZE) % dt->texture->width;
    else
        dt->x_offset = (int)(dt->ray->wall_x_hit * dt->texture->width / TILE_SIZE) % dt->texture->width;
    draw_ceiling(dt, wall_top_pixel, ray);
    draw_wall(dt, wall_top_pixel, wall_bot_pixel, ray);
    draw_floor(dt, wall_bot_pixel, ray);
}
