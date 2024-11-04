/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 08:13:11 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/11/03 08:20:30 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

mlx_texture_t	*ft_get_data(t_data *dt, char *path)
{
	mlx_texture_t	*img;

	img = mlx_load_png(path);
	if (!img)
		ft_exit(dt, "error\n");
	free(path);
	return (img);
}

int	ft_init_texters(t_data *data)
{
	data->pars.north = ft_get_data(data, data->pars.no);
	data->pars.south = ft_get_data(data, data->pars.so);
	data->pars.west = ft_get_data(data, data->pars.we);
	data->pars.east = ft_get_data(data, data->pars.ea);
	return (0);
}
