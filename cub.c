/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:54:18 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/07/24 02:56:17 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static	int	ft_close(t_data *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	par;

	if (ac == 2)
	{
		par.mlx = mlx_init();
		if (!par.mlx)
			return (2);
		if (ft_diff_map(&par, ft_read_map(av[1])) == -1)
			return (1);
		set_hei_and_wid(&par);
		set_p(&par);
		if (ft_check_map(&par))
			return (2);
		par.win = mlx_new_window(par.mlx, par.wid * 50, par.hei * 50, "cub3D");
		if (!par.win)
			return (2);
		draw_map(&par);
		mlx_hook(par.win, 2, 1L << 0, &key_press, &par);
		mlx_hook(par.win, 17, 0L, &ft_close, &par);
		mlx_loop(par.mlx);
	}
}
