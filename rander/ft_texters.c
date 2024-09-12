/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 08:13:11 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/09/12 09:57:43 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void ft_init_texters(t_params *param, t_texture *texture, char *path)
{
    mlx_texture_t *img;
    img = mlx_load_png(path);
    texture->height = img->height;
    texture->width = img->width;
    texture->pixel_data = img->pixels;
    printf("height: %d\n", texture->height);
    printf("width: %d\n", texture->width);
    for (int y = 0; y < texture->height; y++)
    {
        for (int x = 0; x < texture->width; x++)
        {
            unsigned int pixel_index = (y * texture->width + x) * 4;
            unsigned int r = texture->pixel_data[pixel_index];
            unsigned int g = texture->pixel_data[pixel_index + 1];
            unsigned int b = texture->pixel_data[pixel_index + 2];
            unsigned int a = texture->pixel_data[pixel_index + 3];
            int color = a << 24 | r << 16 | g << 8 | b;
            printf("Pixel at (%u, %u): color = %d \n", x, y, color);
            draw_pixel(param->data->img, 3, x * 3, y * 3, color);
        }
    }
}