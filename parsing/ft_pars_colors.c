/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 02:57:49 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/31 13:28:42 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int ft_check_digit(char *str)
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
            if (ft_strcmp(p[i], "C") == 0 || ft_strcmp(p[i], "F") == 0)
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
                return (ft_putendl_fd("Error\ninvalid Number1", 2), 1);
        }
    }
    return (0);
}

char **ft_split_color(char *str)
{
    char **p;
    int i;
    int j;

    i = 0;
    p = malloc(sizeof(char *) * 3);
    while (str[i] && is_white_space(str[i]))
        i++;
    j = i;
    while (str[j] && !is_white_space(str[j]))
        j++;
    p[0] = ft_substr(str, i, j - i);
    while (str[j] && is_white_space(str[j]))
        j++;
    p[1] = ft_substr(str, j, ft_strlen(str) - j);
    p[2] = NULL;
    return (p);
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
            p = ft_split_color(str[i]);
            if (p && check_c_and_f(args, p))
                return (ft_free_2dm(p), 1);
            ft_free_2dm(p);
        }
        else
            if (ft_check_digit(str[i]) || ft_atoi(str[i]) < 0
                || ft_atoi(str[i]) > 255)
                    return (ft_putendl_fd("Error\ninvalid Number2", 2), 1);
    }
    if (i != 3)
        return (ft_putendl_fd("Error\ninvalid Number3", 2), 1);
    return (0);
}

int    ft_pars_colors(t_data *data, t_pars *args)
{
    int i;
    int j;
    char **p;

    i = -1;
    while (data->colors && data->colors[++i])
    {
        j = 0;
        if (check_valid_color(data->colors[i]))
            return (1);
        p = ft_split(data->colors[i], ',');
        if (!p)
            return (1);
        if (ft_check_colors(args, p) != 0)
            return (ft_free_2dm(p), 1);
        ft_free_2dm(p);
    }
    if (i != 2)
        return (ft_putstr_fd("Error\ninvalid number of colors", 2), 1);
    if (args->is_f != 1 || args->is_c != 1)
        return (ft_putstr_fd("Error\ninvalid color identify", 2), 1);
    return (0);
}
