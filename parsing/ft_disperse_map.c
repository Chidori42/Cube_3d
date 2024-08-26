/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disperse_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:48:30 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/26 15:51:06 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static char *ft_read_line(char *file_map)
{
    int i;
    char *line;

    i = 0;
    while (file_map[i] && file_map[i] != '\n')
        i++;
    line = ft_substr(file_map, 0, i);
    if (!line)
        return (NULL);
    return (line);
}

char *ft_join_line(char **file_map, char *texters, char *line)
{
    texters = ft_strjoin(texters, line);
    texters = ft_strjoin(texters, "\n");
    *file_map += ft_strlen(line); 
    free(line);
    return (texters);
}

int get_map_data(t_pars *args, char *colors, char *texters, char *map)
{
    args->texters = ft_split(texters, '\n');
    args->colors = ft_split(colors, '\n');
    args->map = ft_split(map, '\n');
    if (!args->texters || !args->colors || !args->map)
        return (ft_putstr_fd("Error\ninvalid map", 2), 1);
    free(texters);
    free(colors);
    free(map);
    return (0);
}

int ft_disperse_map(t_pars *args, char *file_map)
{
    char *texters = NULL;
    char *colors = NULL;
    char *map = NULL;
    int i;

    i = 0;
    while (file_map && file_map[i])
    {
        i = 0;
        while (is_white_space(file_map[i]))
            i++;
        if ((!ft_strncmp(file_map + i, "NO", 2) || !ft_strncmp(file_map + i, "SO", 2)
            || !ft_strncmp(file_map + i, "WE", 2) || !ft_strncmp(file_map + i, "EA", 2)))
            texters = ft_join_line(&file_map, texters, ft_read_line(file_map));
        else if ((!ft_strncmp(file_map + i, "C", 1) || !ft_strncmp(file_map + i, "F", 1)))
            colors = ft_join_line(&file_map, colors, ft_read_line(file_map));
        else
        {
            map = ft_strjoin(map, file_map);
            break;
        }
        file_map += i;
    }
    if (get_map_data(args, colors, texters, map))
        return (1);
    return (0);
}

