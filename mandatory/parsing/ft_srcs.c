/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srcs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:07:16 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/09/28 11:26:32 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ft_get_colore(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

void	ft_set_colore(t_pars *args)
{
	args->floor_color = ft_get_colore(args->f[0], args->f[1], args->f[2]);
	args->ceiling_color = ft_get_colore(args->c[0], args->c[1], args->c[2]);
}

int	ft_get_map(t_data *data, char *map)
{
	int	i;

	i = 0;
	if (!map)
		return (ft_putendl_fd("Error\nNO map in file", 2), 1);
	data->map = ft_split(map, '\n');
	if (!data->map)
		return (ft_putendl_fd("Error\nmalloc fail", 2), 1);
	set_hei_and_wid(data);
	data->map = ft_add_spaces(data, data->map);
	if (!data->map)
		return (ft_putendl_fd("Error\nmalloc fail", 2), 1);
	return (0);
}

int	ft_check_digit(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ')
			return (1);
	}
	return (0);
}
