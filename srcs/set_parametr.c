/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_parametr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:42:58 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/18 22:58:20 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	set_hei_and_wid(t_data *data, t_pars *args)
{
	int	j;

	j = -1;
	if (!args->map)
	{
		ft_putstr_fd("Error\ninvalid map", 2);
		exit(1);
	}
	while (args->map[++j])
	{
		if ((int)ft_strlen(args->map[j]) > data->wid)
			data->wid = (int)ft_strlen(args->map[j]);
	}
	
	data->hei = j;
}

static void	set_p(t_pars *args)
{
	int	i;
	int	j;

	j = 0;
	while (args->map[j])
	{
		i = 0;
		while (args->map[j][i])
		{
			if (args->map[j][i] == 'N' || args->map[j][i] == 'S' ||
				args->map[j][i] == 'W' || args->map[j][i] == 'E')
			{
				args->x0 = (float)i;
				args->y0 = (float)j;
				args->pa = args->map[j][i];
			}
			i++;
		}
		j++;
	}
}

void init_camera(t_pars *args, t_camera *camera)
{
	camera->posX = args->x0;
	camera->posY = args->y0;
	camera->dirX = args->x0;
	camera->dirY = args->y0;
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
	ft_allocat_memory();
	param->data->hei = 0;
	param->data->wid = 0;
	param->pars->pa = 0;
	param->pars->x0 = 0;
	param->pars->y0 = 0;
	param->pars->no = NULL;
	param->pars->so = NULL;
	param->pars->we = NULL;
	param->pars->ea = NULL;
	param->pars->is_c = 0;
	param->pars->is_f = 0;
	set_hei_and_wid(param->data, param->pars);
	param->pars->x1 = param->data->wid;
	param->pars->y1 = param->data->hei;
	set_p(param->pars);
}
