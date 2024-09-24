/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:55:03 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/09/24 21:07:45 by ael-fagr         ###   ########.fr       */
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
	if (mlx_image_to_window(param->data->mlx,  param->data->img, 0, 0) == -1)
        return (ft_putendl_fd("Error\nputting back image to window failed", 2), 1);
	init_player(param);
	ft_init_texters(param);
	ft_rander_map(param);
	draw_minimap(param);
	param->data->weapen_img = mlx_texture_to_image(param->data->mlx, param->data->weapen_txt[0]);
	mlx_image_to_window(param->data->mlx, param->data->weapen_img, 700, 700);
	return (0);
}