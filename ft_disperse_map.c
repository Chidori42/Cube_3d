#include "cub.h"

static char    **ft_disperse_map(char *file_map, int *index)
{
    int     i;
    char    **tmp;
    char    *str;

    i = *index;
    if (!file_map)
        return (NULL);
    while (file_map[++i])
    {
        if (file_map[i] == '\n' && file_map[i + 1] == '\n')
            break ;
    }
    str = ft_substr(file_map, *index, i - (*index));
    tmp = ft_split(str, '\n');
    free(str);
    *index = i;
    return (tmp);
}

int ft_diff_map(t_data *args, char *file_map)
{
    int index;

    index = 0;
    if (file_map)
    {
        args->texters = ft_disperse_map(file_map, &index);
        args->colors = ft_disperse_map(file_map, &index);
        args->map = ft_disperse_map(file_map, &index);
        if (!args->map || !args->colors || !args->texters)
            return (-1);
    }
    free(file_map);
    return (0);
}
