/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_texters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 03:37:07 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/07/24 07:54:32 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int check_valid_path(char *str)
{
   int fd;

    fd = open(str, O_RDONLY);
    if (fd == -1)
        return (perror("Error opening file"), 1);
    close(fd);
    return (0);
}

int ft_pars_texters(t_data *args)
{
    int i;
    int j;
    char **p1;

    i = -1;
    while (args->texters && args->texters[++i])
    {
        j = 0;
        p1 = ft_split(args->texters[i], ' ');
        if (!p1)
            return (-2);
        if (ft_strncmp(p1[j], "NO", 2) == 0)
            args->no = ft_strdup(p1[1]);
        else if (ft_strncmp(p1[j], "SO", 2) == 0)
            args->so = ft_strdup(p1[1]);
        else if (ft_strncmp(p1[j], "WE", 2) == 0)
            args->we = ft_strdup(p1[1]);
        else if (ft_strncmp(p1[j], "EA", 2) == 0)
            args->ea = ft_strdup(p1[1]);
        else
            return (1);
        if (p1[j + 1] && check_valid_path(p1[j + 1]))
            return (1);
    }
    if (i != 4 || !args->no || !args->so || !args->we || !args->ea)
        return (printf("Error\ninvalid map\n"), 1);
    return (0);
}
