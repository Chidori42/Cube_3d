/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:42:52 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/18 00:31:12 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static	void	check_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\0')
		{
			ft_putstr_fd("Error\ninvalid map", 2);
			exit(1);
		}
		i++;
	}
}

char	*ft_read_map(char *p)
{
	char	*line;
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
	return (str);
}
