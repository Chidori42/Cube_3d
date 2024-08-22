/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disperse_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:48:30 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/20 22:46:31 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static char    **ft_disperse_map(char *file_map, int *index)
{
    int     i;
    char    **tmp;
    char    *str;

    i = *index;
    if (!file_map || !file_map[i])
        return (NULL);
    while (file_map[++i])
    {
        if (file_map[i] == '\n' && file_map[i + 1] == '\n')
        {
            while(file_map[i] == '\n')
                i++;
            break ;
        }
    }
    str = ft_substr(file_map, *index, i - (*index));
    tmp = ft_split(str, '\n');
    free(str);
    *index = i;
    return (tmp);
}

static int ft_check_valid_mp(t_pars *args)
{
    int i;

    i = -1;
    while (args->map && args->map[++i])
    {
        if (args->map[i][0] == '\n' || args->map[i][0] == '\0')
            return (ft_putendl_fd("Error\ninvalid map", 2), 1);
    }
    return (0);
}

int ft_diff_map(t_pars *args, char *file_map)
{
    int index;
    static int count;

    count = 0;
    index = 0;
    if (file_map)
    {
        args->texters = ft_disperse_map(file_map, &index);
        args->colors = ft_disperse_map(file_map, &index);
        args->map = ft_disperse_map(file_map, &index);
        if (ft_disperse_map(file_map, &index))
        {
            free(file_map);
            return (ft_putendl_fd("Error\ninvalid map", 2), -1);
        }
        if (!args->map || !args->colors || !args->texters || ft_check_valid_mp(args))
        {
            free(file_map);
            return (ft_putendl_fd("Error\ninvalid map", 2), -1);
        }
    }
    free(file_map);
    return (0);
}
