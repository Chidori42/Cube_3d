/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:57:50 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/08 04:24:57 by ael-fagr         ###   ########.fr       */
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


void draw_wall(t_data *dt, int wall_top_pixel, int wall_bot_pixel, int ray)
{
    int     wall_height;
    int     texture_y;
    double  texture_pos;
    int     color;
    double  step;

    // Calculate the height of the wall
    wall_height = wall_bot_pixel - wall_top_pixel;

    // Calculate the step to move through the texture vertically
    step = (double)dt->pars.north->height / wall_height;

    // Initial texture position in the texture Y-axis
    texture_pos = (wall_top_pixel - (S_H / 2) + (wall_height / 2)) * step;

    // Loop through each pixel from top to bottom of the wall
    while (wall_top_pixel < wall_bot_pixel)
    {
        // Make sure we are inside screen bounds
        if (wall_top_pixel >= 0 && wall_top_pixel < S_H)
        {
            // Calculate the texture Y coordinate (clamping it within the texture bounds)
            texture_y = (int)texture_pos;
            if (texture_y >= dt->pars.north->height)
                texture_y = dt->pars.north->height - 1;
            else if (texture_y < 0)
                texture_y = 0;

            // Calculate the pixel index in the texture (using ray for X and texture_y for Y)
            unsigned int pixel_index = texture_y * dt->pars.north->width * 4;  // Assuming 4 bytes per pixel (RGBA)
            unsigned int ray_x = ray % dt->pars.north->width; // Make sure the ray stays within texture bounds
            pixel_index += ray_x * 4;

            // Get the RGBA values of the pixel
            unsigned int r = dt->pars.north->pixel_data[pixel_index];
            unsigned int g = dt->pars.north->pixel_data[pixel_index + 1];
            unsigned int b = dt->pars.north->pixel_data[pixel_index + 2];
            // Combine the RGB values into a single color
            color = ft_get_colore(r, g, b);

            // Draw the pixel on the screen
            ft_mlx_put_pixel(dt, ray, wall_top_pixel, color);
        }

        // Move to the next pixel on the wall
        wall_top_pixel++;
        
        // Move texture position down for the next pixel
        texture_pos += step;
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
