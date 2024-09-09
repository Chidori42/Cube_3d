/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srcs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:07:16 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/09/09 12:04:10 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int ft_get_colore(int a, int b, int c)
{
    return (a << b << c);
}
void ft_set_colore(t_pars *args)
{
    printf("f: %d %d %d\n", args->f[0], args->f[1], args->f[2]);
    printf("c: %d %d %d\n", args->c[0], args->c[1], args->c[2]);
    args->floor_color = ft_get_colore(args->f[0], args->f[1], args->f[2]);
    args->ceiling_color = ft_get_colore(args->c[0], args->c[1], args->c[2]);
    printf("f: %d\n", args->floor_color);
    printf("c: %d\n", args->ceiling_color);
}

static int only_spaces(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!is_white_space(str[i]))
            return (0);
        i++;
    }
    return (1);
}

static int check_map_spaces(char **map)
{
    int i;
    int c;

    i = 0;
    c = 0;
    while (map[i])
    {
        if (only_spaces(map[i]))
            c++;
        i++;
    }
    if (c != 0)
        return (ft_putendl_fd("Error\ninvalid map", 2), 1);
    return (0);
}

int ft_get_map(t_data *data, char *map)
{
    int i;

    i = 0;
    if (!map)
        return (ft_putendl_fd("Error\nNO map in file", 2), 1);
    data->map = NULL;
    while (map && map[i])
    {
        if (map[i] == '\n' && map[i + 1] == '\n')
            return (ft_putendl_fd("Error\ninvalid map", 2), 1);
        i++;
    }
    data->map = ft_split(map, '\n');
    if (!data->map)
        return (ft_putendl_fd("Error\nmalloc fail", 2), 1);
    if (check_map_spaces(data->map))
        return (1);
    set_hei_and_wid(data);
    data->map = ft_add_spaces(data, data->map);
    if (!data->map)
        return (ft_putendl_fd("Error\nmalloc fail", 2), 1);
    return (0);
}

int ft_check_digit(char *str)
{
    int i;

    i = -1;
    while (str && str[++i])
    {
        if (!ft_isdigit(str[i]) && !is_white_space(str[i]))
            return (1);
    }
    return (0);
}
