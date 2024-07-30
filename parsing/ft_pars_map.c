/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-29 20:47:41 by ael-fagr          #+#    #+#             */
/*   Updated: 2024-07-29 20:47:41 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int ft_check_borders(t_data *args)
{
    int i;
    int j;

    j = -1;
    while (args->map[0][++j])
        if (args->map[0][j] != '1' && args->map[0][j] != 32)
            return (ft_putstr_fd("Error\ninvalid borders", 2), 1);
    j = -1;
    while (args->map[++j])
        if (args->map[j][ft_strlen(args->map[j]) - 1] != '1')
            return (ft_putstr_fd("Error\ninvalid borders", 2), 1);
    i = -1;
    j = args->hei - 1;
    while (args->map[j][++i])
        if (args->map[j][i] != '1' && args->map[j][i] != 32)
            return (ft_putstr_fd("Error\ninvalid borders", 2), 1);
    i = -1;
    while (args->map[++i])
    {
        j = -1;
        while (args->map[i][++j] == ' ');
        if (args->map[i][j] != '1')
                return (ft_putstr_fd("Error\ninvalid borders", 2), 1);
    }
    return (0);
}

static int ft_check_valid_char(t_data *args)
{
    int i;
    int j;

    j = 0;
    while (args->map && args->map[j])
    {
        i = 0;
        while (args->map[j][i])
        {
            if (args->map[j][i] != '1' && args->map[j][i] != '0' && args->map[j][i] != 'N'
                && args->map[j][i] != 'S' && args->map[j][i] != 'E' && args->map[j][i] != 'W'
                && args->map[j][i] != 32)
            {
                ft_putstr_fd("Error\ninvalid Character", 2);
                return (1);
            }
            i++;
        }
        j++;
    }
    return (0);
}

static int ft_count_player(t_data *args)
{
    int i;
    int j;
    int count;

    j = 0;
    count = 0;
    while (args->map[j])
    {
        i = 0;
        while (args->map[j][i])
        {
            if (args->map[j][i] == 'N' || args->map[j][i] == 'S'
                || args->map[j][i] == 'W' || args->map[j][i] == 'E')
                count++;
            i++;
        }
        j++;
    }
    if (count != 1)
        return (ft_putstr_fd("Error\ninvalid map", 2), 1);
    return (0);
}

int ft_check_map(t_data *args)
{
    if (ft_check_valid_char(args) || ft_count_player(args)
        || ft_check_borders(args) || check_flood(args)
        || ft_pars_colors(args) || ft_pars_texters(args))
        return (1);
    return (0);
}
