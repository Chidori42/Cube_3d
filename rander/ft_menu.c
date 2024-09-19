/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:26:52 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/09/19 14:24:19 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void clear_window(t_data *data)
{
    unsigned int clear = 255 << 24 | 255 << 16 | 255 << 8 | 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1900; j++)
        {
            mlx_put_pixel(data->img, j, i, clear);
        }
    }
}

int ft_push_images(t_data *data, t_menu *menu)
{
    mlx_texture_t *back_texture;
    mlx_texture_t *start_texture;

    start_texture = mlx_load_png("textures/start.png");
    back_texture = mlx_load_png("textures/back.png");
    menu->back_img = mlx_texture_to_image(data->mlx, back_texture);
    menu->start_img = mlx_texture_to_image(data->mlx, start_texture);
    mlx_resize_image(menu->start_img, 100, 100);
    mlx_resize_image(menu->back_img, 400, 700);
    if (mlx_image_to_window(data->mlx, menu->start_img, 900, 200) == -1)
        return (ft_putendl_fd("Error\nputting start image to window failed", 2), 1);
    if (mlx_image_to_window(data->mlx, menu->back_img, 750, 300) == -1)
        return (ft_putendl_fd("Error\nputting back image to window failed", 2), 1);
    mlx_delete_texture(start_texture);
    mlx_delete_texture(back_texture);
    return (0);
}

void ft_menu_loop(t_params *param)
{
    ft_push_images(param->data, param->menu);
}
