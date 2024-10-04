/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_texters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 03:37:07 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/10/04 20:31:25 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

static int check_valid_path(char *str)
{
   int fd;

    fd = open(str, O_RDONLY);
    if (fd == -1)
        return (perror("Error opening file"), 1);
    close(fd);
    return (0);
}

static char *check_end_spaces(char *str)
{
    int i;

    i = ft_strlen(str) - 1;
    while (str && str[i] == ' ')
        i--;
    str[i + 1] = '\0';
    return (str);
}

char **ft_split_texter(char *str)
{
    int     i;
    char    **p;

    i = 0;
    p = malloc(3 * sizeof(char *));
    if (!p)
        return (NULL);
    while (*str == ' ')
        str++;
    while (str[i] && str[i] != ' ')
        i++;
    p[0] = ft_substr(str, 0, i);
    str += i;
    while (*str == ' ')
        str++;
    p[1] = check_end_spaces(ft_substr(str, 0, ft_strlen(str)));
    p[2] = NULL;
    return (p);
}

int ft_pars_texters(t_data *data, t_pars *args)
{
    int i;
    int j;
    char **p1;

    i = -1;
    while (data->texters && data->texters[++i])
    {
        j = 0;
        p1 = ft_split_texter(data->texters[i]);
        if (!p1)
            return (-2);
        if (ft_strncmp(p1[j], "NO", ft_strlen(p1[j])) == 0)
            args->no = ft_strdup(p1[1]);
        else if (ft_strncmp(p1[j], "SO", ft_strlen(p1[j])) == 0)
            args->so = ft_strdup(p1[1]);
        else if (ft_strncmp(p1[j], "WE", ft_strlen(p1[j])) == 0)
            args->we = ft_strdup(p1[1]);
        else if (ft_strncmp(p1[j], "EA", ft_strlen(p1[j])) == 0)
            args->ea = ft_strdup(p1[1]);
        else
            return (ft_putendl_fd("Error\ninvalid map11", 2), ft_free_2dm(p1), 1);
        if (p1[j + 1] && check_valid_path(p1[j + 1]))
            return (ft_free_2dm(p1), 1);
        ft_free_2dm(p1);
    }
    if (i != 4 || !args->no || !args->so || !args->we || !args->ea)
        return (ft_putendl_fd("Error\ninvalid map22", 2), 1);
    return (0);
}
