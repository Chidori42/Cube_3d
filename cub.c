/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:54:18 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/24 12:22:13 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// static	void	ft_close(void *param)
// {
// 	t_data *data;

// 	data = param;
// 	mlx_close_window(data->mlx);
// 	mlx_terminate(data->mlx);
// 	exit(0);
// }

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
	if (ac == 2)
	{
		if (ft_valid_file(av[1]) || ft_disperse_map(&args, ft_read_map(av[1])) == -1)
			return (1); 
		ft_setparam(&params);
		if (ft_check_map(&data, &args))
			return (1);
		// init_mlx(&data);
		// draw_map(&params);
		// create_minimap(&params, 200);
		// mlx_loop_hook(data.mlx, key_press, &params);
		// mlx_close_hook(data.mlx, ft_close, &data);
		// mlx_loop(data.mlx);
	}
}
