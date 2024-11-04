/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_texters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 03:37:07 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/28 14:59:51 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

static int	check_valid_path(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (perror("Error opening file"), 1);
	close(fd);
	return (0);
}

static char	*check_end_spaces(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (str && str[i] == ' ')
		i--;
	str[i + 1] = '\0';
	return (str);
}

char	**ft_split_texter(char *str)
{
	int		i;
	char	**p;

	i = 0;
	p = malloc(3 * sizeof(char *));
	if (!p)
		return (NULL);
	while (*str == ' ')
		str++;
	while (str[i] && str[i] != ' ')
		i++;
	p[0] = ft_substr(str, 0, i);
	str += i;
	while (*str == ' ')
		str++;
	p[1] = check_end_spaces(ft_substr(str, 0, ft_strlen(str)));
	p[2] = NULL;
	return (p);
}

static int	ft_check_set_path(t_pars *args, char *identify, char *path)
{
	if (ft_strncmp(identify, "NO", ft_strlen(identify)) == 0)
		args->no = ft_strdup(path);
	else if (ft_strncmp(identify, "SO", ft_strlen(identify)) == 0)
		args->so = ft_strdup(path);
	else if (ft_strncmp(identify, "WE", ft_strlen(identify)) == 0)
		args->we = ft_strdup(path);
	else if (ft_strncmp(identify, "EA", ft_strlen(identify)) == 0)
		args->ea = ft_strdup(path);
	else
		return (ft_putendl_fd("Error\ninvalid map", 2), 1);
	return (0);
}

int	ft_pars_texters(t_data *data, t_pars *args)
{
	int		i;
	int		j;
	char	**p;

	i = -1;
	while (data->texters && data->texters[++i])
	{
		j = 0;
		p = ft_split_texter(data->texters[i]);
		if (!p)
			return (-2);
		if (ft_check_set_path(args, p[j], p[1]))
			return (ft_free_2dm(p), 1);
		if (p[j + 1] && check_valid_path(p[j + 1]))
			return (ft_free_2dm(p), 1);
		ft_free_2dm(p);
	}
	if (i != 4 || !args->no || !args->so
		|| !args->we || !args->ea)
		return (ft_putendl_fd("Error\ninvalid Number of texts", 2), 1);
	return (0);
}
