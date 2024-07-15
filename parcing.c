/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 02:11:35 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/02/09 12:03:06 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	size_t	check_border(t_data *arg)
{
	size_t	i;
	size_t	j;

	j = 0;
	arg->wid = ft_strlen(arg->map[j]);
	while (arg->map[j])
		j++;
	arg->hei = j;
	i = 0;
	while (arg->map[i])
	{
		if ((arg->map[i][0] != '1')
			|| arg->map[i][arg->wid - 1] != '1')
			return (1);
		j = 0;
		while (arg->map[i][j])
		{
			if (arg->map[0][j] != '1' || arg->map[arg->hei - 1][j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static	size_t	check_characters(t_data *arg)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (arg->map[i])
	{
		j = 0;
		while (arg->map[i][j])
		{
			if (arg->map[i][j] != '1' && arg->map[i][j] != '0' &&
				arg->map[i][j] != 'C' && arg->map[i][j] != 'E' &&
					arg->map[i][j] != 'P')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// static	size_t	check_p_and_e(t_data *arg)
// {
// 	size_t	i;
// 	size_t	j;
// 	int		n;
// 	int		m;

// 	i = 0;
// 	n = 0;
// 	m = 0;
// 	while (arg->map[i])
// 	{
// 		j = 0;
// 		while (arg->map[i][j])
// 		{
// 			if (arg->map[i][j] == 'E')
// 				n++;
// 			if (arg->map[i][j] == 'P')
// 				m++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (m != 1 || n != 1)
// 		return (1);
// 	return (0);
// }

static	size_t	check_linght(t_data *arg)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(arg->map[0]);
	j = 0;
	while (arg->map[j])
	{
		if (ft_strlen(arg->map[j]) != i)
			return (1);
		j++;
	}
	return (0);
}

int	check_map(t_data *arg)
{
	if (check_border(arg) == 1)
		return (ft_putstr_fd("Error\ncheck border", 1), 1);
	else if (check_characters(arg) == 1)
		return (ft_putstr_fd("Error\ninvalid character", 1), 1);
	else if (check_linght(arg) == 1)
		return (ft_putstr_fd("Error\ncheck lenght", 1), 1);
	else if (check_flood(arg) == 1)
		return (ft_putstr_fd("Error\ncheck flood", 1), 1);
	else
		return (0);
}
