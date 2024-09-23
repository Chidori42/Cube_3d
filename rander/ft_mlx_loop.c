/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:55:03 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/09/22 16:34:03 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_close(void *param)
{
	t_data *data;

	data = param;
	mlx_close_window(data->mlx);
	mlx_terminate(data->mlx);
	exit(0);
}

int	ft_mlx_loop(t_params *param)
{
	init_player(param);
	ft_init_texters(param);
	// draw_minimap(param);
	return (0);
}