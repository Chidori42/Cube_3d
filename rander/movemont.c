/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movemont.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:42:46 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/09/14 08:19:02 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void draw_player_circle(t_params *param, float x, float y, int size, int color)
{
    int i, j;
    int r = size / 2;

    for (i = -r; i < r; i++)
    {
        for (j = -r; j < r; j++)
        {
            if (i * i + j * j <= r * r)
                draw_pixel(param->data->img, 1, x + i, y + j, color);
        }
    }
    mlx_put_pixel(param->data->img, x, y, 0x00FF00);
}

int count_dis_to_wall(t_data *data, int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1; 
    int err = dx - dy;
    int e2;
    int hei = 0;

    while (1)
    {
        if (data->map[y0 / 50][x0 / 50] == '1')
            break;
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
        hei++;
    }
    return (hei);
}
int get_pixel_color (t_texture *texture, int x, int y)
{
    int color;
    unsigned char *color_ptr;

    color_ptr = texture->pixel_data + (y * texture->width + x) * 4;
    color = color_ptr[0] << 24 | color_ptr[1] << 16 | color_ptr[2] << 8 | color_ptr[3];
    return (color);
}

void ft_rander_map(t_params *param)
{
    double  player_x;
    double  player_y;
    double  fov_angle;
    double  line_length; 
    int     num_rays;
    double  angle_step;

    player_x = param->player->x * 50;
    player_y = param->player->y * 50;
    fov_angle = 60 * M_PI / 180.0;
    num_rays = param->data->wid * 50;
    line_length = param->data->wid * 50;
    angle_step = fov_angle / num_rays;
    for (int i = 0; i <= num_rays; i++)
    {
        double ray_angle = param->player->angle - fov_angle / 2.0 + i * angle_step;
        double end_x = player_x + line_length * cos(ray_angle);
        double end_y = player_y + line_length * sin(ray_angle);
        double dis_to_wall = count_dis_to_wall(param->data, player_x, player_y, end_x, end_y);
        double wall_height = 64 / dis_to_wall * 277;
        double wall_start = param->data->hei * 50 / 2 - wall_height / 2;
        double wall_end = param->data->hei * 50 / 2 + wall_height / 2;
        for (int y = wall_start; y < wall_end; y++)
        {
            if (y < 0 || y >= param->data->hei * 50)
                continue;
            mlx_put_pixel(param->data->img, i, y, 0x00FF00FF);
        }
    }
}

static void move_player(t_params *param, int m)
{
    unsigned int clear = 255 << 24 | 255 << 16 | 255 << 8 | 0;
    for (int i = 0; i < param->data->hei * 50; i++)
    {
        for (int j = 0; j < param->data->wid * 50; j++)
        {
            mlx_put_pixel(param->data->img, j, i, clear);
        }
    }
    double new_x = param->player->x + param->player->dx * MOVE_STEP;
    double new_y = param->player->y + param->player->dy * MOVE_STEP;
    if (param->data->map[(int)new_y][(int)new_x] != '1' && m)
    {
        param->player->x = new_x;
        param->player->y = new_y;
    }
    // draw_map(param);
    ft_rander_map(param);
    draw_minimap(param);
}

void key_press(void *p)
{
    t_params *param = (t_params *)p;

    if (mlx_is_key_down(param->data->mlx, MLX_KEY_LEFT))
    {
        param->player->angle -= MOVE_STEP;
        if (param->player->angle < 0)
            param->player->angle += 2 * M_PI;
        move_player(param, 0);
    }
    if (mlx_is_key_down(param->data->mlx, MLX_KEY_RIGHT))
    {
        param->player->angle += MOVE_STEP;
        if (param->player->angle > 2 * M_PI)
            param->player->angle -= 2 * M_PI;
        move_player(param, 0);
    }

    param->player->dx = cos(param->player->angle);
    param->player->dy = sin(param->player->angle);

    if (mlx_is_key_down(param->data->mlx, 'W'))
    {
        move_player(param, 1);
    }
    if (mlx_is_key_down(param->data->mlx, 'S'))
    {
        param->player->dx = -param->player->dx;
        param->player->dy = -param->player->dy;
        move_player(param, 1);
        param->player->dx = cos(param->player->angle);
        param->player->dy = sin(param->player->angle);
    }
    if (mlx_is_key_down(param->data->mlx, 'D'))
    {
        param->player->dx = cos(param->player->angle + M_PI / 2);
        param->player->dy = sin(param->player->angle + M_PI / 2);
        move_player(param, 1);
        param->player->dx = cos(param->player->angle);
        param->player->dy = sin(param->player->angle);
    }
    if (mlx_is_key_down(param->data->mlx, 'A'))
    {
        param->player->dx = cos(param->player->angle - M_PI / 2);
        param->player->dy = sin(param->player->angle - M_PI / 2);
        move_player(param, 1);
        param->player->dx = cos(param->player->angle);
        param->player->dy = sin(param->player->angle);
    }

    if (mlx_is_key_down(param->data->mlx, MLX_KEY_ESCAPE))
    {
        ft_free_exit(param);
        mlx_close_window(param->data->mlx);
    }
}
