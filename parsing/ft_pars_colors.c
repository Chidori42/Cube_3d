/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 02:57:49 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/07/24 08:21:36 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int ft_check_digit(char *str)
{
    int i;

    i = -1;
    while (str[++i])
    {
        if (!ft_isdigit(str[i]))
            return (1);
    }
    return (0);
}

static int ft_check_color(char *str)
{
    int i;
    char **p;

    i = -1;
    printf("%s\n", str);
    p = ft_split(str, ',');
    if (!p)
        return (-2);
    while (p[++i])
    {
        if (ft_strlen(p[i]) > 3 || ft_strlen(p[i]) < 0)
            return (1);
        if (ft_check_digit(p[i]))
            return (1);
        if (ft_atoi(p[i]) < 0 || ft_atoi(p[i]) > 255)
            return (1);
    }
    return (0);
}

int t_check_color_idnt(char *str)
{
    char **p;

    p = ft_split(str, ' ');
    if (!p)
        return (-2);
    if (p[0] && ft_strncmp(p[0], "F", 1) &&
        ft_strncmp(p[0], "C", 1))
        return (ft_putstr_fd("Error\ninvalid identifier", 2), 1);
    
}

int    ft_pars_colors(t_data *args)
{
    int i;
    int j;
    char **p1;

    i = -1;
    j = 0;
    while (args->colors && args->colors[++i])
    {
        j = 0;
       p1 = ft_split(args->colors[i], ',');
       if (!p1)
            return (-2);
        if (p1[j + 1])
        {
            if (ft_check_color(p1[j + 1]) != 0)
                return (ft_putstr_fd("Error\ninvalid color", 2), 1);
        }
    }
    if (i != 2)
        return (ft_putstr_fd("Error\ninvalid number of colors", 2), 1);
    return (0);
}
