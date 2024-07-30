/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_parametr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:42:58 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/07/24 04:16:27 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	set_hei_and_wid(t_data *args)
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
		if ((int)ft_strlen(args->map[j]) > args->wid)
			args->wid = (int)ft_strlen(args->map[j]);
	}
	
	args->hei = j;
}

static void	set_p(t_data *args)
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

void ft_setparam(t_data *args)
{
	args->hei = 0;
	args->wid = 0;
	args->pa = 0;
	args->x0 = 0;
	args->y0 = 0;
	args->no = NULL;
	args->so = NULL;
	args->we = NULL;
	args->ea = NULL;
	args->is_c = 0;
	args->is_f = 0;
	set_hei_and_wid(args);
	args->x1 = args->wid;
	args->y1 = args->hei;
	set_p(args);
}