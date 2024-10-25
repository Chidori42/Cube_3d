/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_resorses.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakazdao <yakazdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:13:34 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/25 09:40:19 by yakazdao         ###   ########.fr       */
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

void ft_free_exit(t_data *data)
{
    if (data->texters)
        ft_free_2dm((data->texters));
    if (data->colors)
        ft_free_2dm((data->colors));
    if (data->map)
        ft_free_2dm((data->map));
    exit(1);
}
 