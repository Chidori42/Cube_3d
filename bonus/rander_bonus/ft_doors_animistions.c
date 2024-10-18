/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doors_animistions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 01:37:46 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/18 13:42:50 by yakazdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

static int ft_load_door(t_data *dt)
{
	dt->door_txt = ft_get_data("textures/wall_texters/SAMPLE/DOOR_1C.PNG");
	if (!(dt->door_txt))
		return (ft_putendl_fd("load door_png fail!!", 2), 1);
    return (0);
}

int	ft_init_door_image(t_data *data)
{
	int i = 0;
	if (ft_load_door(data))
        return (1);
	return (0);
}
