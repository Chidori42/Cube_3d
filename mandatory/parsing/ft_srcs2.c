/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srcs2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 00:48:55 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/11/03 15:09:37 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*ft_read_line(char *file_map)
{
	int		i;
	char	*line;

	i = 0;
	while (file_map[i] && file_map[i] != '\n')
		i++;
	line = ft_substr(file_map, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

static char	*add_spaces(char *str, int size)
{
	int		j;
	int		len;
	char	*new_str;

	new_str = malloc(sizeof(char) * (size + 1));
	if (!new_str)
		return (NULL);
	len = ft_strlen(str);
	j = 0;
	while (j < size)
	{
		if (j < len)
			new_str[j] = str[j];
		else
			new_str[j] = ' ';
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

char	**ft_add_spaces(t_data *data, char **str)
{
	int		i;
	int		size;
	char	**new_str;

	size = data->map_w;
	new_str = malloc(sizeof(char **) * (data->map_h + 1));
	if (!new_str)
		return (ft_free_2dm(str), NULL);
	i = 0;
	while (str[i] && i < data->map_h)
	{
		new_str[i] = add_spaces(str[i], size);
		if (!(new_str[i]))
			return (ft_free_2dm(str), NULL);
		i++;
	}
	new_str[i] = NULL;
	return (ft_free_2dm(str), new_str);
}

int	get_data(t_data *data, char *colors, char *texters, char *map)
{
	if (ft_get_map(data, map))
	{
		free(texters);
		free(colors);
		free(map);
		return (1);
	}
	data->texters = ft_split(texters, '\n');
	data->colors = ft_split(colors, '\n');
	if (!data->texters || !data->colors || !data->map)
	{
		free(texters);
		free(colors);
		free(map);
		return (ft_putstr_fd("Error\ninvalid file informations", 2), 1);
	}
	free(texters);
	free(colors);
	free(map);
	return (0);
}

int	ft_check_digit(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
	}
	if (i > 3)
		return (1);
	return (0);
}
