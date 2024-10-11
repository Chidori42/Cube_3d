/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:54:18 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/09 03:30:23 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

int ft_valid_file(char *p)
{
	int i;

	i = ft_strlen(p);
	if (p[i - 1] != 'b' || p[i - 2] != 'u' || p[i - 3] != 'c' || p[i - 4] != '.')
		return (ft_putendl_fd("Error\ninvalid file extantion", 2), 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data		data;

	if (ac == 2)
	{
		ft_setparam(&data);
		if (ft_valid_file(av[1]) || ft_disperse_map(&data, ft_read_map(av[1])))
			return (ft_free_exit(&data), 1);
		if (ft_check_map(&data, &data.pars))
			return (ft_free_exit(&data), 1);
		if (ft_init_weapen_images(&data))
			return (ft_free_exit(&data), 1);
		if (ft_init_texters(&data))
			return (ft_free_exit(&data), 1);
		if (ft_init_door_image(&data))
			return (ft_free_exit(&data), 1);
		init_data(&data);
    	start_game(&data);
	}
}
