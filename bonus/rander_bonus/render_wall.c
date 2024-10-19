/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:57:50 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/18 23:37:50 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

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

void    apply_shadow(uint32_t *color, t_data *dt)
{
    uint32_t    r;
    uint32_t    g;
    uint32_t    b;
    double        intensity;

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

uint32_t get_texture_pix(t_data *dt)
{
    uint32_t r;
    uint32_t g;
    uint32_t b;
    uint32_t a;
    uint32_t index;

    if (dt->x_offset >= 0 && dt->x_offset < dt->texture->width && dt->y_offset >= 0 && dt->y_offset < dt->texture->height)
    {
        index = (dt->y_offset * dt->texture->width  + dt->x_offset) * 4;
        r = dt->texture->pixel_data[index];
        g = dt->texture->pixel_data[index + 1];
        b = dt->texture->pixel_data[index + 2];
        a = dt->texture->pixel_data[index + 3];
        return (r << 24 | g << 16 | b << 8 | a); 
    }
    return (0x000000ff);
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

void render_wall(t_data *dt, int ray)
{
    float   angle_in_rad;
    float   actual_slice_height;
    float   dist_to_proj_plane;
    int     wall_top_pixel;
    int     wall_bot_pixel;
   
    float distorted_distance = dt->ray->distance;
    float angle_difference = normalize_angle(dt->ray->ray_angle - dt->player->rot_angle);
    float corrected_distance = distorted_distance * cos(angle_difference);
    dt->ray->distance = corrected_distance;

    angle_in_rad = FOV_ANGLE * (M_PI / 180);
    dist_to_proj_plane = (S_W / 2) / tan(angle_in_rad / 2);

    actual_slice_height = TILE_SIZE;
    dt->wall_height = dist_to_proj_plane * (actual_slice_height / dt->ray->distance);
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
