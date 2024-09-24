/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:26:52 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/09/24 21:07:16 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void ft_clear_image(mlx_image_t *img)
{
    unsigned int clear = 255 << 24 | 255 << 16 | 255 << 8 | 0;
    for (uint32_t i = 0; i < img->height; i++)
    {
        for (uint32_t j = 0; j < img->width; j++)
        {
            mlx_put_pixel(img, j, i, clear);
        }
    }
}

void draw_texter(mlx_image_t *img, t_texture   *texter)
{
    int i, j;
    uint32_t color;

    i = 0;
    while (i < texter->height)
    {
        j = 0;
        while (j < texter->width)
        {
            uint32_t r = texter->pixel_data[(i * texter->width + j) * 4];
            uint32_t g = texter->pixel_data[(i * texter->width + j) * 4 + 1];
            uint32_t b = texter->pixel_data[(i * texter->width + j) * 4 + 2];
            color = ft_get_colore(r, g, b);
            mlx_put_pixel(img, j, i, color);
            j++;
        }
        i++;
    }
}

int ft_push_menu(t_data *data, t_menu *menu)
{
    menu->back_tex = ft_get_data("textures/menu_back.png");
    draw_texter(data->img, menu->back_tex);
    return (0);
}
