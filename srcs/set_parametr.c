/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_parametr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:42:58 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/09/22 16:30:24 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

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
	data->map_wid = 0;
	data->map_hei = 0;
	while (data->map && data->map[++j])
	{
		len = (int)ft_strlen(data->map[j]);
		while (is_white_space(data->map[j][len - 1]))
			len--;
		if (len > data->map_wid)
			data->map_wid = len;
	}
	data->map_hei = j;
}

void	init_player(t_params *param)
{
	int	i;
	int	j;

	j = 0;
	param->player->angle = 0.0f;
    param->player->fov = 60.0f;
	param->player->dx = cos(param->player->angle);
	param->player->dy = sin(param->player->angle);
	while (param->data->map && param->data->map[j])
	{
		i = 0;
		while (param->data->map[j][i])
		{
			if (param->data->map[j][i] == 'N' || param->data->map[j][i] == 'S' ||
				param->data->map[j][i] == 'W' || param->data->map[j][i] == 'E')
			{
				param->player->x = (float)i;
				param->player->y = (float)j;
				param->player->p_char = param->data->map[j][i];
			}
			i++;
		}
		j++;
	}
}

void ft_setparam(t_params *param)
{
	param->data->win_width = 1900;
	param->data->win_hei = 1000;
	param->data->texters = NULL;
	param->data->colors = NULL;
	param->data->map = NULL;
	param->pars->no = NULL;
	param->pars->so = NULL;
	param->pars->we = NULL;
	param->pars->ea = NULL;
	param->pars->is_c = 0;
	param->pars->is_f = 0;
	param->menu->check = 0;
}
