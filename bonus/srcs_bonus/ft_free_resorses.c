/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_resorses.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:13:34 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/11/02 17:41:29 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

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

void	ft_free_exit(t_data *data)
{
	if (data->texters)
		ft_free_2dm((data->texters));
	if (data->colors)
		ft_free_2dm((data->colors));
	if (data->map)
		ft_free_2dm((data->map));
	exit(0);
}
