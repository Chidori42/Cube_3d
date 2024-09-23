/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movemont.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:42:46 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/09/23 13:29:33 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void draw_player_circle(mlx_image_t *img, float x, float y, int size, int color)
{
    int i, j;
    int r = size / 2;

    for (i = -r; i < r; i++)
    {
        for (j = -r; j < r; j++)
        {
            if (i * i + j * j <= r * r)
                draw_pixel(img, 1, x + i, y + j, color);
        }
    }
    mlx_put_pixel(img, x, y, 0x00FF00);
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
    if (draw_minimap(param) != 0)
        ft_free_exit(param);
}

void key_press(void *p)
{
    t_params *param = (t_params *)p;


    if (mlx_is_key_down(param->data->mlx, MLX_KEY_ESCAPE))
    {
        ft_free_exit(param);
        mlx_close_window(param->data->mlx);
    }
    if (param->menu->check == 0)
    {
     if (mlx_is_key_down(param->data->mlx, MLX_KEY_ENTER))
    {
        ft_clear_image(param->data->img);
        param->menu->check = 1;
        ft_mlx_loop(param);
    }
    }
    else{
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
    }
}
