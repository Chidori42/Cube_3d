/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srcs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:07:16 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/22 15:57:33 by yakazdao         ###   ########.fr       */
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

int	check_valid_color(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if ((str[i] == ',' && str[i + 1] == ',')
			|| (str[i] == ',' && str[i + 1] == '\0'))
			return (ft_putendl_fd("Error\ninvalid color identify", 2), 1);
		i++;
	}
	return (0);
}

static int	check_valid_map(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_get_map(t_data *data, char *map)
{
	int	i;

	i = 0;
	if (!map)
		return (ft_putendl_fd("Error\nNO map in file", 2), 1);
	if (check_valid_map(map))
		return (ft_putendl_fd("Error\nInvalid map", 2), 1);
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
