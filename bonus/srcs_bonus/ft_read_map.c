/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:42:52 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/11/03 11:21:20 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

char	*ft_read_map(char *p)
{
	char	*line;
	char	*str;
	int		fd;

	str = NULL;
	fd = open(p, O_RDWR);
	if (fd == -1)
	{
		ft_putendl_fd("\x1b[31mError\nopning file\033[0m", 2);
		exit(1);
	}
	line = get_next_line(fd);
	if (!line)
	{
		ft_putendl_fd("\x1b[31mError\nempty file\033[0m", 2);
		exit(1);
	}
	while (line)
	{
		str = ft_strjoin(str, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (str);
}
