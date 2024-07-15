/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:54:18 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/02/09 11:48:23 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	ft_close(t_data *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

void ft_dda_algo(t_data *args, int x1, int y1, int color)
{
	int dx, dy;

	dx = x1 - args->x;
	dy = y1 - args->y;

	int step;
	if (abs(dx) > abs(dy))
		step = abs(dx);
	else
		step = abs(dy);
	float x_inc = (float)dx / step;
	float y_inc = (float)dy / step;

	float x = args->x;
	float y = args->y;
	int i = -1;
	while (++i <= step)
	{
		if (args->map[(int)y][(int)x] == '1')
			break;
		mlx_pixel_put(args->mlx, args->win, x*50, y*50, color);
        x += x_inc; // increment in x at each step 
        y += y_inc; // increment in y at each step
    } 
}
void ft_draw_lines(t_data *args, int wid, int hei, int color)
{
	while (wid > 0)
	{
		ft_dda_algo(args, wid, hei, color);
		wid--;
	}
}

int	main(int ac, char **av)
{
	t_data	par;

	if (ac == 2)
	{
		if (ft_check_ber(av[1]) == 1)
			exit(1);
		par.mlx = mlx_init();
		if (!par.mlx)
			return (2);
		set_param(&par);
		par.map = read_map(av[1]);
		if (!par.map)
			return (free(par.map), ft_putstr_fd("Error\ninvalid map", 2), 2);
		if (check_map(&par) == 1)
			exit (1);
		par.win = mlx_new_window(par.mlx, par.wid * 50, par.hei * 50, "mashle");
		if (!par.win)
			return (2);
		draw_map(&par);
		set_p(&par);
		mlx_hook(par.win, 2, 1L << 0, &key_press, &par);
		mlx_hook(par.win, 17, 0L, &ft_close, &par);
		mlx_loop(par.mlx);
	}
}
