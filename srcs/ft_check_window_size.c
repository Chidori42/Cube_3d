/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_window_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:07:01 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/27 19:38:45 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int ft_check_window_size(t_data *data)
{
    int screen_width;
    int screen_height;

    mlx_get_monitor_size(0, &screen_width, &screen_height);
    if (((data->wid * 50) > screen_width)
        || ((data->hei * 50) > screen_height))
    {
        ft_putendl_fd("Error\nwindow size is too big", 2);
        return (1);
    }
    return (0);
}
