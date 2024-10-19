/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_borders.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 00:25:54 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/19 23:58:22 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

static	int	check_right_side(char **map)
{
	int	j;
	int	len;

	j = 0;
	while (map[j])
	{
		len = ft_strlen(map[j]);
		if (len > 0 && (map[j][len - 1] != '1' && map[j][len - 1] != ' '))
		{
			ft_putendl_fd("\x1b[31mError\ninvalid right border\033[0m", 2);
			return (1);
		}
		j++;
	}
	return (0);
}

static	int	check_left_side(char **map)
{
	int	j;
	int	i;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ' && map[i][j])
			j++;
		if (map[i][j] != '1')
		{
			ft_putendl_fd("\x1b[31mError\ninvalid left border\033[0m", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_top_side(char **map)
{
	int	j;

	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1' && map[0][j] != ' ')
		{
			ft_putendl_fd("\x1b[31mError\ninvalid top border\033[0m", 2);
			return (1);
		}
		j++;
	}
	return (0);
}

static	int	check_down_side(t_data *dt, char **map)
{
	int	j;
	int	i;

	i = 0;
	j = dt->map_h - 1;
	while (map[j][i])
	{
		if (map[j][i] != '1' && map[j][i] != ' ')
		{
			ft_putendl_fd("\x1b[31mError\ninvalid bottom border\033[0m", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_borders(t_data *data)
{
	if (check_left_side(data->map) || check_right_side(data->map) \
		|| check_top_side(data->map) || check_down_side(data, data->map))
		return (1);
	return (0);
}
