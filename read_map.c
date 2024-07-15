/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:42:52 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/02/09 11:44:51 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_hei_and_wid(t_data *arg)
{
	size_t	j;

	j = 0;
	arg->wid = ft_strlen(arg->map[j]);
	while (arg->map[j])
		j++;
	arg->hei = j;
	arg->retate_x = arg->hei;
	arg->retate_y = arg->wid;
}

static	void	check_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
		{
			ft_putstr_fd("Error\ninvalid map", 1);
			exit(1);
		}
		i++;
	}
}

char	**read_map(char *p)
{
	char	*line;
	char	**var;
	char	*str;
	int		fd;

	str = NULL;
	fd = open(p, O_RDWR);
	if (fd == -1)
		exit(1);
	line = get_next_line(fd);
	if (!line)
		exit(1);
	while (line)
	{
		str = ft_strjoin(str, line);
		free(line);
		line = get_next_line(fd);
	}
	check_empty_line(str);
	return (var = ft_split(str, '\n'), free(str), var);
}
