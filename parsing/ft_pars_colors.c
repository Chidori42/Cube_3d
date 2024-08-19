/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 02:57:49 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/19 03:20:23 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int ft_check_digit(char *str)
{
    int i;

    i = -1;
    while (str && str[++i])
    {
        if (!ft_isdigit(str[i]))
            return (1);
    }
    return (0);
}

static int check_valid_color(char *str)
{
    int i;

    i = 0;
    while (str && str[i])
    {
        if ((str[i] == ',' && str[i + 1] == ',')
            || (str[i] == ',' && str[i + 1] == '\0'))
            return (ft_putendl_fd("Error\ninvalid color identify", 2), 1);
        i++;
    }
    return (0);
}

static int check_c_and_f(t_pars *args, char **p)
{
    int i;

    i = -1;
    while (p && p[++i])
    {
        if (i == 0)
        {
            if (strcmp(p[i], "C") == 0 || strcmp(p[i], "F") == 0)
            {
                if (p[i][0] == 'C')
                    args->is_c++;
                else
                    args->is_f++;
            }
            else
                return (ft_putendl_fd("Error\ninvalid color identify", 2), 1);
        }
        else
        {
            if (ft_check_digit(p[i]) || ft_atoi(p[i]) < 0
                || ft_atoi(p[i]) > 255)
                return (ft_putendl_fd("Error\ninvalid Number", 2), 1);
        }
    }
    return (0);
}

static int ft_check_colors(t_pars *args, char **str)
{
    int i;
    char **p;

    i = -1;
    while (str[++i])
    {
        if (i == 0)
        {
            p = my_split(str[i]);
            if (p && check_c_and_f(args, p))
                return (1);
        }
        else
            if (ft_check_digit(str[i]))
                return (ft_putendl_fd("Error\ninvalid Number", 2), 1);
    }
    if (i != 3)
        return (ft_putendl_fd("Error\ninvalid Number", 2), 1);
    return (0);
}

int    ft_pars_colors(t_pars *args)
{
    int i;
    int j;
    char **p;

    i = -1;
    while (args->colors && args->colors[++i])
    {
        j = 0;
        if (check_valid_color(args->colors[i]))
            return (1);
        p = ft_split(args->colors[i], ',');
        if (!p)
            return (1);
        if (ft_check_colors(args, p) != 0)
            return (1);
    }
    if (i != 2)
        return (ft_putstr_fd("Error\ninvalid number of colors", 2), 1);
    if (args->is_f != 1 || args->is_c != 1)
        return (ft_putstr_fd("Error\ninvalid color identify", 2), 1);
    return (0);
}
