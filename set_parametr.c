/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_parametr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:42:58 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/02/09 12:44:36 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_p(t_data *arg)
{
	int	i;
	int	j;

	j = 0;
	while (arg->map[j])
	{
		i = 0;
		while (arg->map[j][i])
		{
			if (arg->map[j][i] == 'P')
			{
				arg->x = i;
				arg->y = j;
			}
			else if (arg->map[j][i] == 'E')
			{
				arg->e_x_p = i;
				arg->e_y_p = j;
			}
			else if (arg->map[j][i] == 'C')
				arg->count_c++;
			i++;
		}
		j++;
	}
}

static void	check_imag_file(t_data *arg)
{
	if (!(arg->w) || !(arg->l) || !(arg->p_d) || !(arg->c)
		|| !(arg->e) || !(arg->enemy) || !(arg->e_o))
	{
		ft_putstr_fd("check image path", 1);
		exit (1);
	}
}

void	set_param(t_data *args)
{
	int	i;

	i = 50;
	args->move = 0;
	args->i = 0;
	args->j = 0;
	args->count_c = 0;
	args->w = mlx_xpm_file_to_image(args->mlx, "./textures/W.xpm", &i, &i);
	args->l = mlx_xpm_file_to_image(args->mlx, "./textures/L.xpm", &i, &i);
	args->p_d = mlx_xpm_file_to_image(args->mlx, "./textures/P_d.xpm", &i, &i);
	args->c = mlx_xpm_file_to_image(args->mlx, "./textures/C.xpm", &i, &i);
	args->e = mlx_xpm_file_to_image(args->mlx, "./textures/E.xpm", &i, &i);
	args->e_o = mlx_xpm_file_to_image(args->mlx, "./textures/E_O.xpm",
			&i, &i);
	args->enemy = mlx_xpm_file_to_image(args->mlx, "./textures/enmy.xpm",
			&i, &i);
	check_imag_file(args);
	args->cp_mp = NULL;
}
