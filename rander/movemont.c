/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movemont.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:42:46 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/30 15:00:36 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void draw_player_circle(t_params *param, int x, int y, int color)
{
    int i, j;
    int r = 7;

    for (i = -r; i <= r; i++)
    {
        for (j = -r; j <= r; j++)
        {
            if (i * i + j * j <= r * r)
            {
                int px = x + i;
                int py = y + j;
				mlx_put_pixel(param->data->img, px, py, color);
            }
        }
    }
    mlx_put_pixel(param->data->img, x, y, 0x000FFF);
}

// static void move_player(t_params *param)
// {
// 	mlx_delete_image(param->data->mlx, param->data->img);
// 	param->data->img = mlx_new_image(param->data->mlx, param->data->wid * 50, param->data->hei * 50);
//     if (param->data->map[(int)param->player->y][(int)(param->player->x + param->player->dx * MOVE_STEP)] != '1')
//     {
//         param->player->x += param->player->dx * MOVE_STEP;
//         param->player->y += param->player->dy * MOVE_STEP;
//     }
// 	mlx_image_to_window(param->data->mlx, param->data->img, 0, 0);
//     draw_map(param);
//     draw_line(param->data, param->player->x * 50, param->player->y * 50,
//         param->player->x * 50 + param->player->dx * 50, param->player->y * 50 + param->player->dy * 50, 0x00FFFF);
// }


// void key_press(void *p)
// {
//     t_params *param;
//     param = (t_params *)p;

//     if (mlx_is_key_down(param->data->mlx, MLX_KEY_LEFT))
//     {
//         param->player->angle -= MOVE_STEP;
//         if (param->player->angle < 0)
//             param->player->angle += 2 * M_PI;
//         param->player->dx = cos(param->player->angle);
//         param->player->dy = sin(param->player->angle);
//     }
//     else if (mlx_is_key_down(param->data->mlx, MLX_KEY_RIGHT))
//     {
//         param->player->angle += MOVE_STEP;
//         if (param->player->angle > 2 * M_PI)
//             param->player->angle -= 2 * M_PI;
//         param->player->dx = cos(param->player->angle);
//         param->player->dy = sin(param->player->angle);
//     }

//     if (mlx_is_key_down(param->data->mlx, 'W'))
//     {
//         move_player(param);
//     }
//     else if (mlx_is_key_down(param->data->mlx, 'S'))
//     {
//         param->player->dx = -param->player->dx;
//         param->player->dy = -param->player->dy;
//         move_player(param);
//         param->player->dx = cos(param->player->angle);
//         param->player->dy = sin(param->player->angle);
//     }
//     else if (mlx_is_key_down(param->data->mlx, 'D'))
//     {
//         param->player->dx = cos(param->player->angle + M_PI / 2);
//         param->player->dy = sin(param->player->angle + M_PI / 2);
//         move_player(param);
//         param->player->dx = cos(param->player->angle);
//         param->player->dy = sin(param->player->angle);
//     }
//     else if (mlx_is_key_down(param->data->mlx, 'A'))
//     {
//         param->player->dx = cos(param->player->angle - M_PI / 2);
//         param->player->dy = sin(param->player->angle - M_PI / 2);
//         move_player(param);
//         param->player->dx = cos(param->player->angle);
//         param->player->dy = sin(param->player->angle);
//     }

//     if (mlx_is_key_down(param->data->mlx, MLX_KEY_ESCAPE))
//     {
//         ft_free_exit(param);
//         mlx_close_window(param->data->mlx);
//     }
// }

static void move_player(t_params *param)
{
    mlx_delete_image(param->data->mlx, param->data->img);
    param->data->img = mlx_new_image(param->data->mlx, param->data->wid * 50, param->data->hei * 50);

    // Calculate new position based on current direction and step size
    double new_x = param->player->x + param->player->dx * MOVE_STEP;
    double new_y = param->player->y + param->player->dy * MOVE_STEP;

    // Check if the new position is valid
    if (param->data->map[(int)new_y][(int)new_x] != '1')
    {
        param->player->x = new_x;
        param->player->y = new_y;
    }

    mlx_image_to_window(param->data->mlx, param->data->img, 0, 0);
    draw_map(param);
    draw_line(param->data, param->player->x * 50, param->player->y * 50,
              param->player->x * 50 + param->player->dx * 50, param->player->y * 50 + param->player->dy * 50, 0x00FFFF);
}

void key_press(void *p)
{
    t_params *param = (t_params *)p;

    if (mlx_is_key_down(param->data->mlx, MLX_KEY_LEFT))
    {
        param->player->angle -= MOVE_STEP;
        if (param->player->angle < 0)
            param->player->angle += 2 * M_PI;
    }
    else if (mlx_is_key_down(param->data->mlx, MLX_KEY_RIGHT))
    {
        param->player->angle += MOVE_STEP;
        if (param->player->angle > 2 * M_PI)
            param->player->angle -= 2 * M_PI;
    }

    // Update direction vectors based on angle
    param->player->dx = cos(param->player->angle);
    param->player->dy = sin(param->player->angle);

    if (mlx_is_key_down(param->data->mlx, 'W'))
    {
        move_player(param);
    }
    else if (mlx_is_key_down(param->data->mlx, 'S'))
    {
        param->player->dx = -param->player->dx;
        param->player->dy = -param->player->dy;
        move_player(param);
        param->player->dx = cos(param->player->angle);
        param->player->dy = sin(param->player->angle);
    }
    else if (mlx_is_key_down(param->data->mlx, 'D'))
    {
        param->player->dx = cos(param->player->angle + M_PI / 2);
        param->player->dy = sin(param->player->angle + M_PI / 2);
        move_player(param);
        param->player->dx = cos(param->player->angle);
        param->player->dy = sin(param->player->angle);
    }
    else if (mlx_is_key_down(param->data->mlx, 'A'))
    {
        param->player->dx = cos(param->player->angle - M_PI / 2);
        param->player->dy = sin(param->player->angle - M_PI / 2);
        move_player(param);
        param->player->dx = cos(param->player->angle);
        param->player->dy = sin(param->player->angle);
    }

    if (mlx_is_key_down(param->data->mlx, MLX_KEY_ESCAPE))
    {
        ft_free_exit(param);
        mlx_close_window(param->data->mlx);
    }
}
