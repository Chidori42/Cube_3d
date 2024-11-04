/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_parametr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:42:58 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/11/03 12:02:35 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

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
	data->texters = NULL;
	data->colors = NULL;
	data->map = NULL;
	data->pars.no = NULL;
	data->pars.so = NULL;
	data->pars.we = NULL;
	data->pars.ea = NULL;
	data->pars.is_c = 0;
	data->pars.is_f = 0;
}
