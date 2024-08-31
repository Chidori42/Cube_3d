/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_parametr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:42:58 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/29 18:24:33 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	set_hei_and_wid(t_data *data)
{
	int	j;

	j = -1;
	if (!data->map)
	{
		ft_putstr_fd("Error\ninvalid map", 2);
		exit(1);
	}
	data->wid = 0;
	data->hei = 0;
	while (data->map[++j])
	{
		if ((int)ft_strlen(data->map[j]) > data->wid)
			data->wid = (int)ft_strlen(data->map[j]);
	}
	
	data->hei = j;
}

static void	init_player(t_params *param)
{
	int	i;
	int	j;

	j = 0;
	param->player->angle = 0.0f;
    param->player->fov = 60.0f;
	param->player->dx = cos(param->player->angle);
	param->player->dy = sin(param->player->angle);
	while (param->data->map[j])
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

int init_mlx(t_data *data)
{
	data->mlx = mlx_init(data->wid * 50, data->hei * 50, "cub3D", true);
	data->img = mlx_new_image(data->mlx, data->wid * 50, data->hei * 50);
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) == -1
		|| !data->mlx || !data->img)
	{
		mlx_close_window(data->mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	return (0);
}

void ft_setparam(t_params *param)
{
	param->pars->no = NULL;
	param->pars->so = NULL;
	param->pars->we = NULL;
	param->pars->ea = NULL;
	param->pars->is_c = 0;
	param->pars->is_f = 0;
	init_player(param);
}
