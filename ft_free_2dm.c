#include "cub.h"

void	ft_free_2dm(char **arr)
{
    int	i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}