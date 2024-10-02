/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:55:03 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/09/30 16:14:41 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void ft_clear_image(mlx_image_t *img)
{
    uint32_t        i;
    uint32_t        j;
    unsigned int    clear;
    
    i = 0;
    clear = 255 << 24 | 255 << 16 | 255 << 8 | 0;
    while (i < img->height)
    {
        j = 0;
        while (j < img->width)
        {
            mlx_put_pixel(img, j, i, clear);
            j++;
        }
        i++;
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

void	ft_close(void *param)
{
	t_data *data;

	data = param;
	mlx_close_window(data->mlx);
	mlx_terminate(data->mlx);
	exit(0);
}

int	ft_mlx_loop(t_params *param)
{
	if (mlx_image_to_window(param->data->mlx,  param->data->img, 0, 0) == -1)
        return (ft_putendl_fd("Error\nputting back image to window failed", 2), 1);
	// init_player(param);
	ft_init_texters(param);
	draw_minimap(param);
	param->data->weapen_img = mlx_texture_to_image(param->data->mlx, param->data->weapen_txt[0]);
	mlx_resize_image(param->data->weapen_img, 375, 400);
	mlx_image_to_window(param->data->mlx, param->data->weapen_img, 600, 600);
	return (0);
}