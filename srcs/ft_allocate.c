/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 23:40:36 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/18 22:47:37 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int ft_allocat_memory(void)
{
    t_params *params;
    t_data *data;
    t_pars *pars;
    t_camera *camera;

    params = malloc(sizeof(t_params));
    data = malloc(sizeof(t_data));
    pars = malloc(sizeof(t_pars));
    camera = malloc(sizeof(t_params));
    if (!params || !data || !pars || !camera)
        return (-1);
    params->data = data;
	params->pars = pars;
	params->camera = camera;
    return (0);
}