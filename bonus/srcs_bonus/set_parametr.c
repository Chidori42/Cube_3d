/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_parametr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:42:58 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/15 10:04:32 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

int draw_pixel(mlx_image_t *img, float pixel_size, int a, int b, int color)
{
    int i;
    int j;

    i = 0;
    j = 0;
	while (i < pixel_size)
    {
        j = 0;
        while (j < pixel_size)
        {
            mlx_put_pixel(img, (a  + j), (b + i), color);
            j++;
        }
        i++;
    }
	return (0);
}

void	set_hei_and_wid(t_data *data)
{
	int	j;
	int len;

	j = -1;
	data->map_w = 0;
	data->map_h = 0;
	while (data->map && data->map[++j])
	{
		len = (int)ft_strlen(data->map[j]);
		while (data->map[j][len - 1] == ' ')
			len--;
		if (len > data->map_w)
			data->map_w = len;
	}
	data->map_h = j;
}


void ft_setparam(t_data *data)
{
	data->is_play = false;
	data->is_load = false;
	data->texters = NULL;
	data->colors = NULL;
	data->map = NULL;
	data->ammo = 8;
	data->fram = 0;
	// data->is_door = false;
	data->pars.no = NULL;
	data->pars.so = NULL;
	data->pars.we = NULL;
	data->pars.ea = NULL;
	data->pars.is_c = 0;
	data->pars.is_f = 0;
}
