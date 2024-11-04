/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_parametr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:42:58 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/11/03 12:18:24 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

int	draw_pixel(t_data *dt, float pixel_size, float a, float b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < pixel_size)
	{
		j = 0;
		while (j < pixel_size)
		{
			mlx_put_pixel(dt->img, (a + j), (b + i), dt->color);
			j++;
		}
		i++;
	}
	return (0);
}

void	set_hei_and_wid(t_data *data)
{
	int	j;
	int	len;

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

void	ft_setparam(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	data->pars.north = NULL;
	data->pars.south = NULL;
	data->pars.west = NULL;
	data->pars.east = NULL;
	data->is_play = false;
	data->is_load = false;
	data->is_animate = false;
	data->is_mouse = false;
	data->b_mouse = false;
	data->door_key_pressed = false;
}
