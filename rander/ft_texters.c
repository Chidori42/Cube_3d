/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 08:13:11 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/09/13 09:12:36 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static t_texture   *ft_get_data(char *path)
{
    mlx_texture_t *img;
    t_texture *texture;
    
    texture = malloc(sizeof(t_texture));
    if (!texture)
        return (ft_putendl_fd("Error\nmalloc failed", 2), NULL);
    img = mlx_load_png(path);
    if (!img)
        return (ft_putendl_fd("Error\nloading texture failed", 2), NULL);
    texture->height = img->height;
    texture->width = img->width;
    texture->pixel_data = img->pixels;
    printf("height: %d\n", texture->height);
    printf("width: %d\n", texture->width);
    return (texture);
}

void ft_init_texters(t_params *param)
{
    param->pars->north = ft_get_data(param->pars->no);
    for (int i = 0; i < param->pars->north->height; i++)
    {
        for (int j = 0; j < param->pars->north->width; j++)
        {
            int pixel_index = (i * param->pars->north->width + j) * 4;
            unsigned int r = param->pars->north->pixel_data[pixel_index];
            unsigned int g = param->pars->north->pixel_data[pixel_index + 1];
            unsigned int b = param->pars->north->pixel_data[pixel_index + 2];
            unsigned int a = param->pars->north->pixel_data[pixel_index + 3];
            uint32_t color = (r << 24) | (g << 16) | (b << 8) | a;
            mlx_put_pixel(param->data->img, j, i, color);
        }
    }
}
