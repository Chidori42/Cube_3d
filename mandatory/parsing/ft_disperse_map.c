/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disperse_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:48:30 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/08 03:45:25 by ael-fagr         ###   ########.fr       */
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

    size = data->map_w + 1;
    new_str = malloc(sizeof(char **) * (data->map_h + 1));
    if (!new_str)
        return (ft_free_2dm(str), NULL);
    i = 0;
    while (str[i] && i < data->map_h)
    {
        new_str[i] = malloc(sizeof(char) * (size + 1));
        if (!new_str[i])
            return (ft_free_2dm(str), NULL);
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

int get_data(t_data *data, char *colors, char *texters, char *map)
{
    if (ft_get_map(data, map))
    {
        free(texters);
        free(colors);
        free(map);
        return (1);
    }
    data->texters = ft_split(texters, '\n');
    data->colors = ft_split(colors, '\n');
    if (!data->texters || !data->colors || !data->map)
    {
        free(texters);
        free(colors);
        free(map);
        return (ft_putstr_fd("Error\ninvalid file informations", 2), 1);
    }
    int i = 0;
    while (data->texters[i])
        printf("[%s]\n", data->texters[i++]);
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
        while (file_map[i] == ' ')
            i++;
        if ((!ft_strncmp(file_map + i, "NO", 2) || !ft_strncmp(file_map + i, "SO", 2)
            || !ft_strncmp(file_map + i, "WE", 2) || !ft_strncmp(file_map + i, "EA", 2)))
            texters = ft_join_line(&file_map, texters, ft_read_line(file_map + i));
        else if ((!ft_strncmp(file_map + i, "C", 1) || !ft_strncmp(file_map + i, "F", 1)))
            colors = ft_join_line(&file_map, colors, ft_read_line(file_map));
        else
        {
            map = ft_strjoin(map, file_map);
            break;
        }
        while (file_map[i] == '\n')
            i++;
        file_map += i;
        i = 0;
    }
    free(tmp);
    if (get_data(data, colors, texters, map))
        return (1);
    return (0);
}

