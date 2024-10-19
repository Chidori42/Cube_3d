/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disperse_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:48:30 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/19 03:19:33 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

static	char	*ft_join_line(char **file_map, char *texters, char *line)
{
	int		len;
	char	*tmp;

	len = ft_strlen(line);
	tmp = ft_strjoin(texters, line);
	texters = ft_strjoin(tmp, "\n");
	*file_map += len;
	free(line);
	return (texters);
}

static	bool	is_texture(const char *str)
{
	if (!strncmp(str, TEXTURE_NO, 2) || \
		!strncmp(str, TEXTURE_SO, 2) || \
		!strncmp(str, TEXTURE_WE, 2) || \
		!strncmp(str, TEXTURE_EA, 2))
		return (true);
	else
		return (false);
}

static	bool	is_color(const char *str)
{
	if (!strncmp(str, COLOR_C, 1) || \
		!strncmp(str, COLOR_F, 1))
		return (true);
	return (false);
}

static int	ft_check_content(t_data *dt, char **tex, char **colr, char **mp)
{
	if (is_texture((dt->file_map) + dt->index))
	{
		*tex = ft_join_line(&(dt->file_map), *tex, \
		ft_read_line((dt->file_map) + dt->index));
	}
	else if (is_color((dt->file_map) + dt->index))
	{
		*colr = ft_join_line(&(dt->file_map), *colr, \
		ft_read_line((dt->file_map) + dt->index));
	}
	else
	{
		*mp = ft_strjoin(*mp, (dt->file_map));
		return (1);
	}
	return (0);
}

int	ft_disperse_map(t_data *dt)
{
	char	*tmp;
	char	*map;
	char	*colors;
	char	*texters;

	map = NULL;
	colors = NULL;
	texters = NULL;
	tmp = (dt->file_map);
	(dt->index) = 0;
	while ((dt->file_map) && (dt->file_map)[dt->index])
	{
		(dt->index) = 0;
		while ((dt->file_map)[dt->index] == ' ' || (dt->file_map)[dt->index] == '\n')
			dt->index++;
		if (ft_check_content(dt, &texters, &colors, &map))
			break ;
		while ((dt->file_map)[dt->index] == '\n')
			dt->index++;
		(dt->file_map) += dt->index;
	}
	if (get_data(dt, colors, texters, map))
		return (free(tmp), 1);
	return (free(tmp), 0);
}
