/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:47:41 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/04 23:11:15 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

static int ft_check_borders(t_data *data)
{
    int i;
    int j;

    j = -1;
    while (data->map[0][++j])
        if (data->map[0][j] != '1' && data->map[0][j] != ' ')
            return (ft_putstr_fd("Error\ninvalid borders", 2), 1);
    j = -1;
    while (data->map[++j])
        if (data->map[j][ft_strlen(data->map[j]) - 1] != '1' &&
            data->map[j][ft_strlen(data->map[j]) - 1] != ' ')
            return (ft_putstr_fd("Error\ninvalid borders", 2), 1);
    i = -1;
    j = data->map_h - 1;
    while (data->map[j][++i])
        if (data->map[j][i] != '1' && data->map[j][i] != ' ')
            return (ft_putstr_fd("Error\ninvalid borders", 2), 1);
    i = -1;
    while (data->map[++i])
    {
        j = -1;
        while (data->map[i][++j] == ' ');
        if (data->map[i][j] != '1')
                return (ft_putstr_fd("Error\ninvalid borders", 2), 1);
    }
    return (0);
}

static int check_sides(t_data *data, int i, int j)
{
    if (ft_strchr("0NSWED", data->map[j][i]))
    {
        if ((j - 1  > 0 && data->map[j - 1][i] == ' ')
            || (j + 1 < data->map_h && data->map[j + 1][i] == ' ')
            || (i + 1 < (int)ft_strlen(data->map[j]) && data->map[j][i + 1] == ' ')
            || (i - 1 > 0 && data->map[j][i - 1] == ' '))
            return (ft_putstr_fd("Error\ninvalid map1", 2), 1);
    }
    return (0);
}

static int ft_check_valid_char(t_data *data)
{
    int i;
    int j;

    j = 0;
    while (data->map && data->map[j])
    {
        i = 0;
        while (data->map[j] && data->map[j][i])
        {
            if (check_sides(data, i, j))
                return (1);
            if (!ft_strchr(" 01DNSWE", data->map[j][i]))
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

static int ft_count_player(t_data *data)
{
    int i;
    int j;
    int count;

    j = 0;
    count = 0;
    while (data->map && data->map[j])
    {
        i = 0;
        while (data->map[j][i])
        {
            if (ft_strchr("NSWE", data->map[j][i]))
                count++;
            i++;
        }
        j++;
    }
    if (count != 1)
        return (ft_putstr_fd("Error\nInvalid number of player", 2), 1);
    return (0);
}

int check_door_sides(char **map)
{
    int i;
    int j;

    while (map[j])
    {
        i = 0;
        while (map[j][i])
        {
            if (map[j][i] == 'D')
            {
                if ((map[j][i + 1] == '1' && map[j][i - 1] == '1')
                    || (map[j + 1][i] == '1' && map[j - 1][i] == '1'))
                    return (0);
            }
            i++;
        }
        j++;
    }
    return (ft_putstr_fd("Error\ninvalid door position", 2), 1);
}

int ft_check_map(t_data *data, t_pars *args)
{
    if (ft_check_valid_char(data) || ft_count_player(data)
        || ft_check_borders(data) || check_door_sides(data->map)
        || ft_pars_colors(data, args) || ft_pars_texters(data, args))
        return (1);
    return (0);
}