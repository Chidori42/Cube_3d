/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:54:18 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/11/03 15:15:09 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static int	ft_valid_file(t_data *dt, char *p)
{
	int	i;

	i = ft_strlen(p);
	if (p[i - 1] != 'b' || p[i - 2] != 'u' \
		|| p[i - 3] != 'c' || p[i - 4] != '.')
	{
		free(dt->file_map);
		ft_putendl_fd("\x1b[31mInvalid file extantion\033[0m", 2);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
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
		ft_putendl_fd("\x1b[32mLOADING WEAPON TEXTURES......\033[0m", 1);
		if (ft_init_weapen_images(&data))
			return (ft_free_exit(&data), 1);
		ft_putendl_fd("\x1b[34mLOADING DOOR TEXTURES......\033[0m", 1);
		if (ft_init_door_image(&data))
			return (ft_free_exit(&data), 1);
		ft_putendl_fd("\x1b[33mLOADING WALL TEXTURES......\033[0m", 1);
		if (ft_init_texters(&data))
			return (ft_exit(&data, "Error\ninit texters failed\n"), 1);
		(init_data(&data), start_game(&data));
	}
	else
		ft_putendl_fd("\x1b[31mError\nInvalid number arguments\033[0m", 1);
	return (0);
}
