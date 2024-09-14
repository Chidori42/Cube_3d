/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:54:18 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/09/14 08:01:03 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static	void	ft_close(void *param)
{
	t_data *data;

	data = param;
	mlx_close_window(data->mlx);
	mlx_terminate(data->mlx);
	ft_free_exit(param);
	exit(0);
}

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
	t_data	data;
	t_pars	args;
	t_player player;
	t_params params;

	params.data = &data;
	params.pars = &args;
	params.player = &player;
	params.data->map = NULL;
	if (ac == 2)
	{
		ft_setparam(&params);
		if (ft_valid_file(av[1]) || ft_disperse_map(&data, ft_read_map(av[1])))
			return (ft_free_exit(&params), 1);
		if (ft_check_map(&data, &args))
			return (ft_free_exit(&params), 1);
		init_mlx(&data);
		if (ft_check_window_size(&data))
			return (ft_free_exit(&params), 1);
		init_player(&params);
		ft_init_texters(&params);
		draw_map(&params);
		mlx_loop_hook(data.mlx, key_press, &params);
		mlx_close_hook(data.mlx, ft_close, &data);
		mlx_loop(data.mlx);
	}
}
