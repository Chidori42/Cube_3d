/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disperse_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:48:30 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/08/31 13:26:43 by ael-fagr         ###   ########.fr       */
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
    int len;
    char *tmp;

    len = ft_strlen(line);
    tmp = ft_strjoin(texters, line);
    texters = ft_strjoin(tmp, "\n");
    *file_map += len; 
    free(line);
    return (texters);
}

char    **ft_add_spaces(t_data *data, char **str)
{
    int size;
    int len;
    char **new_str;
    int i;
    int j;

    size = data->wid;
    new_str = malloc(sizeof(char **) * (data->hei + 1));
    i = 0;
    while (str[i] && i < data->hei)
    {
        new_str[i] = malloc(sizeof(char) * (size + 1));
        if (!new_str[i])
            return (NULL);
        j = 0;
        len = ft_strlen(str[i]);
        while (j < size)
        {
            if (j < len)
                new_str[i][j] = str[i][j];
            else
                new_str[i][j] = ' ';
            j++;
        }
        new_str[i][j] = '\0';
        i++;
    }
    new_str[i] = NULL;
    return (ft_free_2dm(str), new_str);
}

int get_map_data(t_data *data, char *colors, char *texters, char *map)
{
    data->texters = ft_split(texters, '\n');
    data->colors = ft_split(colors, '\n');
    data->map = ft_split(map, '\n');
    if (!data->texters || !data->colors || !data->map)
    {
        free(texters);
        free(colors);
        free(map);
        return (ft_putstr_fd("Error\ninvalid map", 2), 1);
    }
    set_hei_and_wid(data);
    data->map = ft_add_spaces(data, data->map);
    if (!data->map)
    {
        free(texters);
        free(colors);
        free(map);
        return (1);
    }
    free(texters);
    free(colors);
    free(map);
    return (0);
}

int ft_disperse_map(t_data *data, char *file_map)
{
    char *texters = NULL;
    char *colors = NULL;
    char *map = NULL;
    char *tmp;
    int i;

    i = 0;
    tmp = file_map;
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
    if (get_map_data(data, colors, texters, map))
        return (free(tmp), 1);
    return (free(tmp), 0);
}

