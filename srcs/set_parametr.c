/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_parametr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:42:58 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/22 10:32:30 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	set_hei_and_wid(t_data *data, t_pars *args)
{
	int i;
	int len;

	i = 0;
	if (!args->map)
	{
		ft_putstr_fd("Error\ninvalid map", 2);
		exit(1);
	}
	while (args->map[i])
	{
		len = ft_strlen(args->map[i]) - 1;
		while (is_white_space(args->map[i][len]))
			len--;
		if (len > data->wid)
			data->wid = len;
		i++;
	}
	data->hei = i;
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
				args->x = (float)i;
				args->y = (float)j;
				args->pa = args->map[j][i];
			}
			i++;
		}
		j++;
	}
}

void ft_setparam(t_params *param)
{
	param->data->hei = 0;
	param->data->wid = 0;
	param->pars->pa = 0;
	param->pars->x = 0;
	param->pars->y = 0;
	param->pars->dx = 0;
	param->pars->dy = 0;
	param->pars->theta = 0;
	param->pars->no = NULL;
	param->pars->so = NULL;
	param->pars->we = NULL;
	param->pars->ea = NULL;
	param->pars->is_c = 0;
	param->pars->is_f = 0;
	set_hei_and_wid(param->data, param->pars);
	set_p(param->pars);
}
