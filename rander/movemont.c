/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movemont.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:42:46 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/01 13:20:00 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void draw_player_circle(mlx_image_t *img, float x, float y, int size, int color)
{
    int i;
    int j;
    int r;

    r = size / 2;
    i = -r;
    while (i < r)
    {
        j = -r;
        while (j < r)
        {
            if (i * i + j * j <= r * r)
                draw_pixel(img, 1, x + i, y + j, color);
            j++;
        }
        i++;
    }
    mlx_put_pixel(img, x, y, 0x00FF00);
}

int get_pixel_color (t_texture *texture, int x, int y)
{
    int color;
    unsigned char *color_ptr;

    color_ptr = texture->pixel_data + (y * texture->width + x) * 4;
    color = color_ptr[0] << 24 | color_ptr[1] << 16 | color_ptr[2] << 8 | color_ptr[3];
    return (color);
}

static void move_player(t_params *param, int m)
{
    ft_clear_image(param->data->img);
    double new_x = param->player->x + param->player->dx * MOVE_STEP;
    double new_y = param->player->y + param->player->dy * MOVE_STEP;
    if (param->data->map[(int)new_y][(int)new_x] != '1' && m)
    {
        param->player->x = new_x;
        param->player->y = new_y;
    }
    draw_minimap(param);
}


void key_press(void *p)
{
    t_params *param = (t_params *)p;


    if (mlx_is_key_down(param->data->mlx, MLX_KEY_ESCAPE))
    {
        ft_free_exit(param);
        mlx_close_window(param->data->mlx);
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
}
