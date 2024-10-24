/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:54:18 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/23 09:15:46 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	ft_valid_file(t_data *dt, char *p)
{
	int	i;

	i = ft_strlen(p);
	if (p[i - 1] != 'b' || p[i - 2] != 'u' \
		|| p[i - 3] != 'c' || p[i - 4] != '.')
	{
		free(dt->file_map);
		ft_putendl_fd("\x1b[31mInvalid file extantion\033[0m", 1);
		return (1);
	}
	return (0);
}

void print_message(const char *message, const char *color)
{
	printf("%s%s\033[0m\n", color, message);
}

int main(int ac, char **av)
{
    t_data	data;

	if (ac == 2)
	{
        ft_setparam(&data);
		(data.file_map) = ft_read_map(av[1]);
		if (ft_valid_file(&data, av[1]) || ft_disperse_map(&data))
			return (ft_free_exit(&data), 1);
		if (ft_check_map(&data, &data.pars))
			return (ft_free_exit(&data), 1);
		ft_putendl_fd("\x1b[33mLOADING WALL TEXTURES......\033[0m", 1);
		if (ft_init_texters(&data))
			return (ft_free_exit(&data), 1);
		init_data(&data);
		start_game(&data);
	}
	return 0;
}
