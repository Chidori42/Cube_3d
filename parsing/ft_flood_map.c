/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-29 20:47:20 by ael-fagr          #+#    #+#             */
/*   Updated: 2024-07-29 20:47:20 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static	char **copy_map(t_data *args)
{
	int	i;
	int	j;

	i = 0;
	args->cp_mp = (char **)malloc(sizeof(char *) * (args->hei + 1));
    if (!(args->cp_mp))
        return (NULL);
	while (args->map[i])
	{
		args->cp_mp[i] = (char *)malloc((args->wid + 1) * sizeof(char));
        if (!(args->cp_mp[i]))
            return (NULL);
		j = 0;
		while (args->map[i][j])
		{
			args->cp_mp[i][j] = args->map[i][j];
			j++;
		}
		args->cp_mp[i][j] = '\0';
		i++;
	}
	args->cp_mp[i] = NULL;
    return (args->cp_mp);
}

static	void flood_fill(t_data *args, int x, int y)
{
    if (args->cp_mp[y][x] == 32)
    {
        ft_putstr_fd("Error\ninvalid border", 2);
        exit(1);
    } 
	if (args->cp_mp[y][x] == '1')
		return ;
	else
	{
		args->cp_mp[y][x] = '1';
		flood_fill(args, x + 1, y);
		flood_fill(args, x - 1, y);
		flood_fill(args, x, y + 1);
		flood_fill(args, x, y - 1);
	}
}

size_t	check_flood(t_data *args)
{
	size_t	i;
	size_t	j;

	i = 0;
	copy_map(args);
    printf("x0 = %f, y0 = %f\n", args->x0, args->y0);
	flood_fill(args, (int)args->x0, (int)args->y0);
	while (args->cp_mp[i])
	{
		j = 0;
		while (args->cp_mp[i][j])
		{
			if (args->cp_mp[i][j] != '1' && args->cp_mp[i][j] != 32
				&& args->cp_mp[i][j] != '0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
