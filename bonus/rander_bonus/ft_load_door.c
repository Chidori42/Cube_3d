/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doors_animistions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 01:37:46 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/19 21:45:31 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

static int	ft_load_door(t_data *dt)
{
	dt->door_txt = ft_get_data("textures/Door/door.png");
	if (!(dt->door_txt))
		return (ft_putendl_fd("load door_png fail!!", 2), 1);
	return (0);
}

int	ft_init_door_image(t_data *data)
{
	if (ft_load_door(data))
		return (1);
	return (0);
}
