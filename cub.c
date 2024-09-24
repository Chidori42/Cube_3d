/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:54:18 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/09/24 21:07:24 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	t_pars		args;
	t_texture	texture;
	t_menu		menu;
	t_player 	player;
	t_params 	params;

	params.data = &data;
	params.pars = &args;
	params.menu = &menu;
	params.player = &player;
	params.texture = &texture;

	if (ac == 2)
	{
		ft_setparam(&params);
		if (ft_valid_file(av[1]) || ft_disperse_map(&data, ft_read_map(av[1])))
			return (ft_free_exit(&params), 1);
		if (ft_check_map(&data, &args))
			return (ft_free_exit(&params), 1);
		data.mlx = mlx_init(data.win_width, data.win_hei, "cub3D", true);
		data.img = mlx_new_image(data.mlx, data.win_width, data.win_hei);
		if (ft_init_weapen_images(&data))
			return (1);
		// if (menu.check == 0)
		// 	ft_push_menu(&data, &menu);
		ft_mlx_loop(&params);
		mlx_loop_hook(data.mlx, weapen_hooks, &data);
		mlx_loop_hook(data.mlx, key_press, &params);
		mlx_close_hook(data.mlx, ft_close, &data);
		mlx_loop(data.mlx);
	}
}
