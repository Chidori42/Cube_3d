/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_resorses.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:48:41 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/20 21:48:04 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_free_2dm(char **arr)
{
    int	i;

    i = 0;
    while (arr && arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

void ft_free_exit(t_params *param)
{
    if (param->pars->no)
        free((param->pars->no));
    if (param->pars->so)
        free((param->pars->so));
    if (param->pars->we)
        free((param->pars->we));
    if (param->pars->ea)
        free((param->pars->ea));
    if (param->pars->texters)
        ft_free_2dm((param->pars->texters));
    if (param->pars->colors)
        ft_free_2dm((param->pars->colors));
    if (param->pars->map)
        ft_free_2dm((param->pars->map));
    exit(0);
}
 