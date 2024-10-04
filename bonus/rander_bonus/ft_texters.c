/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 08:13:11 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/04 20:31:01 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

t_texture   *ft_get_data(char *path)
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
    return (texture);
}

void ft_init_texters(t_params *param)
{
    param->pars->north = ft_get_data(param->pars->no);
    param->pars->south = ft_get_data(param->pars->so);
    param->pars->west = ft_get_data(param->pars->we);
    param->pars->east = ft_get_data(param->pars->ea);
}
