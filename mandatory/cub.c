/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:54:18 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/18 05:37:00 by ael-fagr         ###   ########.fr       */
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
		return (ft_putendl_fd("Error\ninvalid file extantion", 2), 1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data		data;

	if (ac == 2)
	{
		ft_setparam(&data);
		(data.file_map) = ft_read_map(av[1]);
		if (ft_valid_file(&data, av[1]) || ft_disperse_map(&data))
			return (ft_free_exit(&data), 1);
		if (ft_check_map(&data, &data.pars))
			return (ft_free_exit(&data), 1);
		if (ft_init_texters(&data))
			return (ft_free_exit(&data), 1);
		init_data(&data);
		start_game(&data);
	}
}
