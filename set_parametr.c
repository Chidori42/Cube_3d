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

void	set_hei_and_wid(t_data *args)
{
	int	j;

	j = -1;
	args->hei = 0;
	args->wid = 0;
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

void	set_p(t_data *args)
{
	int	i;
	int	j;

	j = 0;
	args->x1 = args->wid;
	args->y1 = args->hei;
	args->pa = 0;
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
