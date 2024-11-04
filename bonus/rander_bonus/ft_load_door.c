/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_door.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 01:37:46 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/11/03 14:09:06 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

static int	ft_load_door(t_data *dt)
{
	dt->door_txt = ft_get_data(dt, ft_strdup("textures/Door/DOOR1.PNG"));
	return (0);
}

int	ft_init_door_image(t_data *data)
{
	if (ft_load_door(data))
		return (1);
	return (0);
}
